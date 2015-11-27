#pragma once
#include "stdafx.h"
#include "Crime.h"
#include "DataManager.h"
#include <map>

class CrimeParser
{
public:
	CrimeParser();
	~CrimeParser();
	bool CrimeParser::readFileWithManager(DataManager* crimeParserManager);
	void createFileWithDefinitionsForCategories();
	Crime* createCrimeFromCSVChunk(const std::string & dataChunk);
	//
	std::map<std::string, std::vector<float>> crimesDayFreq;
	//
private:
	std::map<std::string, std::vector<double>> crimesHourFreq;
};