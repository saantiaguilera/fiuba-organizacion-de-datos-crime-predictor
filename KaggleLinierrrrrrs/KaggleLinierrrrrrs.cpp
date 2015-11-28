// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "CrimeParser.h"
#include "DataManager.h"
#include "CrimePredictor.h"

int main() {
	std::cout << "Starting to parse crimes, this might take a while" << std::endl;

	DataManager *dataManager = new DataManager();
	CrimeParser *crimeParser = new CrimeParser();
	crimeParser->readFileWithManager(dataManager);
	
	std::cout << "Finished parsing crimes, predictions are about to start, hold on tight" << std::endl;

	//crimeParser->getCrimesHourFreq();
	
	CrimePredictor *crimePredictor = new CrimePredictor();
	crimePredictor->predictCrime(dataManager);

	std::cout << "Finished predicting all the crimes, horray ! Let me free some of the space we have just used" << std::endl;

	delete crimeParser;
	delete dataManager;

	std::cout << "Done. Press a key to exit.." << std::endl;
		
	std::cin.get();

	return 0;
}