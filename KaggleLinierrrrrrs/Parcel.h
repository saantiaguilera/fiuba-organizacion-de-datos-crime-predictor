#pragma once

#include "stdafx.h"
#include "Crime.h"
#include <map>

class Parcel {
public:
	Parcel();
	~Parcel();
	std::vector<Crime*> crimes;
	void addCrime(Crime* crime);
};