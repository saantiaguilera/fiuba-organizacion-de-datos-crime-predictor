// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "PDCrimeParser.h"
#include "CrimeParserManager.h"

int main() {
	CrimeParserManager *crimeParserManager = new CrimeParserManager();

	PDCrimeParser *parser = new PDCrimeParser();
	parser->readFileWithManager(crimeParserManager);
	/*
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Numero total de crimenes: " << parser->numberTotalOfCrimes << std::endl;
	std::cout << "Numero de crimenes ingresados a la matriz: " << crimeParserManager->numberOfCrimesAddedToMatrix << std::endl;
	std::cout << "Numero de crimenes no ingresados a la matriz: " << crimeParserManager->numberOfCrimesOutOfMatrix << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;

	parser->getCrimesHourFreq();
	*/
	std::cin.get();

	delete parser;
	delete crimeParserManager;

	return 0;
}