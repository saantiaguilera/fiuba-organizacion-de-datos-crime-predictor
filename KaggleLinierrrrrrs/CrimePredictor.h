#pragma once

#include "Parcel.h"
#include "DataManager.h"
#include "CrimeParser.h"

class CrimePredictor {
private:
	CategoryConstantsManage *categoryConstantsManager;
	Crime * createCrimeFromCSVChunk(const std::string & dataChunk);
public:
	CrimePredictor();
	~CrimePredictor();
	void CrimePredictor::predictCrime(DataManager *crimeParserManager);
};


