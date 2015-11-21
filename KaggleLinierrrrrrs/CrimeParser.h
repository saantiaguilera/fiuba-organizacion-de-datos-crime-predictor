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
	Crime* createCrimeFromCSVChunk(const std::string & dataChunk);
};