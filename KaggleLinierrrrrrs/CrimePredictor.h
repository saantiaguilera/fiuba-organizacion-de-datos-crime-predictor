#pragma once

#include "Parcel.h"
#include "DataManager.h"
#include "CrimeParser.h"

class CrimePredictor {
private:
	CategoryConstantsManage *categoryConstantsManager;
	void getDataForCrime(Crime * currentCrime, Parcel * parcel, long double & maxDistance);
	Crime * createCrimeFromCSVChunk(const std::string & dataChunk);
	std::map<std::string, double> CrimePredictor::getMostProbableCategory(Crime *crimeToPredict, Parcel *parcel);
public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(DataManager *crimeParserManager);
};


