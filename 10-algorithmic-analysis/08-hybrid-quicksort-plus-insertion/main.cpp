/* Programming Abstractions in C++
 *
 * Exercise 10-08
 *
 * Another interesting hybrid strategy for the sorting problem is to start with
 * a recursive implementation of Quicksort that simply returns when the size of
 * the vector falls below a certain threshold. When this function returns, the
 * vector is not sorted, but all the elements are relatively close to their
 * final positions. At this point, you can use the insertion sort algorithm
 * presented in exercise 2 on the entire vector to fix any remaining problems.
 * Because insertion sort runs in linear time on vectors that are mostly sorted,
 * you may be able to save some time using this approach.
 *
 * Solution 2021 Ben Mills
 *
 * Example run on my machine:
 * Compairing crossover points for hybrid insertion/quicksort.
 * Readings per crossover test: 1
 * Dataset size: 100000
 *  Crossover | Insertion | Selection
 * -----------+-----------+-----------
 *      10000 |     3.265 |     5.642
 *       5000 |     1.682 |     2.924
 *       2500 |     0.827 |     1.445
 *       1000 |     0.378 |     0.680
 *        750 |     0.319 |     0.575
 *        500 |     0.258 |     0.471
 *        400 |     0.236 |     0.445
 *        300 |     0.241 |     0.459
 *        200 |     0.265 |     0.530
 *        100 |     0.415 |     0.821
 *         50 |     0.729 |     1.454
 *         25 |     1.355 |     2.750
 *         10 |     2.933 |     5.855
 *          5 |     4.791 |     9.515
 */

#include <ctime>
#include <iomanip>
#include <iostream>

#include "../../StanfordCPPLib/include/random.h"
#include "../../StanfordCPPLib/include/vector.h"

const int NUM_READINGS = 10;
const int LARGEST_INT = 100000;
const int VEC_SIZE = 100000;

void hybridInsertionQuickSort(Vector<int> &vec, int start, int finish,
                              int crossover);
void hybridSelectionQuickSort(Vector<int> &vec, int start, int finish,
                              int crossover);
int partition(Vector<int> &vec, int start, int finish);
void insertionSort(Vector<int> &vec, int start, int finish);
void selectionSort(Vector<int> &vec, int start, int finish);
int getMedianIntegerIndex(Vector<int> vec, int a, int b, int c);
Vector<int> randomVectorOfSize(int size, int max);

int main() {
  Vector<int> crossoverSizes;
  crossoverSizes += 10000, 5000, 2500, 1000, 750, 500, 400, 300, 200, 100, 50,
      25, 10, 5;
  std::cout << "Compairing crossover points for hybrid insertion/quicksort."
            << std::endl;
  std::cout << "Readings per crossover test: " << NUM_READINGS << std::endl;
  std::cout << "Dataset size: " << VEC_SIZE << std::endl;
  std::cout << " Crossover | Insertion | Selection " << std::endl;
  std::cout << "-----------+-----------+----------- " << std::endl;
  for (int i = 0; i < crossoverSizes.size(); i++) {
    int reading = 0;
    Vector<Vector<int>> duplicatesA;
    Vector<Vector<int>> duplicatesB;
    // Duplicating the vector NUM_READINGS times.
    while (reading < NUM_READINGS) {
      setRandomSeed(1);
      Vector<int> vec = randomVectorOfSize(VEC_SIZE, LARGEST_INT);
      duplicatesA.add(vec);
      duplicatesB.add(vec);
      reading++;
    }
    reading = 0; // reset after filling duplicates
    std::cout << std::right << std::setw(10) << crossoverSizes[i] << " | ";
    std::cout << fixed;
    double start = double(clock()) / CLOCKS_PER_SEC;
    // Collect, average, and print hybridInsertionQuickSort readings
    while (reading < NUM_READINGS) {
      hybridInsertionQuickSort(duplicatesA[reading], 0,
                               duplicatesA[reading].size() - 1,
                               crossoverSizes[i]);
      reading++;
    }
    double finish = double(clock()) / CLOCKS_PER_SEC;
    double elapsed = (finish - start) / NUM_READINGS; // average of NUM_READINGS
    std::cout << std::setw(9) << std::setprecision(3) << elapsed << " | ";
    // Collect, average, and print hybridSelectionQuickSort readings
    reading = 0; // reset after running Insertion
    while (reading < NUM_READINGS) {
      hybridSelectionQuickSort(duplicatesB[reading], 0,
                               duplicatesB[reading].size() - 1,
                               crossoverSizes[i]);
      reading++;
    }
    finish = double(clock()) / CLOCKS_PER_SEC;
    elapsed = (finish - start) / NUM_READINGS; // average of NUM_READINGS
    std::cout << std::setw(9) << std::fixed << std::setprecision(3) << elapsed
              << std::endl;
  }
  return 0;
}

void hybridInsertionQuickSort(Vector<int> &vec, int start, int finish,
                              int crossover) {
  if (finish - start <= crossover) {
    insertionSort(vec, start, finish);
  } else {
    if (start >= finish)
      return;
    int boundary = partition(vec, start, finish);
    hybridInsertionQuickSort(vec, start, boundary - 1, crossover);
    hybridInsertionQuickSort(vec, boundary + 1, finish, crossover);
  }
}

void hybridSelectionQuickSort(Vector<int> &vec, int start, int finish,
                              int crossover) {
  if (finish - start <= crossover) {
    selectionSort(vec, start, finish);
  } else {
    if (start >= finish)
      return;
    int boundary = partition(vec, start, finish);
    hybridSelectionQuickSort(vec, start, boundary - 1, crossover);
    hybridSelectionQuickSort(vec, boundary + 1, finish, crossover);
  }
}

int partition(Vector<int> &vec, int start, int finish) {
  int mid = (finish - start) / 2 + start;
  int pivotIndex = getMedianIntegerIndex(vec, start, mid, finish);
  int pivot = vec[pivotIndex];
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

// This insertionSort has been adjusted to only sort the specific area from
// "start" to "finish", inclusive.
void insertionSort(Vector<int> &vec, int start, int finish) {
  if (vec.size() <= 1)
    return;
  for (int i = start; i <= finish; i++) {
    int backPosition = i;
    while (backPosition > 0 && vec[backPosition] < vec[backPosition - 1]) {
      int temp = vec[backPosition - 1];
      vec[backPosition - 1] = vec[backPosition];
      vec[backPosition] = temp;
      backPosition--;
    }
  }
}

// This selectionSort has been adjusted to only sort the specific area from
// "start" to "finish", inclusive.
void selectionSort(Vector<int> &vec, int start, int finish) {
  for (int lh = start; lh <= finish; lh++) {
    int rh = lh;
    for (int i = lh + 1; i <= finish; i++) {
      if (vec[i] < vec[rh])
        rh = i;
    }
    int tmp = vec[lh];
    vec[lh] = vec[rh];
    vec[rh] = tmp;
  }
}

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
