#include "stdafx.h"
#include "CrimePredictor.h"
#include <time.h>

CrimePredictor::CrimePredictor() {
	srand(time(NULL));
}

CrimePredictor::~CrimePredictor()
{

}

void CrimePredictor::predictCrime(DataManager *dataManager) {
	//Ahora ya esta adentro del proyecto. nombre "crimesToPredict.csv"
	std::ifstream file("crimesToPredict.csv");
	std::ofstream dump("dump.csv");
	
	//If the file is malformed, doesnt exists, by some reason its not available for reading or whatsoever, return 1.
	if (file.good()) {
		//Init variables we will be using in the loop
		std::string currentLine;
		long double maxDistance;
		long double totalPoints;
		std::map<std::string, long double> categoryPointsMap;
		std::map<std::string, int> categoryDayTimeOcasions; //Saves the amount of hits for a category in the same dayTime that has the currentCrime
		std::map<std::string, int> categoryDutiesOcasions; //Saves the amount of hits for a category in the same workingDuty that has the currentCrime
		std::string bestCase; //Temporal, remove at later ocasion

		//First line is  the row indicator, skip it.
		std::getline(file, currentLine);

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine)) {
			//Clean stuff
			bestCase = "";
			totalPoints = 0;
			maxDistance = 0;
			categoryPointsMap.clear();
			categoryDayTimeOcasions.clear();
			categoryDutiesOcasions.clear();

			//Get crime and parcel asociated
			Crime* crime = this->createCrimeFromCSVChunk(currentLine);

			Parcel* parcel = dataManager->getParcelOfCrime(crime);//(dataManager->getParcelOfCrime(crime));

			//Get the data we will use
			getDataForCrime(crime, parcel, maxDistance, categoryDayTimeOcasions, categoryDutiesOcasions);

			//Foreach crime in the parcel get the points corresponding to the distance (1 best - 0 worst)
			for (Crime* parcelCrime : parcel->crimes) {
				if (categoryPointsMap.find(parcelCrime->mCategory) == categoryPointsMap.end())
					categoryPointsMap[parcelCrime->mCategory] = 0;

				long double distance = sqrt(pow(parcelCrime->mLatitude - crime->mLatitude, 2) + pow(parcelCrime->mLongitude - crime->mLongitude, 2));
				long double probability = (distance / maxDistance);
				categoryPointsMap[parcelCrime->mCategory] += (1 - probability);
			}

			long double bestScore = 0;
			//Should iterate over each category that was found and bias them (the other ones since there were 0 hits will be 0%
			for (std::map<std::string, long double>::iterator it = categoryPointsMap.begin(); it != categoryPointsMap.end(); ++it) {
				//Calculate bias for each thing (with a super equation I made up and might be horrible)
				double biasForDayTime = ((categoryDayTimeOcasions[it->first] / (double) parcel->getCrimesCategoryCount(it->first)) > 0.5 ? 1 + (1 - (categoryDayTimeOcasions[it->first] / (double) parcel->getCrimesCategoryCount(it->first))) : 0.5 + (categoryDayTimeOcasions[it->first] / (double) parcel->getCrimesCategoryCount(it->first)));
				double biasForWorkingDuty = ((categoryDutiesOcasions[it->first] / (double) parcel->getCrimesCategoryCount(it->first)) > 0.5 ? 1 + (1 - (categoryDutiesOcasions[it->first] / (double) parcel->getCrimesCategoryCount(it->first))) : 0.5 + (categoryDutiesOcasions[it->first] / (double) parcel->getCrimesCategoryCount(it->first)));
				
				//Merge them in 1 bias, since if not second bias might be stronger than the first one
				double mergeBias = (biasForDayTime + biasForWorkingDuty) / 2;
				
				//Compute and save totalPoints
				it->second *= mergeBias;				
				totalPoints += it->second;	
			}

			dumpData(dump, crime->mId, categoryPointsMap, totalPoints);
		
			//delete the crime pointer which dissappears after this scope (not the parcel since its from the DataManager which is currently used and it will be deleted on ~DataManager)
			delete crime;
		}
	}
}

void CrimePredictor::getDataForCrime(Crime *currentCrime, Parcel *parcel, long double &maxDistance, std::map<std::string, int> &categoryTimesOcasionsMap, std::map<std::string, int> &categoryDutiesOcasionsMap) {
	for (Crime* crime : parcel->crimes) {
		//Get the max distance
		long double distance = sqrt(pow(crime->mLatitude - currentCrime->mLatitude, 2) + pow(crime->mLongitude - currentCrime->mLongitude, 2));
		if (distance > maxDistance)
			maxDistance = distance;

		//Find in the map if the category already exists
		if (categoryTimesOcasionsMap.find(crime->mCategory) == categoryTimesOcasionsMap.end())
			categoryTimesOcasionsMap[crime->mCategory] = 0;

		//If its in the same dayTime then add 1
		if(currentCrime->mDayTime == crime->mDayTime)
			categoryTimesOcasionsMap[crime->mCategory] ++;

		//Repeat but for working duty
		if (categoryDutiesOcasionsMap.find(crime->mCategory) == categoryDutiesOcasionsMap.end())
			categoryDutiesOcasionsMap[crime->mCategory] = 0;

		//If its in the same workingDuty then add 1
		if (currentCrime->mWorkingDuty == crime->mWorkingDuty)
			categoryDutiesOcasionsMap[crime->mCategory] ++;
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
	std::string x;
	std::string y;

	//Gotta catch em all
	char separator(',');

	std::getline(aux, id, separator);
	std::getline(aux, hour, separator);
	std::getline(aux, dayOfWeek, separator);
	std::getline(aux, address, separator);
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

void CrimePredictor::dumpData(std::ofstream &data, std::string id, std::map<std::string, long double> &pointsMap, long double totalPoints) {
	data << id;
	for (std::map<std::string, long double>::iterator it = pointsMap.begin(); it != pointsMap.end(); ++it) {
		data << "," << it->first ;
	}
	for (std::map<std::string, long double>::iterator it = pointsMap.begin(); it != pointsMap.end(); ++it) {
		data << "," << (it->second / totalPoints);
	}
}