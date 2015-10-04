// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

std::vector<std::string> splitStringMatchingARegex(const std::string & s, std::string rgx_str = "\\s+") {


      std::vector<std::string> elems;

      std::regex rgx (rgx_str);

      std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
      std::sregex_token_iterator end;

      while (iter != end)  {
          //std::cout << "S43:" << *iter << std::endl;
          elems.push_back(*iter);
          ++iter;
      }

      return elems;

}

void printVectorValues(std::vector<std::string> valuesVector) {
	for (std::string field : valuesVector) {
		std::cout << "value : " << field << std::endl;
	}

	std::cout << "Finished reading vector." << std::endl;
}

int main()
{

	//Line eg: 2015-05-13 23:53:00,WARRANTS,WARRANT ARREST,Wednesday,NORTHERN,"ARREST, BOOKED",OAK ST / LAGUNA ST,-122.425891675136,37.7745985956747

	//Regex for parsing. This looks for commas ONLY IF there´s an even number of " after it. This means that if there is only 1 comma it wont parse, else if there is 0,2... it will. (since "Arrest, BOOKED" is one field and if not considering this it would be 2.
	//Information about regex (used for this): https://msdn.microsoft.com/en-us/library/f97kw5ka.aspx?f=255&MSPPError=-2147217396 & https://msdn.microsoft.com/en-us/library/bb982727.aspx?f=255&MSPPError=-2147217396
	std::string regex = ",(?=([^\"]*\"[^\"]*\")*[^\"]*$)";
	
	//This should be done to get the whole csv. We should create an object and go storing them bla bla ya lo pensamos todo esto.
	std::ifstream file(R"(C:\Users\Saantii\Desktop\Kagle\train.csv\train.csv)"); //http://en.cppreference.com/w/cpp/language/string_literal for R as raw delimiter
	int i = 0; //Just for testing purposes. dont want to be iterating infinite times.

	if (file.good()) {

		std::string currentLine;

		while ( std::getline(file, currentLine) && i<5) {
			std::vector<std::string> splittedString = splitStringMatchingARegex(currentLine, regex);

			printVectorValues(splittedString);

			i++;
		}
	}
	/*
	//---------------------------------------------------------------------------------------------TEST-------------------------------------------------------------------------------

	//Example line for parsing
	std::string line = "2015-05-13 23:53:00,WARRANTS,WARRANT ARREST,Wednesday,NORTHERN,\"ARREST, BOOKED\",OAK ST / LAGUNA ST,-122.425891675136,37.7745985956747";
	//Regex for parsing. This looks for commas ONLY IF there´s an even number of " after it. This means that if there is only 1 comma it wont parse, else if there is 0,2... it will. (since "Arrest, BOOKED" is one field and if not considering this it would be 2.
	std::string regex = ",(?=([^\"]*\"[^\"]*\")*[^\"]*$)";
	
	//Split the string in a set of tokens 
	std::vector<std::string> splittedString = splitStringMatchingARegex(line, regex);
	printVectorValues(splittedString);

	//Pause the console (ask for a char)
	*/

	std::cin.get();

    return 0;
}