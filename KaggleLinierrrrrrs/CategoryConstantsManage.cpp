#include "stdafx.h"
#include "CategoryConstantsManage.h"

CategoryConstantsManage::CategoryConstantsManage() {
	createWorkingDutyCategoryMap();
	createWorkingOffCategoryMap();
	createWeekDayCategoryMap();
	createWeekendCategoryMap();
	createStreetCornerCategoryMap();
	createStreetNonCornerCategoryMap();
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
	weekDayCategoryConstants["ARSON"] = 50;
	weekDayCategoryConstants["ASSAULT"] = 46;
	weekDayCategoryConstants["BAD CHECKS"] = 67;
	weekDayCategoryConstants["BRIBERY"] = 50;
	weekDayCategoryConstants["BURGLARY"] = 55;
	weekDayCategoryConstants["DISORDERLY CONDUCT"] = 50;
	weekDayCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 37;
	weekDayCategoryConstants["DRUG/NARCOTIC"] = 56;
	weekDayCategoryConstants["DRUNKENNESS"] = 39;
	weekDayCategoryConstants["EMBEZZLEMENT"] = 60;
	weekDayCategoryConstants["EXTORTION"] = 51;
	weekDayCategoryConstants["FAMILY OFFENSES"] = 57;
	weekDayCategoryConstants["FORGERY/COUNTERFEITING"] = 62;
	weekDayCategoryConstants["FRAUD"] = 54;
	weekDayCategoryConstants["GAMBLING"] = 57;
	weekDayCategoryConstants["KIDNAPPING"] = 46;
	weekDayCategoryConstants["LARCENY/THEFT"] = 50;
	weekDayCategoryConstants["LIQUOR LAWS"] = 51;
	weekDayCategoryConstants["LOITERING"] = 55;
	weekDayCategoryConstants["MISSING PERSON"] = 52;
	weekDayCategoryConstants["NON-CRIMINAL"] = 50;
	weekDayCategoryConstants["OTHER OFFENSES"] = 53;
	weekDayCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 64;
	weekDayCategoryConstants["PROSTITUTION"] = 62;
	weekDayCategoryConstants["RECOVERED VEHICLE"] = 60;
	weekDayCategoryConstants["ROBBERY"] = 50;
	weekDayCategoryConstants["RUNAWAY"] = 55;
	weekDayCategoryConstants["SECONDARY CODES"] = 48;
	weekDayCategoryConstants["SEX OFFENSES FORCIBLE"] = 47;
	weekDayCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 54;
	weekDayCategoryConstants["STOLEN PROPERTY"] = 53;
	weekDayCategoryConstants["SUICIDE"] = 51;
	weekDayCategoryConstants["SUSPICIOUS OCC"] = 53;
	weekDayCategoryConstants["TREA"] = 44;
	weekDayCategoryConstants["TRESPASS"] = 53;
	weekDayCategoryConstants["VANDALISM"] = 46;
	weekDayCategoryConstants["VEHICLE THEFT"] = 49;
	weekDayCategoryConstants["WARRANTS"] = 54;
	weekDayCategoryConstants["WEAPON LAWS"] = 51;
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
	streetCornerCategoryConstants["ARSON"] = 8.3361232;
	streetCornerCategoryConstants["ASSAULT"] = 10.0357071;
	streetCornerCategoryConstants["BAD CHECKS"] = 2.60869565;
	streetCornerCategoryConstants["BRIBERY"] = 6.65499124;
	streetCornerCategoryConstants["BURGLARY"] = 0.597498401;
	streetCornerCategoryConstants["DISORDERLY CONDUCT"] = 14.6612623;
	streetCornerCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 31.2458655;
	streetCornerCategoryConstants["DRUG/NARCOTIC"] = 18.4539416;
	streetCornerCategoryConstants["DRUNKENNESS"] = 16.3334503;
	streetCornerCategoryConstants["EMBEZZLEMENT"] = 1.17136659;
	streetCornerCategoryConstants["EXTORTION"] = 5.74257426;
	streetCornerCategoryConstants["FAMILY OFFENSES"] = 3.36487907;
	streetCornerCategoryConstants["FORGERY/COUNTERFEITING"] = 3.93563305;
	streetCornerCategoryConstants["FRAUD"] = 8.58257087;
	streetCornerCategoryConstants["GAMBLING"] = 7.06713781;
	streetCornerCategoryConstants["KIDNAPPING"] = 9.0130593;
	streetCornerCategoryConstants["LARCENY/THEFT"] = 16.2917285;
	streetCornerCategoryConstants["LIQUOR LAWS"] = 15.6496581;
	streetCornerCategoryConstants["LOITERING"] = 31.2576813;
	streetCornerCategoryConstants["MISSING PERSON"] = 3.25754221;
	streetCornerCategoryConstants["NON-CRIMINAL"] = 12.96203;
	streetCornerCategoryConstants["OTHER OFFENSES"] = 23.9048513;
	streetCornerCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 9.75609756;
	streetCornerCategoryConstants["PROSTITUTION"] = 39.7192181;
	streetCornerCategoryConstants["RECOVERED VEHICLE"] = 6.97711634;
	streetCornerCategoryConstants["ROBBERY"] = 22.12222;
	streetCornerCategoryConstants["RUNAWAY"] = 1.01694915;
	streetCornerCategoryConstants["SECONDARY CODES"] = 6.75614764;
	streetCornerCategoryConstants["SEX OFFENSES FORCIBLE"] = 8.17466651;
	streetCornerCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 6.52920962;
	streetCornerCategoryConstants["STOLEN PROPERTY"] = 13.0439573;
	streetCornerCategoryConstants["SUICIDE"] = 1.7769003;
	streetCornerCategoryConstants["SUSPICIOUS OCC"] = 9.10436596;
	//TODO VER ESTA DE ABAJO
	streetCornerCategoryConstants["TREA"] = 1;
	streetCornerCategoryConstants["TRESPASS"] = 2.41752187;
	streetCornerCategoryConstants["VANDALISM"] = 11.0789388;
	streetCornerCategoryConstants["VEHICLE THEFT"] = 18.2082725;
	streetCornerCategoryConstants["WARRANTS"] = 16.8630888;
	streetCornerCategoryConstants["WEAPON LAWS"] = 14.4377522;
}

void CategoryConstantsManage::createStreetNonCornerCategoryMap() {
	streetNonCornerCategoryConstants["ARSON"] = 91.6638768;
	streetNonCornerCategoryConstants["ASSAULT"] = 89.9642929;
	streetNonCornerCategoryConstants["BAD CHECKS"] = 97.3913043;
	streetNonCornerCategoryConstants["BRIBERY"] = 93.3450088;
	streetNonCornerCategoryConstants["BURGLARY"] = 99.4025016;
	streetNonCornerCategoryConstants["DISORDERLY CONDUCT"] = 85.3387377;
	streetNonCornerCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 68.7541345;
	streetNonCornerCategoryConstants["DRUG/NARCOTIC"] = 81.5460584;
	streetNonCornerCategoryConstants["DRUNKENNESS"] = 83.6665497;
	streetNonCornerCategoryConstants["EMBEZZLEMENT"] = 98.8286334;
	streetNonCornerCategoryConstants["EXTORTION"] = 94.2574257;
	streetNonCornerCategoryConstants["FAMILY OFFENSES"] = 96.6351209;
	streetNonCornerCategoryConstants["FORGERY/COUNTERFEITING"] = 96.0643669;
	streetNonCornerCategoryConstants["FRAUD"] = 91.4174291;
	streetNonCornerCategoryConstants["GAMBLING"] = 92.9328622;
	streetNonCornerCategoryConstants["KIDNAPPING"] = 90.9869407;
	streetNonCornerCategoryConstants["LARCENY/THEFT"] = 83.7082715;
	streetNonCornerCategoryConstants["LIQUOR LAWS"] = 84.3503419;
	streetNonCornerCategoryConstants["LOITERING"] = 68.7423187;
	streetNonCornerCategoryConstants["MISSING PERSON"] = 96.7424578;
	streetNonCornerCategoryConstants["NON-CRIMINAL"] = 87.03797;
	streetNonCornerCategoryConstants["OTHER OFFENSES"] = 76.0951487;
	streetNonCornerCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 90.2439024;
	streetNonCornerCategoryConstants["PROSTITUTION"] = 60.2807819;
	streetNonCornerCategoryConstants["RECOVERED VEHICLE"] = 93.0228837;
	streetNonCornerCategoryConstants["ROBBERY"] = 77.87778;
	streetNonCornerCategoryConstants["RUNAWAY"] = 98.9830508;
	streetNonCornerCategoryConstants["SECONDARY CODES"] = 93.2438524;
	streetNonCornerCategoryConstants["SEX OFFENSES FORCIBLE"] = 91.8253335;
	streetNonCornerCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 93.4707904;
	streetNonCornerCategoryConstants["STOLEN PROPERTY"] = 86.9560427;
	streetNonCornerCategoryConstants["SUICIDE"] = 98.2230997;
	streetNonCornerCategoryConstants["SUSPICIOUS OCC"] = 90.895634;
	//TODO VER ESTA DE ABAJO
	streetNonCornerCategoryConstants["TREA"] = 100;
	streetNonCornerCategoryConstants["TRESPASS"] = 97.5824781;
	streetNonCornerCategoryConstants["VANDALISM"] = 88.9210612;
	streetNonCornerCategoryConstants["VEHICLE THEFT"] = 81.7917275;
	streetNonCornerCategoryConstants["WARRANTS"] = 83.1369112;
	streetNonCornerCategoryConstants["WEAPON LAWS"] = 85.5622478;

}