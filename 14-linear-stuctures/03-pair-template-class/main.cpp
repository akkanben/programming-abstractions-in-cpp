/* Programming Abstractions in C++
 *
 * Exercise 14-03
 *
 * Design and implement a template class Pair<T1,T2> that represents a pair of
 * values, the first of type T1 and the second of type T2. The Pair class should
 * export the following methods:
 *
 *  • A default constructor that generates a pair whose values are the default
 *    values for the types T1 and T2.
 *  • A constructor Pair(v1, v2) that takes explicit values of the two types.
 *  • Getter methods first and second that return copies of the stored values.
 *
 * Solution 2021 Ben Mills
 */
#include <iostream>

#include "pair.h"

int main() {
  Pair<int, char> *defaultValues = new Pair<int, char>();
  Pair<int, char> *explicitValues = new Pair<int, char>(123, 'Z');
  std::cout << "Default value: " << defaultValues->getFirst() << std::endl;
  std::cout << "Default value: " << defaultValues->getSecond() << std::endl;
  std::cout << "Explicit value: " << explicitValues->getFirst() << std::endl;
  std::cout << "Explicit value: " << explicitValues->getSecond() << std::endl;
  return 0;
}
