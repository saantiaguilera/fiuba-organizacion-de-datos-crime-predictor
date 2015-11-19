#pragma once

#include "stdafx.h"
#include "Crime.h"
#include "Parcel.h"

class CrimeParserManager {
private:
	int CrimeParserManager::getColNumberForCrime(Crime *crime);
	int CrimeParserManager::getRowNumberForCrime(Crime *crime);
	bool coordinateIsValidForCrime(Crime* crime);
public:
	CrimeParserManager();
	~CrimeParserManager();
	void addCrimeToMatrix(Crime* crime);
	 int numberOfCrimesAddedToMatrix;
	 int numberOfCrimesOutOfMatrix;
	 Parcel* matrix[kSanFranciscoMatrixRowNumber][kSanFranciscoMatrixColNumber];
	 Parcel* CrimeParserManager::getParcelOfCrime(Crime *crime);
};
