#pragma once

#include "stdafx.h"

class Crime {
private:
	
public:
	Crime::Crime(std::string date, std::string hour, std::string category, std::string dow,
		std::string adress);
	Crime();
	Crime(std::string date, std::string hour, std::string category, std::string dayOfWeek, std::string address, double longitude, double latitude);
	~Crime();
	void printValues();
	//Fields: "date" "hour" "Category" "DayOfWeek" "Address" "X" "Y"
	std::string mDate; //In the future this should be a date?
	std::string mHour;
	std::string mCategory;
	std::string mDayOfWeek;
	std::string mAdress;
	double mLatitude;
	double mLongitude;
};