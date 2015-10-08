#pragma once
#include "stdafx.h"
#include "Crime.h"
#include "CrimeParserManager.h"

class PDCrimeParser
{
public:
	PDCrimeParser();
	~PDCrimeParser();
	bool PDCrimeParser::readFileWithManager(CrimeParserManager crimeParserManager);
private:
	Crime* createCrimeFromCSVChunk(const std::string & dataChunk);
};