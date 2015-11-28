#include "stdafx.h"
#include "CategoryConstantsManage.h"

CategoryConstantsManage::CategoryConstantsManage() {
	createWorkingDutyCategoryMap();
	createWorkingOffCategoryMap();
	createWeekDayCategoryMap();
	createWeekendCategoryMap();
}

CategoryConstantsManage::~CategoryConstantsManage() {
}


void CategoryConstantsManage::createWorkingDutyCategoryMap() {
	workingDutyCategoryConstants["ARSON"] = 26.1732;
	workingDutyCategoryConstants["ASSAULT"] = 43.2216;
	workingDutyCategoryConstants["BAD CHECKS"] = 66.2562;
	workingDutyCategoryConstants["BRIBERY"] = 48.7509;
	workingDutyCategoryConstants["BURGLARY"] = 44.7313;
	workingDutyCategoryConstants["DISORDERLY CONDUCT"] = 34.6065;
	workingDutyCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 11.5961;
	workingDutyCategoryConstants["DRUG/NARCOTIC"] = 54.3699;
	workingDutyCategoryConstants["DRUNKENNESS"] = 30;
	workingDutyCategoryConstants["EMBEZZLEMENT"] = 56.518;
	workingDutyCategoryConstants["EXTORTION"] = 53.125;
	workingDutyCategoryConstants["FAMILY OFFENSES"] = 57.4338;
	workingDutyCategoryConstants["FORGERY/COUNTERFEITING"] = 62.2962;
	workingDutyCategoryConstants["FRAUD"] = 54.002;
	workingDutyCategoryConstants["GAMBLING"] = 64.3836;
	workingDutyCategoryConstants["KIDNAPPING"] = 38.0607;
	workingDutyCategoryConstants["LARCENY/THEFT"] = 46.3871;
	workingDutyCategoryConstants["LIQUOR LAWS"] = 47.031;
	workingDutyCategoryConstants["LOITERING"] = 41.9592;
	workingDutyCategoryConstants["MISSING PERSON"] = 51.7142;
	workingDutyCategoryConstants["NON-CRIMINAL"] = 52.1516;
	workingDutyCategoryConstants["OTHER OFFENSES"] = 47.6455;
	workingDutyCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 54.5455;
	workingDutyCategoryConstants["PROSTITUTION"] = 13.8295;
	workingDutyCategoryConstants["RECOVERED VEHICLE"] = 52.1033;
	workingDutyCategoryConstants["ROBBERY"] = 32.8652;
	workingDutyCategoryConstants["RUNAWAY"] = 46.5057;
	workingDutyCategoryConstants["SECONDARY CODES"] = 43.1347;
	workingDutyCategoryConstants["SEX OFFENSES FORCIBLE"] = 36.2124;
	workingDutyCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 50;
	workingDutyCategoryConstants["STOLEN PROPERTY"] = 47.8634;
	workingDutyCategoryConstants["SUICIDE"] = 47.2441;
	workingDutyCategoryConstants["SUSPICIOUS OCC"] = 50.3215;
	workingDutyCategoryConstants["TREA"] = 50;
	workingDutyCategoryConstants["TRESPASS"] = 46.3008;
	workingDutyCategoryConstants["VANDALISM"] = 33.6344;
	workingDutyCategoryConstants["VEHICLE THEFT"] = 36.5055;
	workingDutyCategoryConstants["WARRANTS"] = 49.9242;
	workingDutyCategoryConstants["WEAPON LAWS"] = 43.5885;
}

void CategoryConstantsManage::createWorkingOffCategoryMap() {
	workingOffCategoryConstants["ARSON"] = 73.8268;
	workingOffCategoryConstants["ASSAULT"] = 56.7784;
	workingOffCategoryConstants["BAD CHECKS"] = 33.7438;
	workingOffCategoryConstants["BRIBERY"] = 52.2491;
	workingOffCategoryConstants["BURGLARY"] = 55.2687;
	workingOffCategoryConstants["DISORDERLY CONDUCT"] = 65.3935;
	workingOffCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 88.4039;
	workingOffCategoryConstants["DRUG/NARCOTIC"] = 45.6301;
	workingOffCategoryConstants["DRUNKENNESS"] = 70;
	workingOffCategoryConstants["EMBEZZLEMENT"] = 43.482;
	workingOffCategoryConstants["EXTORTION"] = 46.875;
	workingOffCategoryConstants["FAMILY OFFENSES"] = 42.5662;
	workingOffCategoryConstants["FORGERY/COUNTERFEITING"] = 37.7038;
	workingOffCategoryConstants["FRAUD"] = 45.998;
	workingOffCategoryConstants["GAMBLING"] = 35.6164;
	workingOffCategoryConstants["KIDNAPPING"] = 61.9393;
	workingOffCategoryConstants["LARCENY/THEFT"] = 53.6129;
	workingOffCategoryConstants["LIQUOR LAWS"] = 52.969;
	workingOffCategoryConstants["LOITERING"] = 58.0408;
	workingOffCategoryConstants["MISSING PERSON"] = 48.2858;
	workingOffCategoryConstants["NON-CRIMINAL"] = 47.8484;
	workingOffCategoryConstants["OTHER OFFENSES"] = 52.3545;
	workingOffCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 45.4545;
	workingOffCategoryConstants["PROSTITUTION"] = 86.1705;
	workingOffCategoryConstants["RECOVERED VEHICLE"] = 47.8967;
	workingOffCategoryConstants["ROBBERY"] = 67.1348;
	workingOffCategoryConstants["RUNAWAY"] = 53.4943;
	workingOffCategoryConstants["SECONDARY CODES"] = 56.8653;
	workingOffCategoryConstants["SEX OFFENSES FORCIBLE"] = 63.7876;
	workingOffCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 50;
	workingOffCategoryConstants["STOLEN PROPERTY"] = 52.1366;
	workingOffCategoryConstants["SUICIDE"] = 52.7559;
	workingOffCategoryConstants["SUSPICIOUS OCC"] = 49.6785;
	workingOffCategoryConstants["TREA"] = 50;
	workingOffCategoryConstants["TRESPASS"] = 53.6992;
	workingOffCategoryConstants["VANDALISM"] = 66.3656;
	workingOffCategoryConstants["VEHICLE THEFT"] = 63.4945;
	workingOffCategoryConstants["WARRANTS"] = 50.0758;
	workingOffCategoryConstants["WEAPON LAWS"] = 56.4115;
}

void CategoryConstantsManage::createWeekDayCategoryMap() {
}

void CategoryConstantsManage::createWeekendCategoryMap() {
	weekendCategoryConstants["ARSON"] = 50;
	weekendCategoryConstants["ASSAULT"] = 54;
	weekendCategoryConstants["BAD CHECKS"] = 33;
	weekendCategoryConstants["BRIBERY"] = 50;
	weekendCategoryConstants["BURGLARY"] = 45;
	weekendCategoryConstants["DISORDERLY CONDUCT"] = 50;
	weekendCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 63;
	weekendCategoryConstants["DRUG/NARCOTIC"] = 44;
	weekendCategoryConstants["DRUNKENNESS"] = 61;
	weekendCategoryConstants["EMBEZZLEMENT"] = 40;
	weekendCategoryConstants["EXTORTION"] = 49;
	weekendCategoryConstants["FAMILY OFFENSES"] = 43;
	weekendCategoryConstants["FORGERY/COUNTERFEITING"] = 38;
	weekendCategoryConstants["FRAUD"] = 46;
	weekendCategoryConstants["GAMBLING"] = 43;
	weekendCategoryConstants["KIDNAPPING"] = 54;
	weekendCategoryConstants["LARCENY/THEFT"] = 50;
	weekendCategoryConstants["LIQUOR LAWS"] = 49;
	weekendCategoryConstants["LOITERING"] = 45;
	weekendCategoryConstants["MISSING PERSON"] = 48;
	weekendCategoryConstants["NON-CRIMINAL"] = 50;
	weekendCategoryConstants["OTHER OFFENSES"] = 47;
	weekendCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 36;
	weekendCategoryConstants["PROSTITUTION"] = 38;
	weekendCategoryConstants["RECOVERED VEHICLE"] = 40;
	weekendCategoryConstants["ROBBERY"] = 50;
	weekendCategoryConstants["RUNAWAY"] = 45;
	weekendCategoryConstants["SECONDARY CODES"] = 52;
	weekendCategoryConstants["SEX OFFENSES FORCIBLE"] = 53;
	weekendCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 46;
	weekendCategoryConstants["STOLEN PROPERTY"] = 47;
	weekendCategoryConstants["SUICIDE"] = 49;
	weekendCategoryConstants["SUSPICIOUS OCC"] = 47;
	weekendCategoryConstants["TREA"] = 56;
	weekendCategoryConstants["TRESPASS"] = 47;
	weekendCategoryConstants["VANDALISM"] = 54;
	weekendCategoryConstants["VEHICLE THEFT"] = 51;
	weekendCategoryConstants["WARRANTS"] = 46;
	weekendCategoryConstants["WEAPON LAWS"] = 49;
}

void CategoryConstantsManage::createStreetCornerCategoryMap() {

}

void CategoryConstantsManage::createStreetNonCornerCategoryMap() {

}