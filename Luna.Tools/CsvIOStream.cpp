#include "CsvIOStream.h"



CsvReader::CsvReader(string path)
{
	std::locale::global(std::locale("Korean"));
	file = new wifstream();
	values = new queue<wstring>();
	buffer = new wchar_t[BUFFER_SIZE+1];
	inQuote = false;
	quoted = false;
	file->open(path);

	if (!file)
	{
		throw std::exception("File not found");
	}

	file->seekg(0, file->end);
	fileLength = file->tellg();
	file->seekg(0, file->beg);
}

void CsvReader::extractValues(queue<wstring>* values, wstring target, wstring& rest)
{
	size_t startIndex = 0;
	size_t endIndex = 0;
	for (wstring::iterator iter = target.begin(); iter != target.end(); iter++)
	{
		switch (*iter)
		{
		case '\"':
			inQuote = !inQuote;
			if (inQuote)
			{
				startIndex = iter - target.begin() + 1;
			}
			else
			{
				quoted = true;
			}
			break;
		case ',':
		{
			if (inQuote)
				break;
			endIndex = iter - target.begin();
			int offset = 0;
			if (quoted)
			{
				offset = 1;
				quoted = false;
			}
			values->push(target.substr(startIndex, endIndex - startIndex - offset));
			startIndex = endIndex + 1;
			break;
		}
		default:
			break;
		}
	}

	if (quoted)
		inQuote = true;
	if (startIndex < target.size())
	{
		rest = target.substr(startIndex, target.size() - startIndex );
	}
	else
	{
		rest.erase();
	}
}

wstring CsvReader::readNext()
{
	while (values->empty())
	{
		bool isEnd = file->tellg() > fileLength - BUFFER_SIZE;
		file->read(buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = L'\0';
		wstring a(buffer);
		if (isEnd)
		{
			a.resize(fileLength % BUFFER_SIZE);
			a += LR"(,)"s;
		}
		rest += a;
		extractValues(values, rest, rest);
	}

	wstring result = values->front();
	values->pop();
	return result;
}

wstring CsvReader::readNext2()
{
	wostringstream builder;

	while (file->good()) 
	{
		wchar_t c = file->get();
		switch (c)
		{
		case '\"':
			inQuote = !inQuote;
			if (inQuote)
			{
				builder.str(LR"()"s);
			}
			break;
		case ',':
		{
			if (inQuote)
				break;
			return builder.str();
			break;
		}
		case 65535:
			break;
		default:
			builder << c;
			break;
		}
	}

	return builder.str();
}

CsvReader::~CsvReader()
{
	delete file;
	delete values;
	delete buffer;
}