#pragma once

#include "stdafx.h"
#include <map>

class FileDumper {
private:
	//Output file
	std::ofstream dumpFile;
	//Buffer to store the data temporaly
	std::ostringstream buffer;
	//For flushing when it reaches a certain amount of predictions
	int count;
	//Dumps the initial headers (see define in .cpp)
	void dumpHeaders();
	//Should transform accordingly to the data need to store. Contains the algorythm that makes the percentages for each category
	void addToBuffer(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints);
public:
	//Initializers
	FileDumper();
	~FileDumper();
	//Should transform accordingly to the data need to store. Algorythm for each category is implemented in addToBuffer not here
	void dumpPrediction(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints);
	//Flushes the buffer contents in the file
	void flushBuffer();
};