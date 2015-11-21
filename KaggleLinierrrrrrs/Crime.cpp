#include "stdafx.h"
#include "Crime.h"

Crime::Crime(DayTime dayTime, WorkingDuty workingDuty, std::string category,
	std::string adress, double longitude, double latitude) :
	mDayTime(dayTime), mWorkingDuty(workingDuty), mCategory(category),
	mAdress(adress), mLatitude(latitude),
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