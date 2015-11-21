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
	crimes.push_back(crime);
}