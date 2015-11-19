#pragma once

#include "stdafx.h"
#include <map>
#include "Parcel.h"
#include "DataManager.h"
#include "CrimeParser.h"

class CrimePredictor {
private:
	std::vector<float> crimeFreqs;
	std::string CrimePredictor::crimesFrequenciesForParcel(Crime *crime, Parcel *parcel);
	std::string getCrimeCategoryPrediction(Crime * crime, Parcel * parcel);
public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(DataManager *crimeParserManager);
	DataManager *crimeParserManager;
	CrimeParser *crimeParser;
};