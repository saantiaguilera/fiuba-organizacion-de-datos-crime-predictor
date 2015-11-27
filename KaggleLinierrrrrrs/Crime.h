#pragma once

#include "stdafx.h"

class Crime {
private:
	
public:
	Crime();
	//Crime(DayTime dayTime, WorkingDuty workingDuty, std::string category, std::string address, double longitude, double latitude);
	//Crime(std::string id, DayTime dayTime, WorkingDuty workingDuty, std::string address, double longitude, double latitude);

	Crime::Crime(std::string id, int hour, DayOfWeek dayOfWeek,
		std::string adress, double longitude, double latitude);
	Crime::Crime(int hour, DayOfWeek dayOfWeek, std::string category,
		std::string adress, double longitude, double latitude);

	~Crime();
	void printValues();
	//Fields: "date" "hour" "Category" "DayOfWeek" "Address" "X" "Y"
	std::string mCategory, mAdress, mId;
	int dayOfWeek, mWorkingDuty, hour;
	double mLatitude, mLongitude;
};