#pragma once

#include "stdafx.h"
#include <map>
#include "Parcel.h"
#include "CrimeParserManager.h"
#include "PDCrimeParser.h"

class CrimePredictor {
private:

public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(CrimeParserManager *crimeParserManager);
	CrimeParserManager *crimeParserManager;
	PDCrimeParser *crimeParser;
};