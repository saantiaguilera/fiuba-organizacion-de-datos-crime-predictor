#include "stdafx.h"
#include "Parcel.h"

Parcel::Parcel()
{

}

Parcel::~Parcel()
{

}

void Parcel::addCrime(Crime crime)
{
	crimes.push_back(crime);
}