#include "stdafx.h"
#include "PDCrimeParser.h"
#include "Crime.h"
#include "CrimeParserManager.h"

PDCrimeParser::PDCrimeParser()
{
	numberTotalOfCrimes = 0;
}

PDCrimeParser::~PDCrimeParser()
{

}

Crime* PDCrimeParser::createCrimeFromCSVChunk(const std::string & dataChunk) {
	//Create a stream from the chunk line
	std::istringstream aux(dataChunk);

	//Create variables
	std::string date;
	std::string hour;
	std::string category;
	std::string dayOfWeek;
	std::string address;
	std::string x;
	std::string y;

	//Gotta catch em all
	std::getline(aux, date, ',');
	std::getline(aux, hour, ',');
	std::getline(aux, category, ',');
	std::getline(aux, dayOfWeek, ',');
	std::getline(aux, address, ',');
	std::getline(aux, x, ',');
	std::getline(aux, y, ',');
	
	return new Crime(date, hour, category, dayOfWeek, address, std::stod(x), std::stod(y));
}

bool PDCrimeParser::readFileWithManager(CrimeParserManager& crimeParserManager)
{

	//Ahora ya esta adentro del proyecto. nombre "importantTrain.csv"
    std::ifstream file("importantTrain.csv");

	//Just for testing purposes. dont want to be iterating infinite times now. Should be removed (and everything about i).
	int i = 0;

	//If the file is malformed, doesnt exists, by some reason its not available for reading or whatsoever, return 1.
	if (file.good()) {
		//Init variables we will be using in the loop
		std::string currentLine;

		//First line is  the row indicator, skip it.
		std::getline(file, currentLine);

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine) && i<5000) {
			//create a Crime from the chunk we init before and print the values we got.
			Crime* crime = createCrimeFromCSVChunk(currentLine);

			crimeParserManager.addCrimeToMatrix(crime);

			//Uncomment if you want to see the descript of a Crime (beware, reduce the index of i<VALUE.
			//crime->printValues();

			i++;
		}
		numberTotalOfCrimes = i;

	} else return false;

	return true;
}
