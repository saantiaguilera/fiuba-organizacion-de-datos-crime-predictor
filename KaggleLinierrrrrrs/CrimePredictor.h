#pragma once

#include "stdafx.h"
#include <map>
#include "Parcel.h"
#include "DataManager.h"
#include "CrimeParser.h"

class CrimePredictor {
private:
	void getDataForCrime(Crime * currentCrime, Parcel * parcel, long double & maxDistance, std::map<std::string, int>& categoryTimesOcasionsMap, std::map<std::string, int>& categoryDutiesOcasionsMap);
	Crime * createCrimeFromCSVChunk(const std::string & dataChunk);
	void dumpData(std::ofstream & data, std::string id, std::map<std::string, long double>& pointsMap, long double totalPoitns);
public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(DataManager *crimeParserManager);
};


