#pragma once

#include "stdafx.h"
#include "Crime.h"
#include "Parcel.h"

class DataManager {
private:
	int DataManager::getColNumberForCrime(Crime *crime);
	int DataManager::getRowNumberForCrime(Crime *crime);
	bool coordinateIsValidForCrime(Crime* crime);
public:
	DataManager();
	~DataManager();
	void addCrimeToMatrix(Crime* crime);
	 int numberOfCrimesAddedToMatrix;
	 int numberOfCrimesOutOfMatrix;
	 Parcel* matrix[kSanFranciscoMatrixRowNumber][kSanFranciscoMatrixColNumber];
	 Parcel* DataManager::getParcelOfCrime(Crime *crime);
};
