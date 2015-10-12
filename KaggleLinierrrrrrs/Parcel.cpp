#include "stdafx.h"
#include "Parcel.h"

Parcel::Parcel()
{
	std::vector<Crime> crimes;
}

Parcel::~Parcel()
{

}

void Parcel::addCrime(Crime crime)
{
	crimes.push_back(crime);
}