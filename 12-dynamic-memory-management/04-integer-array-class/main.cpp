/* Programming Abstractions in C++
 *
 * Exercise 12-04
 *
 * Design and implement a class called IntArray that implements the following
 * methods:
 *
 *  • A constructor IntArray(n) that creates an IntArray object with n
 *    elements, each of which is initialized to 0.
 *
 *  • A destructor that frees any heap storage allocated by the IntArray.
 *
 *  • A method size() that returns the number of elements in the IntArray.
 *
 *  • A method get(k) that returns the element at position k. If k is outside
 *    the vector bounds, get should call error with an appropriate message.
 *
 *  • A method put(k, value) that assigns value to the element at position k.
 *
 *  • As with get, the put method should call error if k is out of bounds.
 *
 * Your solution should be split into separate interface and implementation
 * files in a manner similar to the CharStack example from the chapter. In the
 * initial version of the code, you should add the necessary definitions to the
 * intarray.h file to prevent clients from copying IntArray objects. Design
 * and implement a unit test to check the methods exported by the class.
 *
 * By keeping track of the array size and checking that index values are inside
 * the array bounds, this simple IntArray class already fixes two of the most
 * serious shortcomings of the built-in array type.
 *
 * Solution 2021 Ben Mills
 */

#include <cassert>
#include <iostream>

#include "IntArray.h"

int main() {
  IntArray arr(20);
  assert(arr.size() == 20);
  assert(arr.get(0) == 0);
  assert(arr.get(19) == 0);
  arr.put(0, 255);
  assert(arr.get(0) == 255);
  for (int i = 0; i < arr.size(); i++)
    arr.put(i, i);
  for (int i = 0; i < arr.size(); i++)
    assert(arr.get(i) == i);
  std::cout << "IntArray unit test succeeded." << std::endl;
  return 0;
}
