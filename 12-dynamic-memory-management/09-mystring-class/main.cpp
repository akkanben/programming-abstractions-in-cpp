/* Programming Abstractions in C++
 *
 * Exercise 12-09
 *
 * Even though programmers tend to think of strings as relatively simple
 * entities, their implementation turns out to involve the full range of
 * techniques you have seen in this chapter. In this exercise, your mission is
 * to define a class called MyString that approximates the behavior of the
 * string class from the Standard C++ libraries. Your class should export the
 * following methods:
 *
 *  • A constructor MyString(str) that creates a MyString object from a
 *    C++ string.
 *
 *  • A destructor that frees any heap storage allocated by the MyString.
 *
 *  • A toString() method that converts a MyString to a C++ string.
 *
 *  • A method length() that returns the number of characters in the string.
 *
 *  • A method substr(start, n) that returns a substring of the current string
 *    object. As in the library version of the string class, the substring
 *    should begin at the index position start and continue for n characters or
 *    through the end of the string, whichever comes first. The parameter n
 *    should be optional; if it is missing, the substring should always extend
 *    through the end of the original string.
 *
 *  • A redefinition of the operator + that concatenates two MyString objects.
 *    It also makes sense to overload the operator += so that it appends a
 *    character or a string to the end of an existing one.
 *
 *  • A redefinition of the operator << so that MyString objects can be written
 *    to output streams.
 *
 *  • A redefinition of the bracket-selection operator (as described in exercise
 *    5) so that str[i] returns by reference the character at index position i
 *    in str. As an improvement over the string class in the C++ libraries, your
 *    implementation of the bracket operator should call error if the index is
 *    outside the bounds of the string.
 *
 *  • A redefinition of the relational operators ==, !=, <, <=, >, and >= that
 *    compare strings lexicographically.
 *
 *  • A redefinition of the assignment operator and the copy constructor for the
 *    MyString class so that any copying operations make a deep copy that
 *    creates a new character array.
 *
 * Your code should work directly with your underlying representation and
 * should make no calls to any of the methods in the C++ string class. Your
 * interface and implementation should also be const correct so that both
 * clients and the C++ compiler know exactly what methods can change the value
 * of the string.
 *
 * Solution 2021 Ben Mills
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
