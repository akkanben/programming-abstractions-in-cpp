/* Programming Abstractions in C++
 *
 * Exercise 06-06
 *
 * Extend the calendar.h interface still further by adding overloaded versions
 * of the following operators:
 *
 *  • The insertion operator <<.
 *  • The relational operators ==, !=, <, <=, >, and >=
 *  • The expression date + n, which returns the date n days after date
 *  • The expression date - n, which returns the date n days before date
 *  • The expression d1 - d2, which returns how many days separate d1 and d2
 *  • The shorthand assignment operators += and -= with an integer on the right
 *  • The ++ and -- operators in both their prefix and suffix form.
 *
 * Suppose, for example, that you have made the following definitions:
 *
 *  Date electionDay(6, NOVEMBER, 2012);
 *  Date inaugurationDay(21, JANUARY, 2013);
 *
 * Given these values of the variables, electionDay < inaugurationDay is
 * true because electionDay comes before inaugurationDay. Evaluating
 * inaugurationDay - electionDay returns 76, which is the number of days
 * between the two events. The definitions of these operators, moreover, allow
 * you to write a for loop like
 *
 *  for (Date d = electionDay; d <= inaugurationDay; d++)
 *
 * that cycles through each of these days, including both endpoints.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "Calendar.h"

int main() {
  Date electionDay(6, NOVEMBER, 2012);
  Date inaugurationDay(21, JANUARY, 2013);
  for (Date d = electionDay; d <= inaugurationDay; d++) {
    std::cout << d.toString() << std::endl;
  }
  std::cout << "-----------" << std::endl;
  for (Date e = inaugurationDay; e >= electionDay; e--) {
    std::cout << e.toString() << std::endl;
  }
  return (0);
}
