/* Programming Abstractions in C++
 *
 * Exercise 11-07
 *
 * Rewrite the implementation of the merge sort algorithm from Figure 10-3 so
 * that it sorts an array rather than a vector. As in the reimplementation of
 * the selection sort algorithm on page 499, your function should use the
 * prototype
 *
 *  void sort(int array[], int n)
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/random.h"

void sort(int arr[], int n);
void merge(int arr[], int n, int a[], int b[], int aSize, int bSize);
void fillArray(int arr[], int n);
void printArr(int arr[], int n);

int main() {
  int size = 100;
  int arr[size];
  std::cout << "BEFORE: " << std::endl;
  fillArray(arr, size);
  printArr(arr, size);
  sort(arr, size);
  std::cout << std::endl;
  std::cout << "AFTER: " << std::endl;
  printArr(arr, size);
  return 0;
}

void sort(int arr[], int n) {
  if (n <= 1)
    return;
  int a[n];
  int b[n];
  int aSize = 0;
  int bSize = 0;
  for (int i = 0; i < n; i++) {
    if (i < n / 2) {
      a[aSize] = arr[i];
      aSize++;
    } else {
      b[bSize] = arr[i];
      bSize++;
    }
  }
  sort(a, aSize);
  sort(b, bSize);
  n = 0;
  merge(arr, n, a, b, aSize, bSize);
}

void merge(int arr[], int n, int a[], int b[], int aSize, int bSize) {
  int p1 = 0;
  int p2 = 0;
  while (p1 < aSize && p2 < bSize) {
    if (a[p1] < b[p2])
      arr[n++] = a[p1++];
    else
      arr[n++] = b[p2++];
  }
  while (p1 < aSize)
    arr[n++] = a[p1++];
  while (p2 < bSize)
    arr[n++] = b[p2++];
}

void fillArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int random = randomInteger(0, 99);
    arr[i] = random;
  }
}

void printArr(int arr[], int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++) {
    std::cout << " " << arr[i] << ",";
  }
  std::cout << " }" << std::endl;
}
