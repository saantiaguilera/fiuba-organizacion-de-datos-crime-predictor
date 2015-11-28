#include "stdafx.h"
#include "Parcel.h"

Parcel::Parcel() {
	totalCrimes = 0;
}

Parcel::~Parcel()
{
	/*	for (Crime* crime : crimes)
	delete crime;*/
}

void Parcel::addCrime(Crime* crime)
{
	if (crimesCountMap.find(crime->mCategory) == crimesCountMap.end())
	{
		crimesCountMap[crime->mCategory] = 1;
	}
	else
	{
		crimesCountMap[crime->mCategory]++;
	}
	++totalCrimes;

	//Remove this line and uncomment whats commented in here and the .h if you want to use again vector. Error was thrown in predicting crime #664733
	//Because the vector exceeded its available size (we should use list instead of vector). But since its slower and we are not using it for anything in this branch, i removed it

	delete crime;
	//	crimes.push_back(crime);
}

long Parcel::getCrimesCategoryCount(std::string category)
{
	long number = crimesCountMap[category];
	return number;
}