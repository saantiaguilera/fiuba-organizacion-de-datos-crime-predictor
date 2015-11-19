#include "stdafx.h"
#include "CrimePredictor.h"

CrimePredictor::CrimePredictor() {

}

CrimePredictor::~CrimePredictor()
{

}

void CrimePredictor::predictCrime(CrimeParserManager *crimeParserManager) {
	//Ahora ya esta adentro del proyecto. nombre "importantTrain.csv"
	std::ifstream file("importantTrain.csv");

	//Just for testing purposes. dont want to be iterating infinite times now. Should be removed (and everything about i).
	int i = 0;
	int numberOfRigth = 0;

	//If the file is malformed, doesnt exists, by some reason its not available for reading or whatsoever, return 1.
	if (file.good()) {
		//Init variables we will be using in the loop
		std::string currentLine;

		//First line is  the row indicator, skip it.
		std::getline(file, currentLine);

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine) && i < 81000) {
			Crime* crime = this->crimeParser->createCrimeFromCSVChunk(currentLine);

			Parcel *parcel = crimeParserManager->getParcelOfCrime(crime);//(crimeParserManager->getParcelOfCrime(crime));
			parcel = crimeParserManager->getParcelOfCrime(crime);
			std::string maxFreqCategoryName = parcel->getMostFreqCategoryCrime();

			if (maxFreqCategoryName.compare(crime->mCategory)) {
				numberOfRigth++;
			}

			i++;
		}
		std::cout << "predicciones correctas " << numberOfRigth << "\n";
		std::cout << "predicciones totales " << i << "\n";

	}
}