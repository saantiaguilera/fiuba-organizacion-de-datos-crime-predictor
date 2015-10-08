#include "stdafx.h"
#include "Crime.h"

Crime::Crime(std::string date, std::string category, std::string descript, std::string dow, std::string pDistrict,
	std::string resolution, std::string adress, double longitude, double latitude) :
	mDate(date), mCategory(category), mDescript(descript), mDayOfWeek(dow),
	mPDDistrict(pDistrict), mResolution(resolution), mAdress(adress), mLatitude(latitude),
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
	std::cout << "Category " << mCategory << std::endl;
	std::cout << "Descript " << mDescript << std::endl;
	std::cout << "DayOfWeek " << mDayOfWeek << std::endl;
	std::cout << "PDDistrict " << mPDDistrict << std::endl;
	std::cout << "Resolution " << mResolution << std::endl;
	std::cout << "Address " << mAdress << std::endl;
	std::cout << "Latitude " << mLatitude << std::endl;
	std::cout << "Longitude " << mLongitude << std::endl;
}