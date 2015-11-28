#pragma once

#include "stdafx.h"
#include <map>

class CategoryConstantsManage {
private:
	void createWorkingDutyCategoryMap();
	void createWorkingOffCategoryMap();
	void createWeekDayCategoryMap();
	void createWeekendCategoryMap();
	void createStreetCornerCategoryMap();
	void createStreetNonCornerCategoryMap();
public:
	CategoryConstantsManage();
	~CategoryConstantsManage();
	std::map<std::string, double> workingDutyCategoryConstants;
	std::map<std::string, double> workingOffCategoryConstants;
	std::map<std::string, double> weekDayCategoryConstants;
	std::map<std::string, double> weekendCategoryConstants;
	std::map<std::string, double> streetCornerCategoryConstants;
	std::map<std::string, double> streetNonCornerCategoryConstants;
};
