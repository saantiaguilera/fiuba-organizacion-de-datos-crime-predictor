#include "stdafx.h"
#include "CrimeParserManager.h"

CrimeParserManager::CrimeParserManager()
{
	std::vector<std::vector<Parcel>> matrix(kSanFranciscoMatrixRowNumber, std::vector<Parcel>(kSanFranciscoMatrixColNumber));
}

CrimeParserManager::~CrimeParserManager()
{
	
}

void CrimeParserManager::addCrimeToMatrix(Crime crime)
{
	long double latitude = crime.mLatitude - kMinLatitude;
	long double cellHeigthLatitude = (kMaxLatitude - kMinLatitude) / kSanFranciscoMatrixRowNumber;
	int colIndex = (int) (latitude / cellHeigthLatitude);
	
	long double longitude = crime.mLongitude - kMinLongitude;
	long double cellWidthLongitude = (kMaxLongitude - kMinLongitude) / kSanFranciscoMatrixColNumber;
	int rowIndex = (int)(longitude / cellWidthLongitude);

	matrix[rowIndex][colIndex].addCrime(crime);
}