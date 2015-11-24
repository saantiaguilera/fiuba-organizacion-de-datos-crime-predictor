// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <istream>
#include <vector>
#include <sstream>
#include <chrono>

#define kMinLatitude 37.7074870000000
#define kMaxLatitude 37.8126370000000
#define kMinLongitude -122.3568150000000
#define kMaxLongitude -122.5153430000000

#define kSanFranciscoMatrixRowNumber 40
#define kSanFranciscoMatrixColNumber 35

enum DayTime { DAY_FROM_WEEK = 0, DAY_FROM_WEEKEND = 1 };
enum WorkingDuty { WORKING_DUTY = 0, WORKING_DUTY_OFF = 1 };

//#define CASES_TO_PREDICT 200
//#define CASES_TO_PARSE 5000

//40 - 35 -> 71%
