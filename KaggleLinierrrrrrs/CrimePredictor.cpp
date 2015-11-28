#include "stdafx.h"
#include "CrimePredictor.h"
#include <time.h>
#include <map>
#include "FileDumper.h"


CrimePredictor::CrimePredictor() {
	srand(time(NULL));
	categoryConstantsManager = new CategoryConstantsManage();
}

CrimePredictor::~CrimePredictor()
{
	delete categoryConstantsManager;
}

void CrimePredictor::predictCrime(DataManager *dataManager) {
	//Ahora ya esta adentro del proyecto. nombre "crimesToPredict.csv"
	std::ifstream file("crimesToPredict.csv");

	FileDumper* fileDumper = new FileDumper();
	
	//If the file is malformed, doesnt exists, by some reason its not available for reading or whatsoever, return 1.
	if (file.good()) {
		//Init variables we will be using in the loop
		std::string currentLine;

		//First line is  the row indicator, skip it.
		std::getline(file, currentLine);

		long i = 0;

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine)) {
			//Clean stuff

			//Get crime and parcel asociated
			Crime* crime = this->createCrimeFromCSVChunk(currentLine);

			Parcel* parcel = dataManager->getParcelOfCrime(crime);

			std::map<std::string, double> finalValues;
			std::map<std::string, double>* categoryHourConstants;
			std::map<std::string, double>* categoryDaysConstants;
			//std::map<std::string, double>* categoryStreetConstants;

			if (crime->mWorkingDuty == WORKING_DUTY)
				categoryHourConstants = &categoryConstantsManager->workingDutyCategoryConstants;
			else categoryHourConstants = &categoryConstantsManager->workingOffCategoryConstants;

			if (crime->mDayTime == DAY_FROM_WEEK)
				categoryDaysConstants = &categoryConstantsManager->weekDayCategoryConstants;
			else categoryDaysConstants = &categoryConstantsManager->weekendCategoryConstants;

			/*if (crime->mAddress == IN_CORNER)
			categoryStreetConstants = &categoryConstantsManager->streetCornerCategoryConstants;
			else categoryStreetConstants = &categoryConstantsManager->streetNonCornerCategoryConstants;
			*/

			double total = 0;
			if (parcel != NULL) {
				double sizeOfParcel = parcel->totalCrimes;
				if (sizeOfParcel == 0) sizeOfParcel = 1;

				for (auto const &pair : parcel->crimesCountMap) {
					finalValues[pair.first] = (pair.second / sizeOfParcel) * categoryHourConstants->find(pair.first)->second * categoryDaysConstants->find(pair.first)->second; //* categoryStreetConstants->find(pair.first)->second
					total += finalValues[pair.first];
				}
			}
			else {
				total = 1;
			}

			fileDumper->dumpPrediction(crime->mId, finalValues, total);

			++i;
			//delete the crime pointer which dissappears after this scope (not the parcel since its from the DataManager which is currently used and it will be deleted on ~DataManager)
			delete crime;
		}

		fileDumper->flushBuffer();
	}

	delete fileDumper;
}

Crime* CrimePredictor::createCrimeFromCSVChunk(const std::string & dataChunk) {
	//Create a stream from the chunk line
	std::istringstream aux(dataChunk);

	//Create variables
	std::string id;
	std::string hour;
	std::string category;
	std::string dayOfWeek;
	std::string address;
	std::string district;
	std::string x;
	std::string y;

	//Gotta catch em all
	char separator(',');

	std::getline(aux, id, separator);
	std::getline(aux, hour, separator);
	std::getline(aux, dayOfWeek, separator);
	std::getline(aux, address, separator);

	std::getline(aux, district, separator);

	std::getline(aux, x, separator);
	std::getline(aux, y, separator);

	//Set the type of day
	std::size_t found = dayOfWeek.find("Monday");
	DayTime typeOfDay = DAY_FROM_WEEK;
	if (found != std::string::npos)
		typeOfDay = DAY_FROM_WEEK;
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

	//Set the type of address
	Address typeOfAddress = IN_BETWEEN_STREETS;
	if (address.find("/") != std::string::npos)
		typeOfAddress = IN_CORNER;

	return new Crime(id, typeOfDay, typeOfHour, typeOfAddress, std::stod(x), std::stod(y));
}