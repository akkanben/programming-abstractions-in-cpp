#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "../../StanfordCPPLib/include/strlib.h"
#include "Calendar.h"

int daysInMonth(Month m, int y);
bool isLeapYear(int y);
std::string monthToString(Month m);
int monthToInt(Month m);
Month intToMonth(int num);

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

// Operator overloads
Date operator++(Date &d) {
  Date output = d;
  if (d.day < daysInMonth(d.month, d.year)) {
    d.day += 1;
  } else if (monthToInt(d.getMonth()) < 12) {
    Month newMonth = intToMonth(monthToInt(d.month) + 1);
    d.month = newMonth;
    d.day = 1;
  } else {
    d.day = 1;
    d.month = JANUARY;
    d.year += 1;
  }
  return output;
}

Date operator++(Date &d, int) {
  if (d.day < daysInMonth(d.month, d.year)) {
    d.day += 1;
  } else if (monthToInt(d.getMonth()) < 12) {
    Month newMonth = intToMonth(monthToInt(d.month) + 1);
    d.month = newMonth;
    d.day = 1;
  } else {
    d.day = 1;
    d.month = JANUARY;
    d.year += 1;
  }
  return d;
}

Date operator--(Date &d) {
  Date output = d;
  if (d.getDay() > 1) {
    d.day -= 1;
  } else if (monthToInt(d.getMonth()) > 1) {
    Month newMonth = intToMonth(monthToInt(d.month) - 1);
    d.month = newMonth;
    d.day = daysInMonth(newMonth, d.year);
  } else {
    d.day = 31;
    d.month = DECEMBER;
    d.year -= 1;
  }
  return output;
}

Date operator--(Date &d, int) {
  if (d.getDay() > 1) {
    d.day -= 1;
  } else if (monthToInt(d.getMonth()) > 1) {
    Month newMonth = intToMonth(monthToInt(d.month) - 1);
    d.month = newMonth;
    d.day = daysInMonth(newMonth, d.year);
  } else {
    d.day = 31;
    d.month = DECEMBER;
    d.year -= 1;
  }
  return d;
}

Date operator+(Date d, int numDays) {
  Date output = d;
  for (int i = 0; i < numDays; i++) {
    output++;
  }
  return output;
}

Date operator-(Date d, int numDays) {
  Date output = d;
  for (int i = 0; i < numDays; i++) {
    output--;
  }
  return output;
}

bool operator==(Date d1, Date d2) {
  return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
}

bool operator!=(Date d1, Date d2) { return d1 == d2 ? false : true; }

bool operator>(Date d1, Date d2) {
  if (d1.year > d2.year)
    return true;
  else if (d1.month > d2.month)
    return true;
  else if (d1.day > d2.day)
    return true;
  return false;
}

bool operator<(Date d1, Date d2) {
  if (d1.year < d2.year)
    return true;
  else if (d1.month < d2.month)
    return true;
  else if (d1.day < d2.day)
    return true;
  return false;
}

bool operator>=(Date d1, Date d2) { return d1 == d2 || d1 > d2 ? true : false; }

bool operator<=(Date d1, Date d2) { return d1 == d2 || d1 < d2 ? true : false; }

std::ostream &operator<<(std::ostream &os, Date d) {
  return os << d.toString();
}

// FREE FUNCTIONS

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
  case DECEMBER:
    return "DECEMBER";
  default:
    return "JANUARY";
  }
}

int monthToInt(Month month) {
  switch (month) {
  case JANUARY:
    return 1;
  case FEBRUARY:
    return 2;
  case MARCH:
    return 3;
  case APRIL:
    return 4;
  case MAY:
    return 5;
  case JUNE:
    return 6;
  case JULY:
    return 7;
  case AUGUST:
    return 8;
  case SEPTEMBER:
    return 9;
  case OCTOBER:
    return 10;
  case NOVEMBER:
    return 11;
  case DECEMBER:
    return 12;
  default:
    return 1;
  }
}

Month intToMonth(int num) {
  switch (num) {
  case 1:
    return JANUARY;
  case 2:
    return FEBRUARY;
  case 3:
    return MARCH;
  case 4:
    return APRIL;
  case 5:
    return MAY;
  case 6:
    return JUNE;
  case 7:
    return JULY;
  case 8:
    return AUGUST;
  case 9:
    return SEPTEMBER;
  case 10:
    return OCTOBER;
  case 11:
    return NOVEMBER;
  case 12:
    return DECEMBER;
  default:
    return JANUARY;
  }
}
