#include "stdafx.h"
#include "CrimeParserManager.h"

CrimeParserManager::CrimeParserManager()
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

CrimeParserManager::~CrimeParserManager()
{
	for (int i = 0; i < kSanFranciscoMatrixColNumber; i++)
	{
		for (int k = 0; k < kSanFranciscoMatrixRowNumber; k++)
		{
			delete matrix[k][i];
		}
	}
}

void CrimeParserManager::addCrimeToMatrix(Crime* crime)
{
	if (coordinateIsValidForCrime(crime)) {
		int colIndex = this->getColNumberForCrime(crime);
		int rowIndex = this->getRowNumberForCrime(crime);

		matrix[rowIndex][colIndex]->addCrime(crime);
	}
}

int CrimeParserManager::getColNumberForCrime(Crime *crime) {
	long double latitude = crime->mLatitude - kMinLatitude;
	long double cellHeigthLatitude = (kMaxLatitude - kMinLatitude) / kSanFranciscoMatrixRowNumber;
	int colIndex = (int)(latitude / cellHeigthLatitude);
	return colIndex;
}

int CrimeParserManager::getRowNumberForCrime(Crime *crime) {
	long double longitude = crime->mLongitude - kMinLongitude;
	long double cellWidthLongitude = (kMaxLongitude - kMinLongitude) / kSanFranciscoMatrixColNumber;
	int rowIndex = (int)(longitude / cellWidthLongitude);
	return rowIndex;
}

bool CrimeParserManager::coordinateIsValidForCrime(Crime* crime)
{
	if (crime->mLatitude <= kMaxLatitude && crime->mLatitude >= kMinLatitude && crime->mLongitude >= kMaxLongitude && crime->mLongitude <= kMinLongitude) {
		numberOfCrimesAddedToMatrix++;
		return true;
	}
	
	numberOfCrimesOutOfMatrix++;
	return false;
}

Parcel* CrimeParserManager::getParcelOfCrime(Crime *crime) {
	int colNumber = this->getColNumberForCrime(crime);
	int rowNumber = this->getRowNumberForCrime(crime);

	return this->matrix[rowNumber][colNumber];
}