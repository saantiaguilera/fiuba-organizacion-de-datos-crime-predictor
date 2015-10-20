#pragma once

#include "stdafx.h"
#include "Crime.h"

class Parcel {
private:
	std::vector<Crime*> crimes;
public:
	Parcel();
	~Parcel();
	void addCrime(Crime* crime);
};