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

	/*
	std::size_t found = dayOfWeek.find("Monday");
	int typeOfDay = -1;
	if (found != std::string::npos)
		typeOfDay=0;

	found = dayOfWeek.find("Tuesday");
	if (found != std::string::npos)
		typeOfDay = 0;

	found = dayOfWeek.find("Wednesday");
	if (found != std::string::npos)
		typeOfDay = 0;

	found = dayOfWeek.find("Thursday");
	if (found != std::string::npos)
		typeOfDay = 0;

	found = dayOfWeek.find("Friday");
	if (found != std::string::npos)
		typeOfDay = 0;

	found = dayOfWeek.find("Saturday");
	if (found != std::string::npos)
		typeOfDay = 1;

	found = dayOfWeek.find("Sunday");
	if (found != std::string::npos)
		typeOfDay = 1;

	std::string onlyHour = hour.substr(1, 2);
	std::string specialCategory = category.substr(1, category.length() - 2);
	std::replace(specialCategory.begin(), specialCategory.end(), ' ', '_');
	std::replace(specialCategory.begin(), specialCategory.end(), '-', '_');
	std::replace(specialCategory.begin(), specialCategory.end(), '/', '_');

	if (crimesHourFreq.find(specialCategory) == crimesHourFreq.end())
	{
		crimesHourFreq[specialCategory] = {0.0,0.0, 0, 0};
		if (std::stoi(onlyHour) < 18 && std::stoi(onlyHour) >= 9)
			crimesHourFreq[specialCategory][0]++;
		crimesHourFreq[specialCategory][1]++;

		switch (typeOfDay) {
		case 0:
			crimesHourFreq[specialCategory][2]++;
			break;

		case 1:
			crimesHourFreq[specialCategory][3]++;
		}

	}
	else
	{
		if (std::stoi(onlyHour) < 18 && std::stoi(onlyHour) >= 9)
			crimesHourFreq[specialCategory][0]++;
		crimesHourFreq[specialCategory][1]++;

		switch (typeOfDay) {
		case 0:
			crimesHourFreq[specialCategory][2]++;
			break;

		case 1:
			crimesHourFreq[specialCategory][3]++;
		}

	}
	*/

	return new Crime(date, hour, category, dayOfWeek, address, std::stod(x), std::stod(y));
}

bool PDCrimeParser::readFileWithManager(CrimeParserManager* crimeParserManager)
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
		while (std::getline(file, currentLine) && i < 5000) {
			//create a Crime from the chunk we init before and print the values we got.
			Crime* crime = createCrimeFromCSVChunk(currentLine);

			crimeParserManager -> addCrimeToMatrix(crime);

			//Uncomment if you want to see the descript of a Crime (beware, reduce the index of i<VALUE.
			//crime->printValues();

			i++;
		}

		numberTotalOfCrimes = i;

	} else return false;

	return true;
}

void PDCrimeParser::createFileWithDefinitionsForCategories()
{
	//For using this method please add to the stdafx.h "#include <algorithm>"
	std::ofstream myfile("categoryConstants.txt");
	if (myfile.is_open()) {

		for (std::map<std::string, std::vector<double>>::iterator it = crimesHourFreq.begin(); it != crimesHourFreq.end(); ++it) {
			myfile << "#define TYPE_WORKING_DUTY_" << it->first << " " << it->second[0] / it->second[1] * 100 << std::endl;
			myfile << "#define TYPE_WORKING_OFF_" << it->first << " " << 100 - (it->second[0] / it->second[1] * 100) << std::endl;
			myfile << "#define TYPE_DAY_FROM_WEEK_" << it->first << " " << (it->second[2] / (it->second[2] + it->second[3])) * 100 << std::endl;
			myfile << "#define TYPE_DAY_FROM_WEEKEND_" << it->first << " " << (it->second[3] / (it->second[2] + it->second[3])) * 100 << std::endl;
		}

		myfile.close();
	}
	else std::cout << "Couldnt open file" << std::endl;

}