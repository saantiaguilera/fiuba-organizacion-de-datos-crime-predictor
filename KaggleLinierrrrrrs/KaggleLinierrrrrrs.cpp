// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "CrimeParser.h"
#include "DataManager.h"
#include "CrimePredictor.h"

int main() {

	DataManager *dataManager = new DataManager();
	CrimeParser *crimeParser = new CrimeParser();
	crimeParser->readFileWithManager(dataManager);
	
	std::cout << "Finished reading crimes" << std::endl;

	CrimePredictor *crimePredictor = new CrimePredictor();
	crimePredictor->predictCrime(dataManager);
	
	delete crimeParser;
	delete dataManager;
	
	std::cout << "Finished predicting" << std::endl;

	std::cin.get();

	return 0;
}