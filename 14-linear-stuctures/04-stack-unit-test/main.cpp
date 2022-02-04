/* Programming Abstractions in C++
 *
 * Exercise 14-04
 *
 * Develop a reasonably comprehensive unit test for the stack.h interface that
 * tests the operations exported by the Stack class using stacks with several
 * different base types. Use your unit test program to validate both the array-
 * and list-based implementations of the Stack class.
 *
 * Solution 2021 Ben Mills
 */

#include <cassert>
#include <iostream>

#include "arrayBasedStack.h"
#include "linkedListBasedStack.h"

int main() {
  // DATA
  char chars[] = {'a', 'c', '$', 'V', 'R', '8', '#', 'd', 'f', 'e', 'w'};
  std::string strings[] = {"hello", "world", "foo", "bar",  "string",  "words",
                           "array", "eight", "hi",  "test", "last one"};
  double doubles[] = {3.14, 4.44, 1.2345,  56.8,  12.1,   1.1111,
                      4.21, 9.22, 8.36928, 382.1, 12983.3};
  int ints[] = {2, 4, 1, 56, 3, 5, 7, 8, 9, 23419, 828282};

  // ARRAY TESTS
  ArrayBasedStack<char> aStack1;
  ArrayBasedStack<std::string> aStack2;
  ArrayBasedStack<double> aStack3;
  ArrayBasedStack<int> aStack4;
  for (int i = 0; i < 22; i++) {
    if (i < 11) {
      aStack1.push(chars[i]);
      aStack2.push(strings[i]);
      aStack3.push(doubles[i]);
      aStack4.push(ints[i]);
      assert(aStack1.size() == i + 1);
      assert(aStack2.size() == i + 1);
      assert(aStack3.size() == i + 1);
      assert(aStack4.size() == i + 1);
      assert(aStack1.peek() == chars[i]);
      assert(aStack2.peek() == strings[i]);
      assert(aStack3.peek() == doubles[i]);
      assert(aStack4.peek() == ints[i]);
    } else {
      aStack1.pop();
      aStack2.pop();
      aStack3.pop();
      aStack4.pop();
      if (i == 21) {
        assert(aStack1.isEmpty());
        assert(aStack2.isEmpty());
        assert(aStack3.isEmpty());
        assert(aStack4.isEmpty());
      }
    }
  }
  std::cout << "Array Based Stack Unit Test Passed." << std::endl;

  // LINKED LIST TESTS
  LinkedListBasedStack<char> lStack1;
  LinkedListBasedStack<std::string> lStack2;
  LinkedListBasedStack<double> lStack3;
  LinkedListBasedStack<int> lStack4;
  for (int i = 0; i < 22; i++) {
    if (i < 11) {
      lStack1.push(chars[i]);
      lStack2.push(strings[i]);
      lStack3.push(doubles[i]);
      lStack4.push(ints[i]);
      assert(lStack1.size() == i + 1);
      assert(lStack2.size() == i + 1);
      assert(lStack3.size() == i + 1);
      assert(lStack4.size() == i + 1);
      assert(lStack1.peek() == chars[i]);
      assert(lStack2.peek() == strings[i]);
      assert(lStack3.peek() == doubles[i]);
      assert(lStack4.peek() == ints[i]);
    } else {
      lStack1.pop();
      lStack2.pop();
      lStack3.pop();
      lStack4.pop();
      if (i == 21) {
        assert(lStack1.isEmpty());
        assert(lStack2.isEmpty());
        assert(lStack3.isEmpty());
        assert(lStack4.isEmpty());
      }
    }
  }
  std::cout << "Linked List Based Stack Unit Test Passed." << std::endl;
  return 0;
}
