#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>

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
	string command;
	set<string> flagsMap;
	map<string, vector<string>> optionsMap;

	static const char delimeter = ' ';
	static const char optionSpecifier = '-';

public:
	CommandParser() = delete;
	CommandParser(string toParse);
	string getCommand();
	bool getFlag(string name);
	vector<string> getArgs(string name);
	~CommandParser();
};