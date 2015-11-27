#pragma once

#include "stdafx.h"
#include "Crime.h"
#include <map>

class Parcel {
public:
	std::map<std::string, int> crimesCountMap;
	Parcel();
	~Parcel();
	std::vector<Crime*> crimes;
	void addCrime(Crime* crime);
	int getCrimesCategoryCount(std::string category);
};