#pragma once

#include "stdafx.h"
#include <map>
#include "Parcel.h"
#include "CrimeParserManager.h"
#include "PDCrimeParser.h"

class CrimePredictor {
private:
	std::vector<float> crimeFreqs;
	void CrimePredictor::crimesFrequenciesForParcel(Parcel *parcel);
	std::string getCrimeCategoryPrediction(Crime * crime, Parcel * parcel);
public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(CrimeParserManager *crimeParserManager);
	CrimeParserManager *crimeParserManager;
	PDCrimeParser *crimeParser;
};