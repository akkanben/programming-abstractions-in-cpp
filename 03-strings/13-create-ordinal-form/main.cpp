/* Programming Abstractions in C++
 *
 * Exercise 03-13
 *
 * Like most other languages, English include two types of numbers.
 *
 * The cardinal numbers (such as one, two, three, and four) are used in counting
 *
 * The ordinal numbers (such as first, second, third, and fourth) are used to
 * indicate a position in a sequence.
 *
 * In text, ordinals are usually indicated by writing the digits in the number,
 * followed by the last two letters of the English word that names the
 * corresponding ordinal. Thus, the ordinal numbers first, second, third, and
 * fourth often appear in print as 1st, 2nd, 3rd, and 4th. The ordinals for 11,
 * 12, and 13, however, are 11th, 12th, and 13th.
 *
 * Devise a rule that determines what suffix should be added to each number, and
 * then use this rule to write a function createOrdinalForm(n) that returns the
 * ordinal form of the number n as a string.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

std::string createOrdinalForm(int n);

int main() {
  for (int i = 1; i <= 100; i++) {
    std::cout << createOrdinalForm(i) << std::endl;
  }
  return 0;
}
std::string createOrdinalForm(int n) {
  if (n % 100 == 11 || n % 100 == 12 || n % 100 == 13) {
    return std::to_string(n) + "th";
  }
  switch (n % 10) {
  case 1:
    return std::to_string(n) + "st";
  case 2:
    return std::to_string(n) + "nd";
  case 3:
    return std::to_string(n) + "rd";
  default:
    return std::to_string(n) + "th";
  }
}
