#pragma once

#include "stdafx.h"

class Crime {
private:
	//Fields: Dates,Category,Descript,DayOfWeek,PdDistrict,Resolution,Address,X,Y
	std::string mDate; //In the future this should be a date?
	std::string mCategory;
	std::string mDescript;
	std::string mDayOfWeek;
	std::string mPDDistrict;
	std::string mResolution;
	std::string mAdress;
	double mLatitude;
	double mLongitude;
public:
	Crime();
	Crime(std::string date, std::string category, std::string descript, std::string dayOfWeek, std::string pdDistrict, std::string resolution, std::string address, double longitude, double latitude);
	~Crime();
	void printValues();
};