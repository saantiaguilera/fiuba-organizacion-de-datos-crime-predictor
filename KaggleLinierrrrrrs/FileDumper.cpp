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
void FileDumper::dumpPrediction(std::string& id, std::map<std::string, double>& values, double& points) {
	if (count >= MAX_CRIMES_IN_BUFFER) {
		flushBuffer();
	}

	addToBuffer(id, values, points);
	count++;
}

//Dont change
void FileDumper::flushBuffer() {
	std::cout << "Flushing a set of " << count << "\n";
	dumpFile << buffer.str();
	buffer.clear();
	buffer.str(std::string());
	count = 0;
}

//On each '0' goes the percentage for each category. See the HEADERS define to know the order. 
//Dont change the structure or the COMMA / << / buffer / EOL things. Its optimized this way
void FileDumper::addToBuffer(std::string& id, std::map<std::string, double>& values, double& total) {
	if (total == 0)
		total = 1;

	buffer << id
		<< COMMA
		<< (values["ARSON"] / total)
		<< COMMA
		<< (values["ASSAULT"] / total)
		<< COMMA
		<< (values["BAD CHECKS"] / total)
		<< COMMA
		<< (values["BRIBERY"] / total)
		<< COMMA
		<< (values["BURGLARY"] / total)
		<< COMMA
		<< (values["DISORDERLY CONDUCT"] / total)
		<< COMMA
		<< (values["DRIVING UNDER THE INFLUENCE"] / total)
		<< COMMA
		<< (values["DRUG/NARCOTIC"] / total)
		<< COMMA
		<< (values["DRUNKENNESS"] / total)
		<< COMMA
		<< (values["EMBEZZLEMENT"] / total)
		<< COMMA
		<< (values["EXTORTION"] / total)
		<< COMMA
		<< (values["FAMILY OFFENSES"] / total)
		<< COMMA
		<< (values["FORGERY/COUNTERFEITING"] / total)
		<< COMMA
		<< (values["FRAUD"] / total)
		<< COMMA
		<< (values["GAMBLING"] / total)
		<< COMMA
		<< (values["KIDNAPPING"] / total)
		<< COMMA
		<< (values["LARCENY/THEFT"] / total)
		<< COMMA
		<< (values["LIQUOR LAWS"] / total)
		<< COMMA
		<< (values["LOITERING"] / total)
		<< COMMA
		<< (values["MISSING PERSON"] / total)
		<< COMMA
		<< (values["NON-CRIMINAL"] / total)
		<< COMMA
		<< (values["OTHER OFFENSES"] / total)
		<< COMMA
		<< (values["PORNOGRAPHY/OBSCENE MAT"] / total)
		<< COMMA
		<< (values["PROSTITUTION"] / total)
		<< COMMA
		<< (values["RECOVERED VEHICLE"] / total)
		<< COMMA
		<< (values["ROBBERY"] / total)
		<< COMMA
		<< (values["RUNAWAY"] / total)
		<< COMMA
		<< (values["SECONDARY CODES"] / total)
		<< COMMA
		<< (values["SEX OFFENSES FORCIBLE"] / total)
		<< COMMA
		<< (values["SEX OFFENSES NON FORCIBLE"] / total)
		<< COMMA
		<< (values["STOLEN PROPERTY"] / total)
		<< COMMA
		<< (values["SUICIDE"] / total)
		<< COMMA
		<< (values["SUSPICIOUS OCC"] / total)
		<< COMMA
		<< (values["TREA"] / total)
		<< COMMA
		<< (values["TRESPASS"] / total)
		<< COMMA
		<< (values["VANDALISM"] / total)
		<< COMMA
		<< (values["VEHICLE THEFT"] / total)
		<< COMMA
		<< (values["WARRANTS"] / total)
		<< COMMA
		<< (values["WEAPON LAWS"] / total)
		<< EOL;
}