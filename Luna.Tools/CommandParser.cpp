#include "CommandParser.h"
#include <algorithm>

CommandParser::CommandParser(string toParse) : toParse(toParse)
{
	for (string::iterator iter = toParse.begin(); iter != toParse.end(); iter++)
	{
		switch (*iter)
		{
		case delimeter:
			break;
		case optionSpecifier:
			break;
		default:
			break;
		}
	}
}

string CommandParser::getCommand()
{
	return this->command;
}

bool CommandParser::getFlag(string name)
{
	set<string>::iterator iter = this->flagsMap.find(name);
	if (iter != this->flagsMap.end())
	{
		return true;
	}
	return false;
}

vector<string> CommandParser::getArgs(string name)
{
	map<string, vector<string>>::iterator iter = this->optionsMap.find(name);
	if (iter != this->optionsMap.end())
	{
		return iter->second;
	}
	return vector<string>();
}

CommandParser::~CommandParser()
{

}
