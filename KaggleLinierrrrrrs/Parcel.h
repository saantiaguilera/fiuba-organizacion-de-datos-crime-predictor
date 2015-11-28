#pragma once

#include "stdafx.h"
#include "Crime.h"
#include <map>

class Parcel {
public:
	std::map<std::string, long> crimesCountMap;
	Parcel();
	~Parcel();
	//std::vector<Crime*> crimes;
	long totalCrimes;
	void addCrime(Crime* crime);
	long getCrimesCategoryCount(std::string category);
};