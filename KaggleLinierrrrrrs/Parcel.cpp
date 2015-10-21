#include "stdafx.h"
#include "Parcel.h"

Parcel::Parcel(){
}

Parcel::~Parcel()
{
	for (int i = 0; i < crimes.size(); i++)
	{
		delete crimes[i];
	}
}

void Parcel::addCrime(Crime* crime)
{
	crimes.push_back(crime);
}