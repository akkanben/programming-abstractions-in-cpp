#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "../../StanfordCPPLib/include/strlib.h"
#include "Calendar.h"

int daysInMonth(Month month, int year) {
  switch (month) {
  case APRIL:
  case JUNE:
  case SEPTEMBER:
  case NOVEMBER:
    return 30;
  case FEBRUARY:
    return (isLeapYear(year)) ? 29 : 28;
  default:
    return 31;
  }
}

bool isLeapYear(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

std::string monthToString(Month month) {
  switch (month) {
  case JANUARY:
    return "JANUARY";
  case FEBRUARY:
    return "FEBRUARY";
  case MARCH:
    return "MARCH";
  case APRIL:
    return "APRIL";
  case MAY:
    return "MAY";
  case JUNE:
    return "JUNE";
  case JULY:
    return "JULY";
  case AUGUST:
    return "AUGUST";
  case SEPTEMBER:
    return "SEPTEMBER";
  case OCTOBER:
    return "OCTOBER";
  case NOVEMBER:
    return "NOVEMBER";
  default:
    return "DECEMBER";
  }
}

Date::Date() {
  month = JANUARY;
  day = 1;
  year = 1900;
}

Date::Date(Month m, int d, int y) {
  month = m;
  day = d;
  year = y;
}

Date::Date(int d, Month m, int y) {
  day = d;
  month = m;
  year = y;
}

Month Date::getMonth() { return month; }

int Date::getDay() { return day; }

int Date::getYear() { return year; }

std::string Date::toString() {
  std::string monthStr = monthToString(month);
  monthStr = (monthStr[0]) + toLowerCase(monthStr.substr(1, 2));
  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << day;
  return ss.str() + "-" + monthStr + "-" + integerToString(year);
}
