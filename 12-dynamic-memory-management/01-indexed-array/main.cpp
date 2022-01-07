/* Programming Abstractions in C++
 *
 * Exercise 12-01
 *
 * Write a function createIndexArray(n) that allocates a dynamic array of n
 * integers in which each integer is initialized to its own index. For example,
 * calling createIndexArray(8) should return a pointer to the following array
 * on the heap:
 *
 *  <image of array[8] with indexes 0-7 filled with matching integers>
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

const int SIZE = 15;

int *createIndexArray(int n);

int main() {
  int *arr = createIndexArray(SIZE);
  for (int i = 0; i < SIZE; i++) {
    std::cout << arr[i] << " at " << &arr[i] << std::endl;
  }
  delete[] arr;
  return 0;
}

int *createIndexArray(int n) {
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  return arr;
}
