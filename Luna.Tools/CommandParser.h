#pragma once

#include <string>

using namespace std;

/**
 * @brief 
 * It parses the command arguments.
 * It only handles the format that gives '-' character in front of options.
*/
class CommandParser
{
private:
	string toParse;

public:
	CommandParser() = delete;
	CommandParser(string toParse);
	string getCommand();
	bool getFlag(string name);
	string* getArgs(string name);
	~CommandParser();
};