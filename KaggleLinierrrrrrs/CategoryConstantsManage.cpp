#include "stdafx.h"
#include "CategoryConstantsManage.h"

CategoryConstantsManage::CategoryConstantsManage() {
	createWorkingDutyCategoryMap();
	createWorkingOffCategoryMap();
	createWeekDayCategoryMap();
	createWeekendCategoryMap();
	//createStreetCornerCategoryMap();
	//createStreetNonCornerCategoryMap();
}

CategoryConstantsManage::~CategoryConstantsManage() {
}

void CategoryConstantsManage::createWorkingDutyCategoryMap() {
	workingDutyCategoryConstants["ARSON"] = 26;
	workingDutyCategoryConstants["ASSAULT"] = 43;
	workingDutyCategoryConstants["BAD CHECKS"] = 66;
	workingDutyCategoryConstants["BRIBERY"] = 48;
	workingDutyCategoryConstants["BURGLARY"] = 45;
	workingDutyCategoryConstants["DISORDERLY CONDUCT"] = 35;
	workingDutyCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 12;
	workingDutyCategoryConstants["DRUG/NARCOTIC"] = 54;
	workingDutyCategoryConstants["DRUNKENNESS"] = 30;
	workingDutyCategoryConstants["EMBEZZLEMENT"] = 57;
	workingDutyCategoryConstants["EXTORTION"] = 53;
	workingDutyCategoryConstants["FAMILY OFFENSES"] = 57;
	workingDutyCategoryConstants["FORGERY/COUNTERFEITING"] = 62;
	workingDutyCategoryConstants["FRAUD"] = 54;
	workingDutyCategoryConstants["GAMBLING"] = 64;
	workingDutyCategoryConstants["KIDNAPPING"] = 38;
	workingDutyCategoryConstants["LARCENY/THEFT"] = 46;
	workingDutyCategoryConstants["LIQUOR LAWS"] = 47;
	workingDutyCategoryConstants["LOITERING"] = 42;
	workingDutyCategoryConstants["MISSING PERSON"] = 52;
	workingDutyCategoryConstants["NON-CRIMINAL"] = 52;
	workingDutyCategoryConstants["OTHER OFFENSES"] = 48;
	workingDutyCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 55;
	workingDutyCategoryConstants["PROSTITUTION"] = 14;
	workingDutyCategoryConstants["RECOVERED VEHICLE"] = 52;
	workingDutyCategoryConstants["ROBBERY"] = 33;
	workingDutyCategoryConstants["RUNAWAY"] = 47;
	workingDutyCategoryConstants["SECONDARY CODES"] = 43;
	workingDutyCategoryConstants["SEX OFFENSES FORCIBLE"] = 36;
	workingDutyCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 50;
	workingDutyCategoryConstants["STOLEN PROPERTY"] = 48;
	workingDutyCategoryConstants["SUICIDE"] = 47;
	workingDutyCategoryConstants["SUSPICIOUS OCC"] = 50;
	workingDutyCategoryConstants["TREA"] = 50;
	workingDutyCategoryConstants["TRESPASS"] = 46;
	workingDutyCategoryConstants["VANDALISM"] = 34;
	workingDutyCategoryConstants["VEHICLE THEFT"] = 37;
	workingDutyCategoryConstants["WARRANTS"] = 50;
	workingDutyCategoryConstants["WEAPON LAWS"] = 44;
}

void CategoryConstantsManage::createWorkingOffCategoryMap() {
	workingOffCategoryConstants["ARSON"] = 74;
	workingOffCategoryConstants["ASSAULT"] = 57;
	workingOffCategoryConstants["BAD CHECKS"] = 34;
	workingOffCategoryConstants["BRIBERY"] = 52;
	workingOffCategoryConstants["BURGLARY"] = 55;
	workingOffCategoryConstants["DISORDERLY CONDUCT"] = 65;
	workingOffCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 88;
	workingOffCategoryConstants["DRUG/NARCOTIC"] = 46;
	workingOffCategoryConstants["DRUNKENNESS"] = 70;
	workingOffCategoryConstants["EMBEZZLEMENT"] = 43;
	workingOffCategoryConstants["EXTORTION"] = 47;
	workingOffCategoryConstants["FAMILY OFFENSES"] = 43;
	workingOffCategoryConstants["FORGERY/COUNTERFEITING"] = 38;
	workingOffCategoryConstants["FRAUD"] = 46;
	workingOffCategoryConstants["GAMBLING"] = 36;
	workingOffCategoryConstants["KIDNAPPING"] = 62;
	workingOffCategoryConstants["LARCENY/THEFT"] = 54;
	workingOffCategoryConstants["LIQUOR LAWS"] = 53;
	workingOffCategoryConstants["LOITERING"] = 58;
	workingOffCategoryConstants["MISSING PERSON"] = 48;
	workingOffCategoryConstants["NON-CRIMINAL"] = 48;
	workingOffCategoryConstants["OTHER OFFENSES"] = 52;
	workingOffCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 45;
	workingOffCategoryConstants["PROSTITUTION"] = 86;
	workingOffCategoryConstants["RECOVERED VEHICLE"] = 48;
	workingOffCategoryConstants["ROBBERY"] = 67;
	workingOffCategoryConstants["RUNAWAY"] = 53;
	workingOffCategoryConstants["SECONDARY CODES"] = 57;
	workingOffCategoryConstants["SEX OFFENSES FORCIBLE"] = 64;
	workingOffCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 50;
	workingOffCategoryConstants["STOLEN PROPERTY"] = 52;
	workingOffCategoryConstants["SUICIDE"] = 53;
	workingOffCategoryConstants["SUSPICIOUS OCC"] = 50;
	workingOffCategoryConstants["TREA"] = 50;
	workingOffCategoryConstants["TRESPASS"] = 54;
	workingOffCategoryConstants["VANDALISM"] = 66;
	workingOffCategoryConstants["VEHICLE THEFT"] = 63;
	workingOffCategoryConstants["WARRANTS"] = 50;
	workingOffCategoryConstants["WEAPON LAWS"] = 56;
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
/*
void CategoryConstantsManage::createStreetCornerCategoryMap() {
	streetCornerCategoryConstants["ARSON"] = 16.6667;
	streetCornerCategoryConstants["ASSAULT"] = 20.0713;
	streetCornerCategoryConstants["BAD CHECKS"] = 5.21092;
	streetCornerCategoryConstants["BRIBERY"] = 13.2867;
	streetCornerCategoryConstants["BURGLARY"] = 1.19498;
	streetCornerCategoryConstants["DISORDERLY CONDUCT"] = 29.3191;
	streetCornerCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 62.478;
	streetCornerCategoryConstants["DRUG/NARCOTIC"] = 36.9075;
	streetCornerCategoryConstants["DRUNKENNESS"] = 32.6631;
	streetCornerCategoryConstants["EMBEZZLEMENT"] = 2.34172;
	streetCornerCategoryConstants["EXTORTION"] = 11.4625;
	streetCornerCategoryConstants["FAMILY OFFENSES"] = 6.72269;
	streetCornerCategoryConstants["FORGERY/COUNTERFEITING"] = 7.87089;
	streetCornerCategoryConstants["FRAUD"] = 17.1646;
	streetCornerCategoryConstants["GAMBLING"] = 14.0845;
	streetCornerCategoryConstants["KIDNAPPING"] = 18.0223;
	streetCornerCategoryConstants["LARCENY/THEFT"] = 32.5834;
	streetCornerCategoryConstants["LIQUOR LAWS"] = 31.2829;
	streetCornerCategoryConstants["LOITERING"] = 62.4898;
	streetCornerCategoryConstants["MISSING PERSON"] = 6.51496;
	streetCornerCategoryConstants["NON-CRIMINAL"] = 25.9239;
	streetCornerCategoryConstants["OTHER OFFENSES"] = 47.8095;
	streetCornerCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 19.0476;
	streetCornerCategoryConstants["PROSTITUTION"] = 79.4331;
	streetCornerCategoryConstants["RECOVERED VEHICLE"] = 13.952;
	streetCornerCategoryConstants["ROBBERY"] = 44.2435;
	streetCornerCategoryConstants["RUNAWAY"] = 2.03337;
	streetCornerCategoryConstants["SECONDARY CODES"] = 13.5116;
	streetCornerCategoryConstants["SEX OFFENSES FORCIBLE"] = 16.3475;
	streetCornerCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 13.0137;
	streetCornerCategoryConstants["STOLEN PROPERTY"] = 26.085;
	streetCornerCategoryConstants["SUICIDE"] = 3.5503;
	streetCornerCategoryConstants["SUSPICIOUS OCC"] = 18.2084;
	streetCornerCategoryConstants["TREA"] = 0;
	streetCornerCategoryConstants["TRESPASS"] = 4.83471;
	streetCornerCategoryConstants["VANDALISM"] = 22.1576;
	streetCornerCategoryConstants["VEHICLE THEFT"] = 36.4162;
	streetCornerCategoryConstants["WARRANTS"] = 33.7258;
	streetCornerCategoryConstants["WEAPON LAWS"] = 28.8738;
}

void CategoryConstantsManage::createStreetNonCornerCategoryMap() {
	streetNonCornerCategoryConstants["ARSON"] = 83.3333;
	streetNonCornerCategoryConstants["ASSAULT"] = 79.9287;
	streetNonCornerCategoryConstants["BAD CHECKS"] = 94.7891;
	streetNonCornerCategoryConstants["BRIBERY"] = 86.7133;
	streetNonCornerCategoryConstants["BURGLARY"] = 98.805;
	streetNonCornerCategoryConstants["DISORDERLY CONDUCT"] = 70.6809;
	streetNonCornerCategoryConstants["DRIVING UNDER THE INFLUENCE"] = 37.522;
	streetNonCornerCategoryConstants["DRUG/NARCOTIC"] = 63.0925;
	streetNonCornerCategoryConstants["DRUNKENNESS"] = 67.3369;
	streetNonCornerCategoryConstants["EMBEZZLEMENT"] = 97.6583;
	streetNonCornerCategoryConstants["EXTORTION"] = 88.5375;
	streetNonCornerCategoryConstants["FAMILY OFFENSES"] = 93.2773;
	streetNonCornerCategoryConstants["FORGERY/COUNTERFEITING"] = 92.1291;
	streetNonCornerCategoryConstants["FRAUD"] = 82.8354;
	streetNonCornerCategoryConstants["GAMBLING"] = 85.9155;
	streetNonCornerCategoryConstants["KIDNAPPING"] = 81.9777;
	streetNonCornerCategoryConstants["LARCENY/THEFT"] = 67.4166;
	streetNonCornerCategoryConstants["LIQUOR LAWS"] = 68.7171;
	streetNonCornerCategoryConstants["LOITERING"] = 37.5102;
	streetNonCornerCategoryConstants["MISSING PERSON"] = 93.485;
	streetNonCornerCategoryConstants["NON-CRIMINAL"] = 74.0761;
	streetNonCornerCategoryConstants["OTHER OFFENSES"] = 52.1905;
	streetNonCornerCategoryConstants["PORNOGRAPHY/OBSCENE MAT"] = 80.9524;
	streetNonCornerCategoryConstants["PROSTITUTION"] = 20.5669;
	streetNonCornerCategoryConstants["RECOVERED VEHICLE"] = 86.048;
	streetNonCornerCategoryConstants["ROBBERY"] = 55.7565;
	streetNonCornerCategoryConstants["RUNAWAY"] = 97.9666;
	streetNonCornerCategoryConstants["SECONDARY CODES"] = 86.4884;
	streetNonCornerCategoryConstants["SEX OFFENSES FORCIBLE"] = 83.6525;
	streetNonCornerCategoryConstants["SEX OFFENSES NON FORCIBLE"] = 86.9863;
	streetNonCornerCategoryConstants["STOLEN PROPERTY"] = 73.915;
	streetNonCornerCategoryConstants["SUICIDE"] = 96.4497;
	streetNonCornerCategoryConstants["SUSPICIOUS OCC"] = 81.7916;
	streetNonCornerCategoryConstants["TREA"] = 100;
	streetNonCornerCategoryConstants["TRESPASS"] = 95.1653;
	streetNonCornerCategoryConstants["VANDALISM"] = 77.8424;
	streetNonCornerCategoryConstants["VEHICLE THEFT"] = 63.5838;
	streetNonCornerCategoryConstants["WARRANTS"] = 66.2742;
	streetNonCornerCategoryConstants["WEAPON LAWS"] = 71.1262;
}
*/