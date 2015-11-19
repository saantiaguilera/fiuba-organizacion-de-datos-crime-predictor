#pragma once

#include "stdafx.h"
#include <map>
#include "Parcel.h"
#include "DataManager.h"
#include "CrimeParser.h"

class CrimePredictor {
private:

public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(DataManager *crimeParserManager);
	DataManager *crimeParserManager;
	CrimeParser *crimeParser;
};