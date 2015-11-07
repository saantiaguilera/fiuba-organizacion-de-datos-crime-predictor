#pragma once
#include "stdafx.h"
#include "Crime.h"
#include "CrimeParserManager.h"
#include <map>

class PDCrimeParser
{
public:
	PDCrimeParser();
	~PDCrimeParser();
	bool PDCrimeParser::readFileWithManager(CrimeParserManager* crimeParserManager);
	 int numberTotalOfCrimes;
	 void createFileWithDefinitionsForCategories();
private:
	Crime* createCrimeFromCSVChunk(const std::string & dataChunk);
	std::map<std::string, std::vector<double>> crimesHourFreq;
};