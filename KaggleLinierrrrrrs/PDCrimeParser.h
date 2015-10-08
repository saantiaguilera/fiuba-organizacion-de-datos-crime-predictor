#pragma once
#include "stdafx.h"
#include "Crime.h"

class PDCrimeParser
{
public:
	PDCrimeParser();
	~PDCrimeParser();
	bool readFile();
private:
	Crime* createCrimeFromCSVChunk(const std::string & dataChunk);
};