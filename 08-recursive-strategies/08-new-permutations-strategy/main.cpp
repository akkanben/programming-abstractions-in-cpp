/* Programming Abstractions in C++
 *
 * Exercise
 *
 * The recursive decomposition presented in section 8-3 to solve the problem of
 * generating permutations is not the only effective strategy. Another way to
 * look at the problem is to solve the recursive case looks like this:
 *
 *  a)  Remove the first character from the string and store it in the variable
 *      ch.
 *  b)  Generate the set containing all permutations of the remaining
 *      characters.
 *  c)  Form a new set by inserting ch in every possible position in each of
 *      those permutations.
 *
 *  Reimplement the Permutations program so that it uses this new strategy.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/set.h"
#include "../../StanfordCPPLib/include/simpio.h"

Set<std::string> generatePermutations(std::string str);

int main() {
  std::string str = getLine("Enter a string: ");
  std::cout << "The permutaions of \"" << str << "\" are:" << std::endl;
  foreach (std::string s in generatePermutations(str)) {
    cout << "  \"" << s << "\"" << std::endl;
  }
  return 0;
}

Set<std::string> generatePermutations(std::string str) {
  Set<std::string> result;
  if (str == "") {
    result += "";
  } else {
    char ch = str[0];
    string rest = str.substr(1);
    foreach (std::string s in generatePermutations(rest)) {
      for (int i = 0; i < str.length(); i++) {
        result += s.substr(0, i) + ch + s.substr(i);
      }
    }
  }
  return result;
}
