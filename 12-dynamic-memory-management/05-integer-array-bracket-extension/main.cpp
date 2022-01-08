/* Programming Abstractions in C++
 *
 * Exercise 12-05
 *
 * You can make the IntArray class from the preceding exercise look a little
 * more like traditional arrays by overriding the bracket-selection operator,
 * which has the following prototype:
 *
 *  int & operator[](int k);
 *
 * Like the get and put methods, your implementation of operator[] should
 * check to make sure that the index k is valid. If it is, the operator[] method
 * should return the element by reference so that clients can assign a new value
 * to a selection expression.
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
  std::cout << "IntArray unit test succeeded." << std::endl;
  return 0;
}
