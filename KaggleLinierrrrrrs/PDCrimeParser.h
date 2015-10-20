#pragma once
#include "stdafx.h"
#include "Crime.h"
#include "CrimeParserManager.h"

class PDCrimeParser
{
public:
	PDCrimeParser();
	~PDCrimeParser();
	bool PDCrimeParser::readFileWithManager(CrimeParserManager &crimeParserManager);
	 int numberTotalOfCrimes;
	 int workingDuty, offDuty;
	 int monday, tuesday, wednesday, thursday, friday, saturday, sunday;
private:
	Crime* createCrimeFromCSVChunk(const std::string & dataChunk);
};