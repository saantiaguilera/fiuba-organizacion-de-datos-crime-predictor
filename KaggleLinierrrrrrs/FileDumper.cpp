#include "stdafx.h"
#include "FileDumper.h"

#define HEADERS "Id,ARSON,ASSAULT,BAD CHECKS,BRIBERY,BURGLARY,DISORDERLY CONDUCT,DRIVING UNDER THE INFLUENCE,DRUG/NARCOTIC,DRUNKENNESS,EMBEZZLEMENT,EXTORTION,FAMILY OFFENSES,FORGERY/COUNTERFEITING,FRAUD,GAMBLING,KIDNAPPING,LARCENY/THEFT,LIQUOR LAWS,LOITERING,MISSING PERSON,NON-CRIMINAL,OTHER OFFENSES,PORNOGRAPHY/OBSCENE MAT,PROSTITUTION,RECOVERED VEHICLE,ROBBERY,RUNAWAY,SECONDARY CODES,SEX OFFENSES FORCIBLE,SEX OFFENSES NON FORCIBLE,STOLEN PROPERTY,SUICIDE,SUSPICIOUS OCC,TREA,TRESPASS,VANDALISM,VEHICLE THEFT,WARRANTS,WEAPON LAWS\n"
#define COMMA ","
#define MAX_CRIMES_IN_BUFFER 1000

FileDumper::FileDumper() : count(0) {
	fopen_s(&dumpFile, "dump.csv", "w+");

	if (dumpFile == NULL)
		exit(-1);

	dumpHeaders();
}

FileDumper::~FileDumper() {
	fclose(dumpFile);
}

void FileDumper::dumpHeaders() {
	fprintf(dumpFile, HEADERS);
}

void FileDumper::dumpPrediction(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints) {
	if (count >= MAX_CRIMES_IN_BUFFER) {
		flushBuffer();
	}

	addToBuffer(id, pointsMap, totalPoints);
	count++;
}

void FileDumper::flushBuffer() {
	fprintf(dumpFile, buffer.str().c_str());
	buffer.clear();
	buffer.str(std::string());
	count = 0;
}

void FileDumper::addToBuffer(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints) {
	buffer << id
		<< COMMA
		<< (pointsMap["ARSON"] / totalPoints)
		<< COMMA
		<< (pointsMap["ASSAULT"] / totalPoints)
		<< COMMA
		<< (pointsMap["BAD CHECKS"] / totalPoints)
		<< COMMA
		<< (pointsMap["BRIBERY"] / totalPoints)
		<< COMMA
		<< (pointsMap["BURGLARY"] / totalPoints)
		<< COMMA
		<< (pointsMap["DISORDERLY CONDUCT"] / totalPoints)
		<< COMMA
		<< (pointsMap["DRIVING UNDER THE INFLUENCE"] / totalPoints)
		<< COMMA
		<< (pointsMap["DRUG/NARCOTIC"] / totalPoints)
		<< COMMA
		<< (pointsMap["DRUNKENNESS"] / totalPoints)
		<< COMMA
		<< (pointsMap["EMBEZZLEMENT"] / totalPoints)
		<< COMMA
		<< (pointsMap["EXTORTION"] / totalPoints)
		<< COMMA
		<< (pointsMap["FAMILY OFFENSES"] / totalPoints)
		<< COMMA
		<< (pointsMap["FORGERY/COUNTERFEITING"] / totalPoints)
		<< COMMA
		<< (pointsMap["FRAUD"] / totalPoints)
		<< COMMA
		<< (pointsMap["GAMBLING"] / totalPoints)
		<< COMMA
		<< (pointsMap["KIDNAPPING"] / totalPoints)
		<< COMMA
		<< (pointsMap["LARCENY/THEFT"] / totalPoints)
		<< COMMA
		<< (pointsMap["LIQUOR LAWS"] / totalPoints)
		<< COMMA
		<< (pointsMap["LOITERING"] / totalPoints)
		<< COMMA
		<< (pointsMap["MISSING PERSON"] / totalPoints)
		<< COMMA
		<< (pointsMap["NON-CRIMINAL"] / totalPoints)
		<< COMMA
		<< (pointsMap["OTHER OFFENSES"] / totalPoints)
		<< COMMA
		<< (pointsMap["PORNOGRAPHY/OBSCENE MAT"] / totalPoints)
		<< COMMA
		<< (pointsMap["PROSTITUTION"] / totalPoints)
		<< COMMA
		<< (pointsMap["RECOVERED VEHICLE"] / totalPoints)
		<< COMMA
		<< (pointsMap["ROBBERY"] / totalPoints)
		<< COMMA
		<< (pointsMap["RUNAWAY"] / totalPoints)
		<< COMMA
		<< (pointsMap["SECONDARY CODES"] / totalPoints)
		<< COMMA
		<< (pointsMap["SEX OFFENSES FORCIBLE"] / totalPoints)
		<< COMMA
		<< (pointsMap["SEX OFFENSES NON FORCIBLE"] / totalPoints)
		<< COMMA
		<< (pointsMap["STOLEN PROPERTY"] / totalPoints)
		<< COMMA
		<< (pointsMap["SUICIDE"] / totalPoints)
		<< COMMA
		<< (pointsMap["SUSPICIOUS OCC"] / totalPoints)
		<< COMMA
		<< (pointsMap["TREA"] / totalPoints)
		<< COMMA
		<< (pointsMap["TRESPASS"] / totalPoints)
		<< COMMA
		<< (pointsMap["VANDALISM"] / totalPoints)
		<< COMMA
		<< (pointsMap["VEHICLE THEFT"] / totalPoints)
		<< COMMA
		<< (pointsMap["WARRANTS"] / totalPoints)
		<< COMMA
		<< (pointsMap["WEAPON LAWS"] / totalPoints)
		<< "\n";
}