#include "CommandParser.h"

CommandParser::CommandParser(string toParse) : toParse(toParse)
{
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
