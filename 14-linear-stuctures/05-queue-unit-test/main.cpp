/* Programming Abstractions in C++
 *
 * Exercise 14-05
 *
 * Devise a similar unit test for the queue.h interface.
 *
 * Solution 2021 Ben Mills
 */

#include "arrayBasedQueue.h"
#include "linkedListsBasedQueue.h"
#include <cassert>
#include <iostream>

int main() {
  // DATA
  char chars[] = {'a', 'c', '$', 'V', 'R', '8', '#', 'd', 'f', 'e', 'w'};
  std::string strings[] = {"hello", "world", "foo", "bar",  "string",  "words",
                           "array", "eight", "hi",  "test", "last one"};
  double doubles[] = {3.14, 4.44, 1.2345,  56.8,  12.1,   1.1111,
                      4.21, 9.22, 8.36928, 382.1, 12983.3};
  int ints[] = {2, 4, 1, 56, 3, 5, 7, 8, 9, 23419, 828282};

  // ARRAY TESTS
  ArrayBasedQueue<char> aQueue1;
  ArrayBasedQueue<std::string> aQueue2;
  ArrayBasedQueue<double> aQueue3;
  ArrayBasedQueue<int> aQueue4;
  for (int i = 0; i < 22; i++) {
    if (i < 11) {
      aQueue1.enqueue(chars[i]);
      aQueue2.enqueue(strings[i]);
      aQueue3.enqueue(doubles[i]);
      aQueue4.enqueue(ints[i]);
      assert(aQueue1.size() == i + 1);
      assert(aQueue2.size() == i + 1);
      assert(aQueue3.size() == i + 1);
      assert(aQueue4.size() == i + 1);
      assert(aQueue1.peek() == chars[aQueue1.size() - i - 1]);
      assert(aQueue2.peek() == strings[aQueue2.size() - i - 1]);
      assert(aQueue3.peek() == doubles[aQueue3.size() - i - 1]);
      assert(aQueue4.peek() == ints[aQueue4.size() - i - 1]);
    } else {
      aQueue1.dequeue();
      aQueue2.dequeue();
      aQueue3.dequeue();
      aQueue4.dequeue();
      if (i == 21) {
        assert(aQueue1.isEmpty());
        assert(aQueue2.isEmpty());
        assert(aQueue3.isEmpty());
        assert(aQueue4.isEmpty());
      }
    }
  }
  std::cout << "Array Based Queue Unit Test Passed." << std::endl;

  // LINKED LIST TESTS
  LinkedListBasedQueue<char> lQueue1;
  LinkedListBasedQueue<std::string> lQueue2;
  LinkedListBasedQueue<double> lQueue3;
  LinkedListBasedQueue<int> lQueue4;
  for (int i = 0; i < 22; i++) {
    if (i < 11) {
      lQueue1.enqueue(chars[i]);
      lQueue2.enqueue(strings[i]);
      lQueue3.enqueue(doubles[i]);
      lQueue4.enqueue(ints[i]);
      assert(lQueue1.size() == i + 1);
      assert(lQueue2.size() == i + 1);
      assert(lQueue3.size() == i + 1);
      assert(lQueue4.size() == i + 1);
      assert(lQueue1.peek() == chars[lQueue1.size() - i - 1]);
      assert(lQueue2.peek() == strings[lQueue2.size() - i - 1]);
      assert(lQueue3.peek() == doubles[lQueue3.size() - i - 1]);
      assert(lQueue4.peek() == ints[lQueue4.size() - i - 1]);
    } else {
      lQueue1.dequeue();
      lQueue2.dequeue();
      lQueue3.dequeue();
      lQueue4.dequeue();
      if (i == 21) {
        assert(lQueue1.isEmpty());
        assert(lQueue2.isEmpty());
        assert(lQueue3.isEmpty());
        assert(lQueue4.isEmpty());
      }
    }
  }
  std::cout << "Linked List Based Queue Unit Test Passed." << std::endl;
  return 0;
}
