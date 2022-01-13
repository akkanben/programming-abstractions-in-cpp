/* Programming Abstractions in C++
 *
 * Exercise 12-11 (labeled as 12-12 in the book skipping 12-11)
 *
 * The Pig Latin program from the preceding exercise is not an adequate test of
 * the MyString class. Design and implement a more comprehensive unit test of
 * the MyString package.
 *
 * Solution 2021 Ben Mills
 *
 * This is basically the same as exercise 12-09 since I wrote all these unit
 * tests when I built the class.
 */

#include <cassert>
#include <iostream>
#include <string>

#include "MyString.h"

int main() {
  MyString a = MyString("a");
  MyString b = MyString("b");
  MyString str1 = MyString("Hello Test");
  MyString str2 = MyString("Goodbye Test");
  assert(str1.substr(6) == str2.substr(8));
  assert(str2.substr(4, 3) == MyString("bye"));
  assert(str1.substr(6).toString() == "Test");
  assert(a.length() == 1);
  assert(str1.length() == 10);
  assert(a.toString() == "a");
  assert(str1.toString() == "Hello Test");
  assert(a + b == MyString("ab"));
  assert((a += str1) == MyString("aHello Test"));
  assert(str2[4] == 'b');
  assert(str2[4] == b[0]);
  assert(a < b);
  assert(a <= b);
  assert(!(a > b));
  assert(!(a >= b));
  assert(!(a == b));
  str1 = str2;
  assert(str1 == str2);
  assert(&str1 != &str2);
  MyString success = MyString("MyString unit test succeeded.");
  std::cout << success << std::endl;
  return 0;
}
