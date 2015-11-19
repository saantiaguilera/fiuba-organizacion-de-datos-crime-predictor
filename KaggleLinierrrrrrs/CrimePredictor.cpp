#include "stdafx.h"
#include "CrimePredictor.h"

CrimePredictor::CrimePredictor() {

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
		while (std::getline(file, currentLine) && totalCases < 100) {
			Crime* crime(this->crimeParser->createCrimeFromCSVChunk(currentLine));

			Parcel *parcel(dataManager->getParcelOfCrime(crime));//(dataManager->getParcelOfCrime(crime));

			std::string maxFreqCategoryName(parcel->getMostFreqCategoryCrime());

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