#pragma once

#include "stdafx.h"
#include <map>

class CategoryConstantsManage {
private:
	void createWorkingDutyCategoryMap();
	void createWorkingOffCategoryMap();
	void createWeekDayCategoryMap();
	void createWeekendCategoryMap();
public:
	CategoryConstantsManage();
	~CategoryConstantsManage();
	std::map<std::string, float> workingDutyCategoryConstants;
	std::map<std::string, float> workingOffCategoryConstants;
	std::map<std::string, float> weekDayCategoryConstants;
	std::map<std::string, float> weekendCategoryConstants;
};
