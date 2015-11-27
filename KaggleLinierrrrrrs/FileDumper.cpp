#include "stdafx.h"
#include "FileDumper.h"

/*
Using things this way, times are:
- Writing all 882000 crimes: 607 seconds
- Flushing a set of 50000 crimes: ~60ms
- Sending to the buffer a crime prediction: <1ms
*/

//Dont change
#define COMMA ","
#define EOL "\n"

//Change if needed
#define HEADERS "Id,ARSON,ASSAULT,BAD CHECKS,BRIBERY,BURGLARY,DISORDERLY CONDUCT,DRIVING UNDER THE INFLUENCE,DRUG/NARCOTIC,DRUNKENNESS,EMBEZZLEMENT,EXTORTION,FAMILY OFFENSES,FORGERY/COUNTERFEITING,FRAUD,GAMBLING,KIDNAPPING,LARCENY/THEFT,LIQUOR LAWS,LOITERING,MISSING PERSON,NON-CRIMINAL,OTHER OFFENSES,PORNOGRAPHY/OBSCENE MAT,PROSTITUTION,RECOVERED VEHICLE,ROBBERY,RUNAWAY,SECONDARY CODES,SEX OFFENSES FORCIBLE,SEX OFFENSES NON FORCIBLE,STOLEN PROPERTY,SUICIDE,SUSPICIOUS OCC,TREA,TRESPASS,VANDALISM,VEHICLE THEFT,WARRANTS,WEAPON LAWS\n"
#define MAX_CRIMES_IN_BUFFER 50000

//Dont change
FileDumper::FileDumper() : count(0) {
	dumpFile.open("dump.csv", std::ofstream::out | std::ofstream::trunc);
	dumpHeaders();
}

//Dont change
FileDumper::~FileDumper() {
	dumpFile.close();
}

//Dont change
void FileDumper::dumpHeaders() {
	dumpFile << HEADERS;
}

//Dont change
void FileDumper::dumpPrediction(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints) {
	if (count >= MAX_CRIMES_IN_BUFFER) {
		flushBuffer();
	}

	addToBuffer(id, pointsMap, totalPoints);
	count++;
}

//Dont change
void FileDumper::flushBuffer() {
	dumpFile << buffer.str();
	buffer.clear();
	buffer.str(std::string());
	count = 0;
}

//On each '0' goes the percentage for each category. See the HEADERS define to know the order. 
//Dont change the structure or the COMMA / << / buffer / EOL things. Its optimized this way
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