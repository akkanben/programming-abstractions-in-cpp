/* Programming Abstractions in C++
 *
 * Exercise 02-08
 *
 * Although Euclid’s algorithm for calculating the greatest common divisor is
 * one of the oldest to be dignified with that term, there are other algorithms
 * that date back many centuries. In the Middle Ages, one of the problems that
 * required sophisticated algorithmic thinking was determining the date of
 * Easter, which falls on the first Sunday after the first full moon following
 * the vernal equinox. Given this definition, the calculation involves
 * interacting cycles of the day of the week, the orbit of the moon, and the
 * passage of the sun through the zodiac. Early algorithms for solving this
 * problem date back to the third century and are described in the writings of
 * the eighth-century scholar known as the Venerable Bede. In 1800, the German
 * mathematician Carl Friedrich Gauss published an algorithm for determining the
 * date of Easter that was purely computational in the sense that it relied on
 * arithmetic rather than looking up values in tables. His algorithm—translated
 * directly from the German—appears in Figure 2-18.
 *
 * Write a procedure:
 *
 *   void findEaster(int year, string & month, int & day);
 *
 * that returns the Easter date for year in the reference parameters month and
 * day. Unfortunately, the algorithm in Figure 2-18 only works for years in the
 * 18th and 19th centuries. It is easy, however, to search the web for
 * extensions that work for all years. Once you have completed your
 * implementation of Gauss’s algorithm, undertake the necessary research to find
 * a more general approach.
 *
 * FIG 2-18:
 *
 * I. Divide the number of the year for which one wishes to calculate Easter by
 * 19, by 4, and by 7, and call the remainders of these divisions a, b, and c
 * respectively. If the division is even, set the remainder to 0; the quotients
 * are not taken into account.
 *
 * II. Divide the value 19a + 23 by 30 and call the remainder d.
 *
 * III. Finally, divide 2b + 4c + 6d + 3, or 2b + 4c + 6d + 4, choosing the
 * former for years between 1700 and 1799 and the latter for years between 1800
 * and 1899, by 7 and call the remainder e.
 *
 * Then Easter falls on March 22 + d + e, or when d + e is greater than 9, on
 * April d + e -9.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int getYear(int &year);
void findEaster(int year, std::string &month, int &day); // 1700 to 1899

int main() {
  std::string month;
  int day;
  int year;
  while (true) {
    getYear(year);
    if (year < 1899 && year > 1699) {
      findEaster(year, month, day);
    } else {
      break;
    }
    std::cout << "Easter falls on " << month << " " << day << " in " << year
              << "." << std::endl;
  }
  std::cout << "Date outside range.  Goodbye.";
  return 0;
}

int getYear(int &year) {
  std::cout
      << "Enter a year that is between 1700 and 1899 to calculate Easter: ";
  std::cin >> year;
  return year;
}

void findEaster(int year, std::string &month, int &day) {
  int a, b, c, d, e;
  a = year % 19;
  b = year % 4;
  c = year % 7;
  d = (19 * a + 23) % 30;
  if (year > 1699 && year < 1800) {
    e = (2 * b + 4 * c + 6 * d + 3) % 7;
  } else {
    e = (2 * b + 4 * c + 6 * d + 4) % 7;
  }
  if (d + e < 9) {
    month = "March";
    day = 22 + d + e;
  } else {
    month = "April";
    day = d + e - 9;
  }
}
