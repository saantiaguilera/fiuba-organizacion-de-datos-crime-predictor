// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "CrimeParser.h"
#include "DataManager.h"
#include "CrimePredictor.h"

int main() {
	DataManager *dataManager = new DataManager();
	CrimeParser *crimeParser = new CrimeParser();
	crimeParser->readFileWithManager(dataManager);
	
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Numero de crimenes ingresados a la matriz: " << dataManager->numberOfCrimesAddedToMatrix << std::endl;
	std::cout << "Numero de crimenes no ingresados a la matriz: " << dataManager->numberOfCrimesOutOfMatrix << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;
	
	CrimePredictor *crimePredictor = new CrimePredictor();
	crimePredictor->crimeParser = crimeParser;
	crimePredictor->predictCrime(dataManager);

	std::cin.get();

	delete crimePredictor;
	delete crimeParser;
	delete dataManager;

	return 0;
}