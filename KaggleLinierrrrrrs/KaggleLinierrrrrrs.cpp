// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "CrimeParser.h"
#include "DataManager.h"
#include "CrimePredictor.h"

int main() {
	long long startingMilis = (std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch())).count();

	DataManager *dataManager = new DataManager();
	CrimeParser *crimeParser = new CrimeParser();
	crimeParser->readFileWithManager(dataManager);
	
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Numero de crimenes ingresados a la matriz: " << dataManager->numberOfCrimesAddedToMatrix << std::endl;
	std::cout << "Numero de crimenes no ingresados a la matriz: " << dataManager->numberOfCrimesOutOfMatrix << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;

	//crimeParser->getCrimesHourFreq();
	
	CrimePredictor *crimePredictor = new CrimePredictor();
	crimePredictor->predictCrime(dataManager);

	delete crimeParser;
	delete dataManager;
	
	long long endingMilis = (std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch())).count();
	long long timeElapsed = (endingMilis - startingMilis) / 1000;
	
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Time elapsed (in seconds): " << timeElapsed << std::endl;

	std::cin.get();

	return 0;
}