/* Programming Abstractions in C++
 *
 * Exercise 14-06
 *
 * Because the ring-buffer implementation of queues makes it impossible to tell
 * the difference between an empty queue and one that is completely full, the
 * capacity of the queue is one less than the allocated size of the array. You
 * can avoid this restriction by changing the internal representation so that
 * the concrete structure of the queue keeps track of the number of elements in
 * the queue instead of the index of the tail element. Given the index of the
 * head element and the number of data values in the queue, you can easily
 * calculate the tail index, which means that you don’t need to store this value
 * explicitly. Rewrite the array-based queue representation so that it uses this
 * representation.
 *
 * Solution 2021 Ben Mills
 *
 * I'm using the same unit test here to verify the new representation.
 */

#include "arrayBasedQueue.h"
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
  std::cout << "Adjusted Ring-Buffer Array Based Queue Unit Test Passed."
            << std::endl;
  return 0;
}
