#include "CommandParser.h"

CommandParser::CommandParser(string toParse)
{

}

string CommandParser::getCommand()
{
	return string();
}

bool CommandParser::getFlag(string name)
{
	return false;
}

string* CommandParser::getArgs(string name)
{
	return nullptr;
}

CommandParser::~CommandParser()
{

}
