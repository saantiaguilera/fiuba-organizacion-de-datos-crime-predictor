#pragma once

#include "stdafx.h"
#include <map>

class FileDumper {
private:
	std::ofstream dumpFile;
	std::ostringstream buffer;
	int count;
	void dumpHeaders();
	void addToBuffer(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints);
public:
	FileDumper();
	~FileDumper();
	void dumpPrediction(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints);
	void flushBuffer();
};