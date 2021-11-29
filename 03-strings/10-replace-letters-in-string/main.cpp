/* Programming Abstractions in C++
 *
 * Exercise 03-10
 *
 * Write a function: string replaceAll(string str, char c1, char c2);
 * that returns a copy of str with every occurrence of c1 replaced by c2.
 *
 * For example, calling replaceAll("nannies", 'n', 'd');
 * should return "daddies".
 *
 * Once you have coded and tested this function, write an overloaded version
 * string replaceAll(string str, string s1, string s2);
 * that replaces all instances of the string s1 with the replacement string s2.
 *
 * Solution 2021 Ben Mills
 *
 * C++ style function overloading is not allowed in JavaScript because it will
 * result in a syntax error identifying that the function has already been
 * declared.
 *
 * For this example however since all characters are strings in JavaScript we
 * can just check for the length of s1 and then treat s1 as either a single
 * letter or a longer string and have two separate aproaches.
 */

#include <iostream>
#include <string>

std::string replaceAll(std::string str, char c1, char c2);

int main() {
  std::cout << "Change all the n\'s in nannies to d\'s: "
            << replaceAll("nannies", 'n', 'd') << std::endl;
  return 0;
}

std::string replaceAll(std::string str, char c1, char c2) {
  std::string output = "";
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == c1) {
      output += c2;
    } else {
      output += str[i];
    }
  }
  return output;
}
