/* Programming Abstractions in C++
 *
 * Exercise
 *
 * Write a recursive function that takes a string as argument and returns the
 * reverse of that string. The prototype for this function should be
 *
 *  string reverse(string str);
 *
 * and the statement
 *
 *  cout << reverse("program") << endl;
 *
 * should display
 *
 *  <image of example run>
 *
 * Your solution should be entirely recursive and should not use any iterative
 * constructs such as while or for.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>
#include <vector>

std::string reverse(std::string str);

int main() {
  std::vector<std::string> words = {"program", "words", "backwards", "racecar",
                                    "recursive"};
  for (int i = 0; i < words.size(); i++) {
    std::cout << words[i] << " ---> " << reverse(words[i]) << std::endl;
  }
  return 0;
}

std::string reverse(std::string str) {
  if (str.length() == 1)
    return str;
  return str[str.length() - 1] + reverse(str.substr(0, str.length() - 1));
}
