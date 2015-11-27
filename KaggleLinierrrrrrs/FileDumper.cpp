#include "stdafx.h"
#include "FileDumper.h"

#define HEADERS "Id,ARSON,ASSAULT,BAD CHECKS,BRIBERY,BURGLARY,DISORDERLY CONDUCT,DRIVING UNDER THE INFLUENCE,DRUG/NARCOTIC,DRUNKENNESS,EMBEZZLEMENT,EXTORTION,FAMILY OFFENSES,FORGERY/COUNTERFEITING,FRAUD,GAMBLING,KIDNAPPING,LARCENY/THEFT,LIQUOR LAWS,LOITERING,MISSING PERSON,NON-CRIMINAL,OTHER OFFENSES,PORNOGRAPHY/OBSCENE MAT,PROSTITUTION,RECOVERED VEHICLE,ROBBERY,RUNAWAY,SECONDARY CODES,SEX OFFENSES FORCIBLE,SEX OFFENSES NON FORCIBLE,STOLEN PROPERTY,SUICIDE,SUSPICIOUS OCC,TREA,TRESPASS,VANDALISM,VEHICLE THEFT,WARRANTS,WEAPON LAWS\n"
#define COMMA ","
#define EOL "\n"
#define MAX_CRIMES_IN_BUFFER 50000

FileDumper::FileDumper() : count(0) {
	dumpFile.open("dump.csv", std::ofstream::out | std::ofstream::trunc);
	dumpHeaders();
}

FileDumper::~FileDumper() {
	dumpFile.close();
}

void FileDumper::dumpHeaders() {
	dumpFile << HEADERS;
}

void FileDumper::dumpPrediction(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints) {
	if (count >= MAX_CRIMES_IN_BUFFER) {
		flushBuffer();
	}

	addToBuffer(id, pointsMap, totalPoints);
	count++;
}

void FileDumper::flushBuffer() {
	dumpFile << buffer.str();
	buffer.clear();
	buffer.str(std::string());
	count = 0;
}

void FileDumper::addToBuffer(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints) {
	buffer << id
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< COMMA
		<< 0
		<< EOL;
}