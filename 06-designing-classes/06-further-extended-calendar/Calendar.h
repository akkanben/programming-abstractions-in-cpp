#ifndef _calendar_h
#define _calendar_h

#include <string>

enum Month {
  JANUARY = 1,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JUNE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER
};

class Date {
public:
  Date();
  Date(Month m, int d, int y);
  Date(int d, Month m, int y);
  Month getMonth();
  int getDay();
  int getYear();
  std::string toString();
  friend Date operator+(Date d1, Date d2);
  friend Date operator+(Date d1, int numDays);
  friend Date operator-(Date d1, int numDays);
  friend bool operator==(Date d1, Date d2);
  friend bool operator>(Date d1, Date d2);
  friend bool operator<(Date d1, Date d2);
  friend Date operator++(Date &d);
  friend Date operator++(Date &d, int);
  friend Date operator--(Date &d);
  friend Date operator--(Date &d, int);

private:
  Month month;
  int day;
  int year;
};

Date operator+(Date d, int numDays);
Date operator-(Date d, int numDays);
bool operator==(Date d1, Date d2);
bool operator!=(Date d1, Date d2);
bool operator>=(Date d1, Date d2);
bool operator<=(Date d1, Date d2);
bool operator>(Date d1, Date d2);
bool operator<(Date d1, Date d2);
Date operator++(Date &d);
Date operator++(Date &d, int);
Date operator--(Date &d);
Date operator--(Date &d, int);
std::ostream &operator<<(std::ostream &os, Date d);

#endif
