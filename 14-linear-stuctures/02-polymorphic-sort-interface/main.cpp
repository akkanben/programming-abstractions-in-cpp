/* Programming Abstractions in C++
 *
 * Exercise 14-02
 *
 * Write a sort.h interface that exports a polymorphic version of the sort
 * function that works with any base type that implements the standard
 * relational operators. Your function should use the following prototype:
 *
 *  template <typename ValueType>
 *  void sort(Vector<ValueType> & vec);
 *
 * Your implementation should use the Quicksort algorithm as it appears in
 * Figure 10-9.
 *
 * Solution 2021 Ben Mills
 */

#include <cassert>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/vector.h"
#include "sort.h"

int main() {
  Vector<int> vec1;
  Vector<char> vec2;
  Vector<float> vec3;
  Vector<double> vec4;
  Vector<std::string> vec5;
  Vector<bool> vec6;
  vec1 += 3, 1, 12, 5;
  vec2 += 'D', 'R', 'A', 'Z', 'B';
  vec3 += 2.13, 2.11, 2.10, 1.99;
  vec4 += 5.1234, 5.2345, 5.12345, 5.235;
  vec5 += "bcd", "xyz", "abc", "lmn";
  vec6 += false, true, true, true, false;
  sort(vec1);
  sort(vec2);
  sort(vec3);
  sort(vec4);
  sort(vec5);
  sort(vec6);
  assert(vec1[3] == 12);
  assert(vec2[0] == 'A');
  assert(vec3[3] == (float)2.13);
  assert(vec4[1] == 5.12345);
  assert(vec5[0] == "abc");
  assert(vec6[4] == true);
  std::cout << "Sort template interface unit test succeeded." << std::endl;
  return 0;
}
