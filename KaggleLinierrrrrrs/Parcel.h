#pragma once

#include "stdafx.h"
#include "Crime.h"
#include <map>

class Parcel {
private:
	std::vector<Crime*> crimes;
public:
	Parcel();
	~Parcel();
	void addCrime(Crime* crime);
	void getCrimesCategoryCount();
	std::string getMostFreqCategoryCrime();
	std::map<std::string, int> crimesCountMap;
};