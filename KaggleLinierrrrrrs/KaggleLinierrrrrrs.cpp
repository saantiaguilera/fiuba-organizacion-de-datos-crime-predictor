// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

std::string ID;
std::string nome;
std::string idade;
std::string genero;

int main()
{

	//Line eg: 2015-05-13 23:53:00,WARRANTS,WARRANT ARREST,Wednesday,NORTHERN,"ARREST, BOOKED",OAK ST / LAGUNA ST,-122.425891675136,37.7745985956747

	/*
	//This should be done to get the whole csv. We should create an object and go storing them bla bla ya lo pensamos todo esto.
	std::ifstream file(R"(C:\Users\Saantii\Desktop\Kagle\train.csv\train.csv)"); //http://en.cppreference.com/w/cpp/language/string_literal for R as raw delimiter

	while (file.good()) {

		std::getline(file, ID, ',');
		std::cout << "ID: " << ID << " ";

		std::getline(file, nome, ',');
		std::cout << "User: " << nome << " ";

		std::getline(file, idade, ',');
		std::cout << "Idade: " << idade << " ";

		std::getline(file, genero); // diff
		std::cout << "Sexo: " << genero; //diff
	}
	*/ //TODO uncomment this. Just commented because im showing an example of how to parse a single csv line. this should still work (i guess, im sleepy)

	//---------------------------------------------------------------------------------------------TEST-------------------------------------------------------------------------------

	//Example line for parsing
	char line[] = "2015-05-13 23:53:00,WARRANTS,WARRANT ARREST,Wednesday,NORTHERN,\"ARREST, BOOKED\",OAK ST / LAGUNA ST,-122.425891675136,37.7745985956747";
	//Regex for parsing. This looks for commas ONLY IF there´s an even number of " after it. This means that if there is only 1 comma it wont parse, else if there is 0,2... it will. (since "Arrest, BOOKED" is one field and if not considering this it would be 2.
	char regex[] = ",(?=(?:[^']*'[^']*')*[^']*$)";
	//Hold a reference for the next token
	char *nextToken = NULL;
	
	//Split the string in a set of tokens 
	char* tokens = strtok_s(line, regex, &nextToken);
	while (tokens != NULL) { //Iterate on them and print
		std::cout << tokens << std::endl;

		tokens = strtok_s(NULL, regex, &nextToken);
	}

	//Pause the console (ask for a char)
	std::cin.get();

    return 0;
}