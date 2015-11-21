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
	//Ahora ya esta adentro del proyecto. nombre "importantTrain.csv"
	std::ifstream file("importantTrain.csv");

	//Just for testing purposes. dont want to be iterating infinite times now. Should be removed (and everything about totalCases).
	int totalCases = 0;
	int positiveCases = 0;
	int i = 0;

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
		while (std::getline(file, currentLine) && i < CASES_TO_PREDICT) {
			//Clean stuff
			bestCase = "";
			totalPoints = 0;
			maxDistance = 0;
			categoryPointsMap.clear();

			//Get crime and parcel asociated
			Crime* crime = this->crimeParser->createCrimeFromCSVChunk(currentLine);

			Parcel *parcel(dataManager->getParcelOfCrime(crime));//(dataManager->getParcelOfCrime(crime));

			//Get the data we will use
			getDataForCrime(crime, parcel, maxDistance, categoryDayTimeOcasions, categoryDutiesOcasions);

			//Foreach crime in the parcel get the points corresponding to the distance (1 best - 0 worst)
			for (Crime* parcelCrime : parcel->crimes) {
				if (categoryPointsMap.find(crime->mCategory) == categoryPointsMap.end())
					categoryPointsMap[crime->mCategory] = 0;
				else {
					long double distance = sqrt(pow(parcelCrime->mLatitude - crime->mLatitude, 2) + pow(parcelCrime->mLongitude - crime->mLongitude, 2));
					long double probability = (distance / maxDistance);
					categoryPointsMap[crime->mCategory] += (1 - probability);
				}
			}

			long double bestScore = 0;
			//Should iterate over each category that was found and bias them (the other ones since there were 0 hits will be 0%
			for (std::map<std::string, long double>::iterator it = categoryPointsMap.begin(); it != categoryPointsMap.end(); ++it) {
				//Calculate bias for each thing (with a super equation I made up and might be horrible)
				double biasForDayTime = ((categoryDayTimeOcasions[it->first] / parcel->crimes.size()) > 0.5 ? 1 + (1 - (categoryDayTimeOcasions[it->first] / parcel->crimes.size())) : 0.5 + (categoryDayTimeOcasions[it->first] / parcel->crimes.size()));
				double biasForWorkingDuty = ((categoryDutiesOcasions[it->first] / parcel->crimes.size()) > 0.5 ? 1 + (1 - (categoryDutiesOcasions[it->first] / parcel->crimes.size())) : 0.5 + (categoryDutiesOcasions[it->first] / parcel->crimes.size()));
				
				//Merge them in 1 bias, since if not second bias might be stronger than the first one
				double mergeBias = (biasForDayTime + biasForWorkingDuty) / 2;
				
				//Compute and save totalPoints
				it->second *= mergeBias;				
				totalPoints += it->second;	

				if (it->second > bestScore)
					bestCase = it->first;
			}

			//For now we will simply get the stronger , if not simply iterate again and save the %
			if (!bestCase.compare(crime->mCategory)) {
				positiveCases++;
			}

			totalCases++;
			i++;
		
			//delete the crime pointer which dissappears after this scope (not the parcel since its from the DataManager which is currently used and it will be deleted on ~DataManager)
			delete crime;
		}
		std::cout << "predicciones correctas " << positiveCases << "\n";
		std::cout << "predicciones totales " << totalCases << "\n";

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