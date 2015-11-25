#pragma once

#include "Parcel.h"
#include "DataManager.h"
#include "CrimeParser.h"

class CrimePredictor {
private:
	void getDataForCrime(Crime * currentCrime, Parcel * parcel, long double & maxDistance, std::map<std::string, int>& categoryTimesOcasionsMap, std::map<std::string, int>& categoryDutiesOcasionsMap);
	Crime * createCrimeFromCSVChunk(const std::string & dataChunk);
public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(DataManager *crimeParserManager);
};


