#pragma once

#include "stdafx.h"

class Crime {
private:
	
public:
	Crime();
	Crime(DayTime dayTime, WorkingDuty workingDuty, std::string category, Address address, double longitude, double latitude);
	Crime(std::string id, DayTime dayTime, WorkingDuty workingDuty, Address address, double longitude, double latitude);
	~Crime();
	void printValues();
	//Fields: "date" "hour" "Category" "DayOfWeek" "Address" "X" "Y"
	std::string mCategory, mId;
	DayTime mDayTime;
	WorkingDuty mWorkingDuty;
	Address mAddress;
	double mLatitude, mLongitude;
};