// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "PDCrimeParser.h"

int main() {
	PDCrimeParser *parser = new PDCrimeParser();
	parser->readFile();

	delete parser;

	std::cin.get();

	return 0;
}