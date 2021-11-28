/* Programming Abstractions in C++
 *
 * Exercise 02-08 ALTERNATE i.e. valid any year after 1583 ~ Gregorian calendar
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
 *
 * This algorithm for the alternate version uses the Guass Easter Algorithm
 * found at:
 *
 * http://www.henk-reints.nl/easter/index.htm?frame=easteralg2.htm
 *   A L G O R I T H M :
 *   P = year DIV 100
 *   Q = (3 x P + 3) DIV 4
 *   R = (8 x P + 13) DIV 25
 *   M = (15 + Q - R) MOD 30
 *   N = (4  +  Q) MOD 7
 *   A = year MOD 19
 *   B = year MOD 4
 *   C = year MOD 7
 *   D = (19 x A + M) MOD 30
 *   E = (2 x B + 4 x C + 6 x D + N) MOD 7
 *   F = 22 + D + E
 *   if F = 57 or (F = 56 and E = 6 and A > 10) then F = F - 7
 *   result = F
 */

#include <iostream>

int getYear(int &year);
void findEaster(int year, std::string &month, int &day);

int main() {
  std::string month;
  int day;
  int year;
  while (true) {
    getYear(year);
    if (year > 1583) {
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
  std::cout << "Enter a year after 1583 to calculate Easter: ";
  std::cin >> year;
  return year;
}

void findEaster(int year, std::string &month, int &day) {
  int a, b, c, p, q, r, m, n, d, e, f;
  a = year % 19;
  b = year % 4;
  c = year % 7;
  p = year / 100;
  q = (3 * p + 3) / 4;
  r = (8 * p + 13) / 25;
  m = (15 + q - r) % 30;
  n = (4 + q) % 7;
  d = (19 * a + m) % 30;
  e = (2 * b + 4 * c + 6 * d + n) % 7;
  f = 22 + d + e;
  if (f == 57 || (f == 56 && e == 6 && a > 10))
    f -= 7;
  day = f;
  if (day > 31) {
    month = "April";
    day -= 31;
  } else {
    month = "March";
  }
}
