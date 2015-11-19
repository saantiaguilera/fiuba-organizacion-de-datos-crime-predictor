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

std::string Parcel::getMostFreqCategoryCrime() {
	int maxFreq = -1;
	std::string maxFreqCategory;

	for (std::map<std::string, int>::iterator it = crimesCountMap.begin(); it != crimesCountMap.end(); ++it) {
		if (it->second > maxFreq)
		{
			maxFreq = it->second;
			maxFreqCategory = it->first;
		}
	}
	return maxFreqCategory;
}

long int Parcel::amountOfCrimes() {
	return sizeof(crimes);
}