#include "stdafx.h"
#include "PDCrimeParser.h"
#include "Crime.h"
#include "CrimeParserManager.h"

PDCrimeParser::PDCrimeParser()
{
	numberTotalOfCrimes = 0;

	monday = 0;
	tuesday = 0;
	wednesday = 0;
	thursday = 0;
	friday = 0;
	saturday = 0;
	sunday = 0;

	workingDuty = 0;
	offDuty = 0;
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

	std::size_t found = dayOfWeek.find("Monday");
	if (found != std::string::npos)
		monday++;

	found = dayOfWeek.find("Tuesday");
	if (found != std::string::npos)
		tuesday++;

	found = dayOfWeek.find("Wednesday");
	if (found != std::string::npos)
		wednesday++;

	found = dayOfWeek.find("Thursday");
	if (found != std::string::npos)
		thursday++;

	found = dayOfWeek.find("Friday");
	if (found != std::string::npos)
		friday++;

	found = dayOfWeek.find("Saturday");
	if (found != std::string::npos)
		saturday++;

	found = dayOfWeek.find("Sunday");
	if (found != std::string::npos)
		sunday++;

	std::string onlyHour = hour.substr(1, 2);

	if (crimesHourFreq.find(category) == crimesHourFreq.end())
	{
		crimesHourFreq[category] = {0.0,0.0};
		if (std::stoi(onlyHour) < 18 && std::stoi(onlyHour) >= 9)
			crimesHourFreq[category][0]++;
		crimesHourFreq[category][1]++;
	}
	else
	{
		if (std::stoi(onlyHour) < 18 && std::stoi(onlyHour) >= 9)
			crimesHourFreq[category][0]++;
		crimesHourFreq[category][1]++;
	}

	if (std::stoi(onlyHour) < 18 && std::stoi(onlyHour) >= 9)
		workingDuty++;
	else offDuty++;

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
		while (std::getline(file, currentLine) && i<5000000) {
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

void PDCrimeParser::getCrimesHourFreq()
{
	for (std::map<std::string, std::vector<double>>::iterator it = crimesHourFreq.begin(); it != crimesHourFreq.end(); ++it) {
		std::cout << it->first << " laboral: " << it->second[0] / it->second[1] *100 << "% fuera laboral " << 100 - (it->second[0] / it->second[1] *100) <<"% \n";
	}
}
