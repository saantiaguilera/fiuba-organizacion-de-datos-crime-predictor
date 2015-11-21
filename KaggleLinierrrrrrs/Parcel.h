#pragma once

#include "stdafx.h"
#include "Crime.h"
#include <map>

class Parcel {
private:
	std::map<std::string, int> crimesCountMap;
public:
	Parcel();
	~Parcel();
	std::vector<Crime*> crimes;
	void addCrime(Crime* crime);
	int getCrimesCategoryCount(std::string category);
};