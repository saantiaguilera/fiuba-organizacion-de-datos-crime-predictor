#pragma once

#include "stdafx.h"
#include "Crime.h"
#include "Parcel.h"

class CrimeParserManager {
private:
	Parcel matrix[kSanFranciscoMatrixRowNumber][kSanFranciscoMatrixColNumber];
public:
	CrimeParserManager();
	~CrimeParserManager();
	void addCrimeToMatrix(Crime crime);
};
