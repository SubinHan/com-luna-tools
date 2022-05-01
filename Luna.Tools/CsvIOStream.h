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
	wifstream* file;

private:

public:
	CsvReader(string path);
	wstring readNext();
	~CsvReader();

};