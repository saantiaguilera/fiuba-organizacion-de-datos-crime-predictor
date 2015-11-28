#include "stdafx.h"
#include "CrimePredictor.h"
#include <map>
#include "FileDumper.h"


CrimePredictor::CrimePredictor() {
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
		std::map<std::string, float>* categoryHourConstants;
		std::map<std::string, float>* categoryDaysConstants;

		//First line is  the row indicator, skip it.
		std::getline(file, currentLine);

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine)) {
			//Clean stuff

			//Get crime and parcel asociated
			Crime* crime = this->createCrimeFromCSVChunk(currentLine);

			Parcel* parcel = dataManager->getParcelOfCrime(crime);

			//Create mapper needed for the final values (maybe its more efficient outside loop and clear it ?)
			std::map<std::string, double> finalValues;

			//Get the corresponding map according to the crime to predict
			if (crime->mWorkingDuty == WORKING_DUTY) 
				categoryHourConstants = &categoryConstantsManager->workingDutyCategoryConstants;
			else categoryHourConstants = &categoryConstantsManager->workingOffCategoryConstants;

			if (crime->mDayTime == DAY_FROM_WEEK)
				categoryDaysConstants = &categoryConstantsManager->weekDayCategoryConstants;
			else categoryDaysConstants = &categoryConstantsManager->weekendCategoryConstants;
			
			//Create percentages based on data we have
			double total = 0;
			if (parcel != NULL) {
				double sizeOfParcel = parcel->crimes.size();
				if (sizeOfParcel == 0)
					sizeOfParcel = 1;

				for (auto const &pair : parcel->crimesCountMap) {
					finalValues[pair.first] = (pair.second / sizeOfParcel) * categoryHourConstants->find(pair.first)->second * categoryDaysConstants->find(pair.first)->second;
					total += finalValues[pair.first];
				}
			}
			else {
				total = 1;
			}

			//Dump predictions
			fileDumper->dumpPrediction(crime->mId, finalValues, total);
		
			//delete the crime pointer which dissappears after this scope (not the parcel since its from the DataManager which is currently used and it will be deleted on ~DataManager)
			delete crime;
		}

		//Since the buffer could still hold data not flushed, flush the remains
		fileDumper->flushBuffer();
	}

	delete fileDumper;
}

void CrimePredictor::getDataForCrime(Crime *currentCrime, Parcel *parcel, long double &maxDistance) {
	for (Crime* crime : parcel->crimes) {
		//Get the max distance
		long double distance = sqrt(pow(crime->mLatitude - currentCrime->mLatitude, 2) + pow(crime->mLongitude - currentCrime->mLongitude, 2));
		if (distance > maxDistance)
			maxDistance = distance;
	}
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

	return new Crime(id, typeOfDay, typeOfHour, address, std::stod(x), std::stod(y));
}