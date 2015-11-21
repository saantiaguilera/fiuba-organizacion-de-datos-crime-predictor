#include "stdafx.h"
#include "CrimeParser.h"
#include "Crime.h"
#include "DataManager.h"

CrimeParser::CrimeParser()
{
}

CrimeParser::~CrimeParser()
{

}

Crime* CrimeParser::createCrimeFromCSVChunk(const std::string & dataChunk) {
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
	char separator(',');

	std::getline(aux, date, separator);
	std::getline(aux, hour, separator);
	std::getline(aux, category, separator);
	std::getline(aux, dayOfWeek, separator);
	std::getline(aux, address, separator);
	std::getline(aux, x, separator);
	std::getline(aux, y, separator);

	//Set the type of day
	std::size_t found = dayOfWeek.find("Monday");
	DayTime typeOfDay = DAY_FROM_WEEK;
	if (found != std::string::npos)
		typeOfDay= DAY_FROM_WEEK;
	else {
		found = dayOfWeek.find("Tuesday");
		if (found != std::string::npos)
			typeOfDay = DAY_FROM_WEEK;
		else {
			found = dayOfWeek.find("Wednesday");
			if (found != std::string::npos)
				typeOfDay = DAY_FROM_WEEK;
			else {
				found = dayOfWeek.find("Thursday");
				if (found != std::string::npos)
					typeOfDay = DAY_FROM_WEEK;
				else {
					found = dayOfWeek.find("Friday");
					if (found != std::string::npos)
						typeOfDay = DAY_FROM_WEEK;
					else {
						found = dayOfWeek.find("Saturday");
						if (found != std::string::npos)
							typeOfDay = DAY_FROM_WEEKEND;
						else {
							found = dayOfWeek.find("Sunday");
							if (found != std::string::npos)
								typeOfDay = DAY_FROM_WEEKEND;
						}
					}
				}
			}
		}
	}

	//Set the working duty
	WorkingDuty typeOfHour = WORKING_DUTY_OFF;
	std::string onlyHour = hour.substr(1, 2);
	if (std::stoi(onlyHour) < 18 && std::stoi(onlyHour) >= 9)
		typeOfHour = WORKING_DUTY;

	//Remove "" from categories
	category = category.substr(1, category.length() - 2);

	return new Crime(typeOfDay, typeOfHour, category, address, std::stod(x), std::stod(y));
}

bool CrimeParser::readFileWithManager(DataManager* dataManager)
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
		while (std::getline(file, currentLine) && i < CASES_TO_PARSE) {
			if (i > CASES_TO_PREDICT) {
				//create a Crime from the chunk we init before and print the values we got.
				Crime* crime(createCrimeFromCSVChunk(currentLine));

				dataManager->addCrimeToMatrix(crime);

				//Uncomment if you want to see the descript of a Crime (beware, reduce the index of i<VALUE.
				//crime->printValues();
			}
			i++;
		}

	} else return false;

	return true;
}