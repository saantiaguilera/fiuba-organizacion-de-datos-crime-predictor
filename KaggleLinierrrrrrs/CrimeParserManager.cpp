#include "stdafx.h"
#include "CrimeParserManager.h"

CrimeParserManager::CrimeParserManager()
{
	std::vector<std::vector<Parcel*>> matrix(kSanFranciscoMatrixRowNumber, std::vector<Parcel*>(kSanFranciscoMatrixColNumber));
	//Both vars for testing purpose only,  remove when done.
	numberOfCrimesAddedToMatrix = 0;
	numberOfCrimesOutOfMatrix = 0;
}

CrimeParserManager::~CrimeParserManager()
{

}

void CrimeParserManager::addCrimeToMatrix(Crime* crime)
{
	if (coordinateIsValidForCrime(crime)) {
		long double latitude = crime->mLatitude - kMinLatitude;
		long double cellHeigthLatitude = (kMaxLatitude - kMinLatitude) / kSanFranciscoMatrixRowNumber;
		int colIndex = (int)(latitude / cellHeigthLatitude);

		long double longitude = crime->mLongitude - kMinLongitude;
		long double cellWidthLongitude = (kMaxLongitude - kMinLongitude) / kSanFranciscoMatrixColNumber;
		int rowIndex = (int)(longitude / cellWidthLongitude);

		matrix[rowIndex][colIndex]->addCrime(crime);
	}
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