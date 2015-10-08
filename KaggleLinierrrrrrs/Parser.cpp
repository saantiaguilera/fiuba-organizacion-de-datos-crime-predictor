#include "stdafx.h"
#include "Parser.h"

//Line eg: 2015-05-13 23:53:00,WARRANTS,WARRANT ARREST,Wednesday,NORTHERN,"ARREST, BOOKED",OAK ST / LAGUNA ST,-122.425891675136,37.7745985956747

std::string regex;

Parser::Parser()
{
	//Regex for parsing. This looks for commas ONLY IF there´s an even number of " after it. This means that if there is only 1 comma it wont parse, else if there is 0,2... it will. (since "Arrest, BOOKED" is one field and if not considering this it would be 2.
	//Information about regex (used for this): https://msdn.microsoft.com/en-us/library/f97kw5ka.aspx?f=255&MSPPError=-2147217396
	regex = ",(?=([^\"]*\"[^\"]*\")*[^\"]*$)";
}

Parser::~Parser()
{

}

std::vector<std::string> Parser::splitStringMatchingARegex(const std::string & s, std::string rgx_str)
{
	//Initialize stuff we will need.
	std::vector<std::string> elems;
	std::regex rgx(rgx_str);

	//Create a token iterator from start to end of string, using the regex. The -1 is for making the iterator point to the text that precede the match.
	std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
	//Since I cant do a iter != NULL I create a NULL var of it.
	std::sregex_token_iterator end;

	Crime *crime = new Crime;
	crime->date = *iter;
	++iter;
	crime->category = *iter;
	++iter;
	crime->descript = *iter;
	++iter;
	crime->dayOfWeek = *iter;
	++iter;
	crime->pdDistrict = *iter;
	++iter;
	crime->resolution = *iter;
	++iter;
	crime->address = *iter;
	++iter;
	crime->latitude = std::stod(*iter);
	++iter;
	crime->longitude = std::stod(*iter);

	

	std::cout << "valor: " << crime->date << std::endl;
	std::cout << "valor: " << crime->category << std::endl;
	std::cout << "valor: " << crime->descript << std::endl;
	std::cout << "valor: " << crime->dayOfWeek << std::endl;
	std::cout << "valor: " << crime->pdDistrict << std::endl;
	std::cout << "valor: " << crime->resolution << std::endl;
	std::cout << "valor: " << crime->address << std::endl;
	std::cout << "valor: " << crime->latitude << std::endl;
	std::cout << std::setprecision(20) << crime->latitude << std::endl;
	std::cout << "valor: " << crime->longitude << std::endl;

	delete crime;

	while (iter != end) {
		//Add elements to vector and move iterator
		elems.push_back(*iter);
		++iter;
	}

	return elems;
}

void Parser::printVectorValues(std::vector<std::string> valuesVector)
{
	for (std::string field : valuesVector) {
		std::cout << "value : " << field << std::endl;
	}

	std::cout << "Finished reading vector." << std::endl;
}

bool Parser::readFile()
{
	//This should be done to get the whole csv. We should create an object and go storing them bla bla ya lo pensamos todo esto.
	//http://en.cppreference.com/w/cpp/language/string_literal for R as raw delimiter
	std::ifstream file(R"(C:\Chano\train.csv)");

	//Just for testing purposes. dont want to be iterating infinite times now. Should be removed (and everything about i).
	int i = 0;
	bool isFirstLine = true;

	//If the file is malformed, doesnt exists, by some reason its not available for reading or whatsoever, return 1.
	if (file.good()) {
		//Init variables we will be using in the loop
		std::string currentLine;

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine) && i<2) {

			if (!isFirstLine)
			{
				//Split them using the regex we init before and print the values we got.
				std::vector<std::string> splittedString = splitStringMatchingARegex(currentLine, regex);

				printVectorValues(splittedString);
			}
			else
			{
				isFirstLine = false;
			}
			
			i++;
		}
	}
	else return 1;

	std::cin.get();

	return 0;
}
