#include "stdafx.h"
#include "CrimeParser.h"

DataManager::DataManager()
{
	//Both vars for testing purpose only,  remove when done.
	numberOfCrimesAddedToMatrix = 0;
	numberOfCrimesOutOfMatrix = 0;
	for (int i = 0; i < kSanFranciscoMatrixColNumber; i++)
	{
		for (int k = 0; k < kSanFranciscoMatrixRowNumber; k++)
		{
			matrix[k][i] = new Parcel;
		}
	}
}

DataManager::~DataManager()
{
	for (int i = 0; i < kSanFranciscoMatrixColNumber; i++)
	{
		for (int k = 0; k < kSanFranciscoMatrixRowNumber; k++)
		{
			delete matrix[k][i];
		}
	}
}

void DataManager::addCrimeToMatrix(Crime* crime)
{
	if (coordinateIsValidForCrime(crime)) {
		int colIndex = this->getColNumberForCrime(crime);
		int rowIndex = this->getRowNumberForCrime(crime);

		matrix[rowIndex][colIndex]->addCrime(crime);
	}
}

int DataManager::getColNumberForCrime(Crime *crime) {
	long double latitude = crime->mLatitude - kMinLatitude;
	long double cellHeigthLatitude = (kMaxLatitude - kMinLatitude) / kSanFranciscoMatrixRowNumber;
	int colIndex = (int)(latitude / cellHeigthLatitude);
	return colIndex;
}

int DataManager::getRowNumberForCrime(Crime *crime) {
	long double longitude = crime->mLongitude - kMinLongitude;
	long double cellWidthLongitude = (kMaxLongitude - kMinLongitude) / kSanFranciscoMatrixColNumber;
	int rowIndex = (int)(longitude / cellWidthLongitude);
	return rowIndex;
}

bool DataManager::coordinateIsValidForCrime(Crime* crime)
{
	if (crime->mLatitude <= kMaxLatitude && crime->mLatitude >= kMinLatitude && crime->mLongitude >= kMaxLongitude && crime->mLongitude <= kMinLongitude) {
		numberOfCrimesAddedToMatrix++;
		return true;
	}
	
	numberOfCrimesOutOfMatrix++;
	return false;
}

Parcel* DataManager::getParcelOfCrime(Crime *crime) {
	int colNumber = this->getColNumberForCrime(crime);
	int rowNumber = this->getRowNumberForCrime(crime);

	return this->matrix[rowNumber][colNumber];
}