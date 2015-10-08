#pragma once
#include "Crime.h"

class Parser
{
public:
	Parser();
	~Parser();
	bool readFile();

private:
	std::vector<std::string> splitStringMatchingARegex(const std::string & s, std::string rgx_str = "\\s+");
	void printVectorValues(std::vector<std::string> valuesVector);
	std::vector<Crime> crimes;
};

