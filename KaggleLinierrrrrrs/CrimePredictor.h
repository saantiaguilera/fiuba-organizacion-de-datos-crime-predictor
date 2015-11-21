#pragma once

#include "stdafx.h"
#include <map>
#include "Parcel.h"
#include "DataManager.h"
#include "CrimeParser.h"

class CrimePredictor {
private:
	void getDataForCrime(Crime * currentCrime, Parcel * parcel, long double & maxDistance, std::map<std::string, int>& categoryTimesOcasionsMap, std::map<std::string, int>& categoryDutiesOcasionsMap);
public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(DataManager *crimeParserManager);
	DataManager *crimeParserManager;
	CrimeParser *crimeParser;
};


