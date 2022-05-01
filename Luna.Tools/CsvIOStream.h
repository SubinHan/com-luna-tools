#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

class CsvReader
{
private:
	static const long long BUFFER_SIZE = 128;

	wifstream* file;
	wstringstream* out;
	wchar_t* buffer;
	wstring rest;
	queue<wstring>* values;
	bool inQuote;
	bool quoted;
	int fileLength;

private:
	void extractValues(queue<wstring>* values, wstring target, wstring& rest);

public:
	CsvReader(string path);
	wstring readNext();
	wstring readNext2();
	~CsvReader();


};