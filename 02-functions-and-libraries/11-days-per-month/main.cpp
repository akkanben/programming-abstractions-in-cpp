/* Programming Abstractions in C++
 *
 * Exercise 02-11
 *
 * Using the direction.h interface as an example, design and implement a
 * calendar.h interface that exports the Month type from Chapter 1, along with
 * the functions daysInMonth and isLeapYear, which also appear in that
 * chapter. Your interface should also export a monthToString function that
 * returns the constant name for a value of type Month. Test your implementation
 * by writing a main program that asks the user to enter a year and then writes
 * out the number of days in each month of that year, as in the following sample
 * run:
 *
 * Solution 2021 Ben Mills
 */

#include "calendar.h"
#include <iostream>

int main() {
  int year;
  std::cout << "Enter a year: ";
  std::cin >> year;
  for (int i = (int)JANUARY; i <= (int)DECEMBER; i++) {
    std::cout << monthToString((Month)i) << " has "
              << daysInMonth((Month)i, year) << " days" << std::endl;
  }
  return 0;
}
