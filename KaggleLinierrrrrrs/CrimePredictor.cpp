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

	//If the file is malformed, doesnt exists, by some reason its not available for reading or whatsoever, return 1.
	if (file.good()) {
		//Init variables we will be using in the loop
		std::string currentLine;

		//First line is  the row indicator, skip it.
		std::getline(file, currentLine);

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine) && totalCases < 1000) {
			Crime* crime = this->crimeParser->createCrimeFromCSVChunk(currentLine);

			Parcel *parcel(dataManager->getParcelOfCrime(crime));//(dataManager->getParcelOfCrime(crime));

			std::string maxFreqCategoryName(this->crimesFrequenciesForParcel(crime, parcel));

			if (maxFreqCategoryName.compare(crime->mCategory)) {
				positiveCases++;
			}

			totalCases++;
		
			//delete the crime pointer which dissappears after this scope (not the parcel since its from the DataManager which is currently used and it will be deleted on ~DataManager)
			delete crime;
		}
		std::cout << "predicciones correctas " << positiveCases << "\n";
		std::cout << "predicciones totales " << totalCases << "\n";

	}
}

std::string CrimePredictor::crimesFrequenciesForParcel(Crime *crime, Parcel *parcel) {
	int index = 0;
	int partialSum = 0;
	for (std::map<std::string, int>::iterator it = parcel->crimesCountMap.begin(); it != parcel->crimesCountMap.end(); ++it) {
		partialSum += it->second;
		crimeFreqs.push_back(partialSum);
		
		index ++;
	}
	return this->getCrimeCategoryPrediction(crime, parcel);
}

std::string CrimePredictor::getCrimeCategoryPrediction(Crime *crime, Parcel *parcel) {
	long int random = rand() % parcel->amountOfCrimes();
	int position = 0;
	for (float crimeFreq : crimeFreqs) {
		if (random <= crimeFreq)
		{
			break;
		}
		position++;
	}
	
	int index = 0;
	for (std::map<std::string, int>::iterator it = parcel->crimesCountMap.begin(); it != parcel->crimesCountMap.end(); ++it) {
		if (index == position)
		{
			return it->first;
		}
		index++;
	}
}