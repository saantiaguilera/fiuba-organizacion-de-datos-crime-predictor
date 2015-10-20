#include "stdafx.h"
#include "Crime.h"

Crime::Crime(std::string date, std::string hour, std::string category, std::string dow,
	std::string adress, double longitude, double latitude) :
	mDate(date), mHour(hour), mCategory(category),
	mDayOfWeek(dow), mAdress(adress), mLatitude(latitude),
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
	std::cout << "Date " << mDate << std::endl;
	std::cout << "Hour " << mHour << std::endl;
	std::cout << "Category " << mCategory << std::endl;
	std::cout << "DayOfWeek " << mDayOfWeek << std::endl;
	std::cout << "Address " << mAdress << std::endl;
	std::cout << "Latitude " << mLatitude << std::endl;
	std::cout << "Longitude " << mLongitude << std::endl;
}