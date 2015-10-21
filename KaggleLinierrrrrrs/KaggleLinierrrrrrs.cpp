// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "PDCrimeParser.h"
#include "CrimeParserManager.h"

int main() {
	CrimeParserManager *crimeParserManager = new CrimeParserManager();

	PDCrimeParser *parser = new PDCrimeParser();
	parser->readFileWithManager(crimeParserManager);

	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Numero total de crimenes: " << parser->numberTotalOfCrimes << std::endl;
	std::cout << "Numero de crimenes ingresados a la matriz: " << crimeParserManager->numberOfCrimesAddedToMatrix << std::endl;
	std::cout << "Numero de crimenes no ingresados a la matriz: " << crimeParserManager->numberOfCrimesOutOfMatrix << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Delitos en horario laboral: " << parser->workingDuty << std::endl;
	std::cout << "Delitos fuera de horario laboral: " << parser->offDuty << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Delitos los lunes: " << parser->monday << std::endl;
	std::cout << "Delitos los martes: " << parser->tuesday << std::endl;
	std::cout << "Delitos los miercoles: " << parser->wednesday << std::endl;
	std::cout << "Delitos los jueves: " << parser->thursday << std::endl;
	std::cout << "Delitos los viernes: " << parser->friday << std::endl;
	std::cout << "Delitos los sabados: " << parser->saturday << std::endl;
	std::cout << "Delitos los domingos: " << parser->sunday << std::endl;
	std::cout << "Delitos los dias habiles: " << (parser->monday + parser->tuesday + parser->wednesday + parser->thursday + parser->friday) << std::endl;
	std::cout << "Delitos los fines de semana : " << (parser->saturday + parser->sunday) << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "##################################################" << std::endl;

	std::cin.get();

	delete parser;
	delete crimeParserManager;

	return 0;
}