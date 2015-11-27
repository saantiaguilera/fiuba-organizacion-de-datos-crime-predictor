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

	return new Crime(date, hour, category, dayOfWeek, address, std::stod(x), std::stod(y));
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
		while (std::getline(file, currentLine) && i < 1) {
			//if (i != 0)
			//{
				//create a Crime from the chunk we init before and print the values we got.
				Crime* crime(createCrimeFromCSVChunk(currentLine));

				dataManager->addCrimeToMatrix(crime);

				//Uncomment if you want to see the descript of a Crime (beware, reduce the index of i<VALUE.
				//crime->printValues();
			//}
			

			i++;
		}

	} else return false;

	return true;
}

void CrimeParser::createFileWithDefinitionsForCategories()
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