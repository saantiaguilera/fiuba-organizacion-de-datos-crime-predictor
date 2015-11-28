#include "stdafx.h"
#include "Crime.h"

Crime::Crime(DayTime dayTime, WorkingDuty workingDuty, std::string category,
	Address adress, double longitude, double latitude) :
	mDayTime(dayTime), mWorkingDuty(workingDuty), mCategory(category),
	mAddress(adress), mLatitude(latitude),
	mLongitude(longitude) {
}

Crime::Crime(std::string id, DayTime dayTime, WorkingDuty workingDuty,
	Address adress, double longitude, double latitude) :
	mId(id), mDayTime(dayTime), mWorkingDuty(workingDuty),
	mAddress(adress), mLatitude(latitude),
	mLongitude(longitude) {
}

Crime::Crime() {
}

Crime::~Crime() {
}

void Crime::printValues() {
	std::cout << "----------------------------------" << std::endl;
	std::cout << "---------------CRIME--------------" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Category " << mCategory << std::endl;
	std::cout << "Address " << mAdress << std::endl;
	std::cout << "Latitude " << mLatitude << std::endl;
	std::cout << "Longitude " << mLongitude << std::endl;
}