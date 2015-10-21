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

void Parcel::getCrimesCategoryCount()
{
	for (std::map<std::string, int>::iterator it = crimesCountMap.begin(); it != crimesCountMap.end(); ++it) {
		std::cout << it->first << " " << it->second << "\n";
	}
}