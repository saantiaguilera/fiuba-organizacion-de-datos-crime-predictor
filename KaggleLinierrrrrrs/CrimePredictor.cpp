#include "stdafx.h"
#include "CrimePredictor.h"
#include <time.h>

#define kCategoryWorkingDuty "TYPE_WORKING_DUTY_"
#define kCategoryWorkingOff "TYPE_WORKING_OFF_"
#define kCategoryDayFromWeek "TYPE_DAY_FROM_WEEK_"
#define kCategoryDayFromWeekend "TYPE_DAY_FROM_WEEKEND_"

CrimePredictor::CrimePredictor() {
	srand(time(NULL));
	categoryConstantsManager = new CategoryConstantsManage();
}

CrimePredictor::~CrimePredictor(){
	delete categoryConstantsManager;
}

void CrimePredictor::predictCrime(DataManager *dataManager) {
	//Ahora ya esta adentro del proyecto. nombre "importantTrain.csv"
	std::ifstream file("importantTrain.csv");

	//Just for testing purposes. dont want to be iterating infinite times now. Should be removed (and everything about totalCases).
	int totalCases = 0;

	//If the file is malformed, doesnt exists, by some reason its not available for reading or whatsoever, return 1.
	if (file.good()) {
		//Init variables we will be using in the loop
		std::string currentLine;

		//First line is  the row indicator, skip it.
		std::getline(file, currentLine);

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine) && totalCases < 1000) {
			Crime* crime = this->crimeParser->createCrimeFromCSVChunk(currentLine);

			Parcel *parcel(dataManager->getParcelOfCrime(crime));

			std::map<std::string, float> freqCategories(this->crimesFrequenciesForParcel(crime, parcel));

			totalCases++;
			//std::cout << "Crimen de cat a predecir: " << crime->mCategory << std::endl;
			//for (std::map<std::string, float>::iterator it = freqCategories.begin(); it != freqCategories.end(); ++it) {
				//std::cout << "Category " << it->first << " P: " << it->second << std::endl;
			//}
			//delete the crime pointer which dissappears after this scope (not the parcel since its from the DataManager which is currently used and it will be deleted on ~DataManager)
			delete crime;
		}
		
		std::cout << "predicciones totales " << totalCases << "\n";

	}
}

std::map<std::string, float> CrimePredictor::crimesFrequenciesForParcel(Crime *crime, Parcel *parcel) {
	float partialSum = 0;
	std::map<std::string, float> categoryHourConstants;
	std::map<std::string, float> categoryDaysConstants;
	std::map<std::string, float> crimesProbability;

	if ((std::stoi(crime->mHour.substr(1, 2)) < 18) && (std::stoi(crime->mHour.substr(1, 2)) >= 9)){
		categoryHourConstants = categoryConstantsManager->workingDutyCategoryConstants;
	}
	else {
		categoryHourConstants = categoryConstantsManager->workingOffCategoryConstants;
	}

	if (crime->mCategory.compare("Monday") || crime->mCategory.compare("Tuesday") || crime->mCategory.compare("Wednesday") || crime->mCategory.compare("Thursday") || crime->mCategory.compare("Friday"))
	{
		categoryDaysConstants = categoryConstantsManager->weekDayCategoryConstants;
	}
	else
	{
		categoryDaysConstants = categoryConstantsManager->weekendCategoryConstants;
	}

	for (std::map<std::string, int>::iterator it = parcel->crimesCountMap.begin(); it != parcel->crimesCountMap.end(); ++it) {
		int crimeFreq = it->second;

		std::string keyName(it->first);
		keyName.erase(0, 1);
		keyName.erase(keyName.length() - 1 , 1);

		float categoryHourFactor = categoryHourConstants.find(keyName)->second;
		float categoryDayFactor = categoryDaysConstants.find(keyName)->second;

		crimesProbability[it->first] = crimeFreq * categoryHourFactor * categoryDayFactor;
		partialSum += crimesProbability[it->first];
	}

	for (std::map<std::string, int>::iterator it = parcel->crimesCountMap.begin(); it != parcel->crimesCountMap.end(); ++it) {
		crimesProbability[it->first] = it->second / partialSum;
	}

	return crimesProbability;
}

/*std::string CrimePredictor::getCrimeCategoryPrediction(Crime *crime, Parcel *parcel) {
	//int number = crimeFreqs.back();
	long int random = rand() % partialSum;//crimeFreqs.back();//parcel->amountOfCrimes();
	int position = 0;
	bool founded = false;

	for (float crimeFreq : crimeFreqs) {
		if (random <= crimeFreq)
		{
			founded = true;
			break;
		}
		position++;
	}

	if (!founded)
	{
		position = crimeFreqs.size() - 1;
	}
	
	int index = 0;
	for (std::map<std::string, int>::iterator it = parcel->crimesCountMap.begin(); it != parcel->crimesCountMap.end(); ++it) {
		if (index == position)
		{
			return it->first;
		}
		index++;
	}
}*/
