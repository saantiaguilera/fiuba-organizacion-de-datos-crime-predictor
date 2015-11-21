#pragma once

#include "stdafx.h"

class Crime {
private:
	
public:
	Crime();
	Crime(int dayTime, int workingDuty, std::string category, std::string address, double longitude, double latitude);
	~Crime();
	void printValues();
	//Fields: "date" "hour" "Category" "DayOfWeek" "Address" "X" "Y"
	std::string mCategory;
	std::string mAdress;
	int mDayTime, mWorkingDuty;
	double mLatitude;
	double mLongitude;
};