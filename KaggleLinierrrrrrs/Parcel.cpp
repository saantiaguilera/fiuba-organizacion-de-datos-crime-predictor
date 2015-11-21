#include "stdafx.h"
#include "Parcel.h"

Parcel::Parcel(){
}

Parcel::~Parcel()
{
	for (Crime* crime : crimes)
		delete crime;
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
	crimes.push_back(crime);
}

int Parcel::getCrimesCategoryCount(std::string category)
{
	int number = crimesCountMap[category];
	return number;
}