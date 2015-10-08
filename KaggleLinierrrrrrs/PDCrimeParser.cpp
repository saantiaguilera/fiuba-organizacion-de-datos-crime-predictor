#include "stdafx.h"
#include "PDCrimeParser.h"
#include "Crime.h"

#define rgxCsv ",(?=([^\"]*\"[^\"]*\")*[^\"]*$)"

//Line eg: 2015-05-13 23:53:00,WARRANTS,WARRANT ARREST,Wednesday,NORTHERN,"ARREST, BOOKED",OAK ST / LAGUNA ST,-122.425891675136,37.7745985956747

//Regex for parsing. This looks for commas ONLY IF there´s an even number of " after it. This means that if there is only 1 comma it wont parse, else if there is 0,2... it will. (since "Arrest, BOOKED" is one field and if not considering this it would be 2.
//Information about regex (used for this): https://msdn.microsoft.com/en-us/library/f97kw5ka.aspx?f=255&MSPPError=-2147217396
std::regex rgx(rgxCsv);

//Since I cant do a iter != NULL I create a NULL var of it.
std::sregex_token_iterator end;

PDCrimeParser::PDCrimeParser()
{
}

PDCrimeParser::~PDCrimeParser()
{

}

Crime* PDCrimeParser::createCrimeFromCSVChunk(const std::string & dataChunk) {
	//Create a token iterator from start to end of string, using the regex. The -1 is for making the iterator point to the text that precede the match.
	std::sregex_token_iterator iter(dataChunk.begin(), dataChunk.end(), rgx, -1);
	//Go one by one getting it? (Maybe doing a vector and then passing to a constructor, but this should be more efficient since we know the csv structure (we are not doing anything generic here).
	std::string date = *iter;
	++iter;

	std::string category = *iter;
	++iter;

	std::string descript = *iter;
	++iter;

	std::string dayOfWeek = *iter;
	++iter;

	std::string pdDistrict = *iter;
	++iter;

	std::string resolution = *iter;
	++iter;

	std::string address = *iter;
	++iter;

	double longitude = std::stod(*iter);
	++iter;

	double latitude = std::stod(*iter);
	
	return new Crime(date, category, descript, dayOfWeek, pdDistrict, resolution, address, longitude, latitude);
}

bool PDCrimeParser::readFile()
{
	//This should be done to get the whole csv. We should create an object and go storing them bla bla ya lo pensamos todo esto.
	//http://en.cppreference.com/w/cpp/language/string_literal for R as raw delimiter
	//Chano route: (C:\Chano\train.csv)
	//Santia route: (C:\Users\Saantii\Desktop\Kagle\train.csv\train.csv)
	std::ifstream file(R"(C:\Users\Saantii\Desktop\Kagle\train.csv\train.csv)");

	//Just for testing purposes. dont want to be iterating infinite times now. Should be removed (and everything about i).
	int i = 0;

	//If the file is malformed, doesnt exists, by some reason its not available for reading or whatsoever, return 1.
	if (file.good()) {
		//Init variables we will be using in the loop
		std::string currentLine;

		//First line is  the row indicator, skip it.
		std::getline(file, currentLine);

		//Iterate over each line of the file (and, for testing purposes, only the first 5 of them)
		while (std::getline(file, currentLine) && i<5) {
			//create a Crime from the chunk we init before and print the values we got.
			Crime* crime = createCrimeFromCSVChunk(currentLine);

			crime->printValues();

			i++;
		}
	} else return false;

	return true;
}
