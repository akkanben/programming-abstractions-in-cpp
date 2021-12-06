/* Programming Abstractions in C++
 *
 * Exercise 06-05
 *
 * Extend the calendar.h interface from Chapter 2, exercise 11 so that it also
 * exports a Date class that exports the following methods:
 *
 *  • A default constructor that sets the date to January 1, 1900.
 *  • A constructor that takes a month, day, and year and initializes the Date
 * to contain those values. For example, the declaration
 *
 *      Date moonLanding(JULY, 20, 1969);
 *
 *    should initialize moonLanding so that it represents July 20, 1969.
 *
 *  • An overloaded version of the constructor that takes the first two
 * parameters in the opposite order, for the benefit of clients in other parts
 * of the world. This change allows the declaration of moonLanding to be written
 * as Date moonLanding(20, JULY, 1969);
 *
 *  • The getter methods getDay, getMonth, and getYear.
 *
 *  • A toString method that returns the date in the form dd-mmm -yyyy,
 *    where dd is a one- or two-digit date, mmm is the three-letter English
 *    abbreviation for the month, and yyyy is the four-digit year. Thus, calling
 *    toString(moonLanding) should return the string "20-Jul-1969".
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "Calendar.h"

int main() {
  Date moonLanding(JULY, 20, 1969);
  Date humanInSpace(12, APRIL, 1961);
  std::cout << "Important Dates in Human Space History:" << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  std::cout << humanInSpace.toString() << ": First human in space."
            << std::endl;
  std::cout << moonLanding.toString() << ": First human on the moon."
            << std::endl;
  return 0;
}
