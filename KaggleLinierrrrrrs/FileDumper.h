#pragma once

#include "stdafx.h"
#include <map>

class FileDumper {
private:
	FILE* dumpFile;
	std::stringstream buffer;
	int count;
	void dumpHeaders();
	void flushBuffer();
	void addToBuffer(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints);
public:
	FileDumper();
	~FileDumper();
	void dumpPrediction(std::string& id, std::map<std::string, long double>& pointsMap, long double& totalPoints);
};