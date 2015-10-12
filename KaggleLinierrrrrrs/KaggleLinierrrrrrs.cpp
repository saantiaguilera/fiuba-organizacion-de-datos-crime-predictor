// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "PDCrimeParser.h"
#include "CrimeParserManager.h"

int main() {
	CrimeParserManager *crimeParserManager = new CrimeParserManager();

	PDCrimeParser *parser = new PDCrimeParser();
	parser->readFileWithManager(*crimeParserManager);

	std::cout << "numero total de crimenes " << parser->numberTotalOfCrimes << std::endl;
	std::cout << "numero de crimenes ingresados a la matriz " << crimeParserManager->numberOfCrimesAddedToMatrix << std::endl;
	std::cout << "numero de crimenes por fuera de San Francisco (coordenadas invalidas)" << crimeParserManager->numberOfCrimesOutOfMatrix << std::endl;

	std::cin.get();

	delete parser;
	delete crimeParserManager;

	return 0;
}