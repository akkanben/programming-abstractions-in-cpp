/* Programming Abstractions in C++
 *
 * Exercise 12-06
 *
 * Implement deep copying for the IntArray class from exercises 4 and 5.
 *
 * Solution 2021 Ben Mills
 */

#include <cassert>
#include <iostream>

#include "IntArray.h"

int main() {
  IntArray arr(20);
  assert(arr.size() == 20);
  assert(arr[0] == 0);
  assert(arr[19] == 0);
  arr.put(0, 255);
  assert(arr.get(0) == 255);
  assert(arr[0] == 255);
  for (int i = 0; i < arr.size(); i++)
    arr.put(i, i);
  for (int i = 0; i < arr.size(); i++)
    assert(arr.get(i) == i);
  for (int i = 0; i < arr.size(); i++)
    assert(arr[i] == i);
  IntArray arr2 = arr;
  for (int i = 0; i < arr2.size(); i++)
    assert(arr2[i] == i);
  std::cout << &arr << " & " << &arr2 << std::endl;
  std::cout << "IntArray unit test succeeded." << std::endl;
  return 0;
}
