/* Programming Abstractions in C++
 *
 * Exercise 10-06
 *
 * Change the implementation of the Quicksort algorithm so that, instead of
 * picking the first element in the vector as the pivot, the partition function
 * chooses the median of the first, middle, and last elements.
 *
 * Solution 2021 Ben Mills
 *
 * My solution uses the same basic structure as the quicksort in the book.
 * Instead of using the first element in the array as the pivot we find the
 * median as instructed. I tried attemping to keep the pivot in place but ran
 * into issues so I ended up moving the value of the median pivot to the first
 * position in the array just like the book.
 */

#include <iostream>

#include "../../StanfordCPPLib/include/random.h"
#include "../../StanfordCPPLib/include/vector.h"

void sort(Vector<int> &vec);
void quicksort(Vector<int> &vec, int start, int finish);
int partition(Vector<int> &vec, int start, int finish);
int getMedianIntegerIndex(Vector<int> vec, int a, int b, int c);
Vector<int> randomVectorOfSize(int size, int max);

int main() {
  Vector<int> vec = randomVectorOfSize(25, 99);
  std::cout << "Before: " << vec << std::endl;
  sort(vec);
  std::cout << "After : " << vec << std::endl;
  return 0;
}

void sort(Vector<int> &vec) { quicksort(vec, 0, vec.size() - 1); }

void quicksort(Vector<int> &vec, int start, int finish) {
  if (start >= finish)
    return;
  int boundary = partition(vec, start, finish);
  quicksort(vec, start, boundary - 1);
  quicksort(vec, boundary + 1, finish);
}

int partition(Vector<int> &vec, int start, int finish) {
  int mid = (finish - start) / 2 + start;
  int pivotIndex = getMedianIntegerIndex(vec, start, mid, finish);
  int pivot = vec[pivotIndex];
  // Here we are moving the value in the pivot to vec[start]. Doing this leaves
  // the rest of the code the same as the quicksort example in the book.
  if (pivotIndex != start) {
    int temp = vec[start];
    vec[start] = vec[pivotIndex];
    vec[pivotIndex] = temp;
  }
  int lh = start + 1;
  int rh = finish;
  while (true) {
    while (lh < rh && vec[rh] >= pivot)
      rh--;
    while (lh < rh && vec[lh] < pivot)
      lh++;
    if (lh == rh)
      break;
    int tmp = vec[lh];
    vec[lh] = vec[rh];
    vec[rh] = tmp;
  }
  if (vec[lh] >= pivot)
    return start;
  vec[start] = vec[lh];
  vec[lh] = pivot;
  return lh;
}

// There is probably a more elegent way to find the median of 3 integers...
int getMedianIntegerIndex(Vector<int> vec, int a, int b, int c) {
  int index = 0;
  if ((vec[a] >= vec[b] && vec[a] <= vec[c]) ||
      vec[a] <= vec[b] && vec[a] >= vec[c])
    index = a;
  if ((vec[b] >= vec[a] && vec[b] <= vec[c]) ||
      vec[b] <= vec[a] && vec[b] >= vec[c])
    index = b;
  if ((vec[c] >= vec[a] && vec[c] <= vec[b]) ||
      vec[c] <= vec[a] && vec[c] >= vec[b])
    index = c;
  return index;
}

Vector<int> randomVectorOfSize(int size, int max) {
  Vector<int> output;
  for (int i = 0; i < size; i++) {
    int randomNumber = randomInteger(0, max);
    output.add(randomNumber);
  }
  return output;
}
