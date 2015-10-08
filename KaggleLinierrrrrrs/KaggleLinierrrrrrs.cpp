// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "PDCrimeParser.h"
#include "CrimeParserManager.h"

int main() {
	CrimeParserManager *crimeParserManager = new CrimeParserManager();

	PDCrimeParser *parser = new PDCrimeParser();
	parser->readFileWithManager(*crimeParserManager);

	delete parser;
	delete crimeParserManager;

	std::cin.get();

	return 0;
}