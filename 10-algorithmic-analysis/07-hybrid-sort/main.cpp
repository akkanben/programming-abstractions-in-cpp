/* Programming Abstractions in C++
 *
 * Exercise 10-07
 *
 * Although O(N log N ) sorting algorithms are clearly more efficient than
 * O(N^2) algorithms for large vectors, the simplicity of quadratic algorithms
 * like selection sort often means that they perform better for small values of
 * N. This fact raises the possibility of developing a strategy that combines
 * the two algorithms, using Quicksort for large vectors but selection sort
 * whenever the vectors become less than some threshold called the crossover
 * point. Approaches that combine two different algorithms to exploit the best
 * features of each are called hybrid strategies.
 *
 * Reimplement sort using a hybrid of the Quicksort and selection sort
 * strategies. Experiment with different values of the crossover point below
 * which the implementation chooses to use selection sort, and determine what
 * value gives the best performance. The value of the crossover point depends on
 * the specific timing characteristics of your computer and will change from
 * system to system.
 *
 * Solution 2021 Ben Mills
 *
 * Example run on my machine:
 *
 * Compairing crossover points for hybrid quick sort.
 * Readings per crossover test: 10
 * Dataset size: 100000
 * Crossover at 50000 --> 14.4
 * Crossover at 25000 --> 5.81
 * Crossover at 10000 --> 2.38
 * Crossover at 7500  --> 1.7
 * Crossover at 5000  --> 1.25
 * Crossover at 2500  --> 0.629
 * Crossover at 1000  --> 0.299
 * Crossover at 750   --> 0.25
 * Crossover at 600   --> 0.235
 * Crossover at 550   --> 0.218
 * Crossover at 500   --> 0.214
 * Crossover at 450   --> 0.21
 * Crossover at 400   --> 0.208
 * Crossover at 350   --> 0.212
 * Crossover at 300   --> 0.219
 * Crossover at 250   --> 0.229
 * Crossover at 200   --> 0.253
 * Crossover at 100   --> 0.406
 * Crossover at 50    --> 0.729
 * Crossover at 10    --> 2.89
 * Crossover at 5     --> 4.74
 * Crossover at 2     --> 7.82
 *
 * It appears that a crossover point of about 400 in the sweet spot for my
 * computer. See exercise 10-06 for more details on the median quicksort used in
 * this hybrid quicksort.
 *
 */

#include <ctime>
#include <iomanip>
#include <iostream>

#include "../../StanfordCPPLib/include/random.h"
#include "../../StanfordCPPLib/include/vector.h"

const int NUM_READINGS = 10;
const int LARGEST_INT = 100000;
const int VEC_SIZE = 100000;

void sort(Vector<int> &vec, int crossover);
void hybridQuickSort(Vector<int> &vec, int start, int finish, int crossover);
int partition(Vector<int> &vec, int start, int finish);
void selectionSort(Vector<int> &vec, int start, int finish);
int getMedianIntegerIndex(Vector<int> vec, int a, int b, int c);
Vector<int> randomVectorOfSize(int size, int max);

int main() {
  Vector<int> crossoverSizes;
  crossoverSizes += 50000, 25000, 10000, 7500, 5000, 2500, 1000, 750, 600, 550,
      500, 450, 400, 350, 300, 250, 200, 100, 50, 10, 5, 2;
  std::cout << "Compairing crossover points for hybrid quick sort."
            << std::endl;
  std::cout << "Readings per crossover test: " << NUM_READINGS << std::endl;
  std::cout << "Dataset size: " << VEC_SIZE << std::endl;
  for (int i = 0; i < crossoverSizes.size(); i++) {
    int reading = 0;
    Vector<Vector<int>> duplicates;
    // Duplicating the vector NUM_READINGS times.
    while (reading < NUM_READINGS) {
      setRandomSeed(1);
      Vector<int> vec = randomVectorOfSize(VEC_SIZE, LARGEST_INT);
      duplicates.add(vec);
      reading++;
    }
    reading = 0; // reset after filling duplicates
    double start = double(clock()) / CLOCKS_PER_SEC;
    while (reading < NUM_READINGS) {
      sort(duplicates[reading], crossoverSizes[i]);
      reading++;
    }
    double finish = double(clock()) / CLOCKS_PER_SEC;
    double elapsed = (finish - start) / NUM_READINGS; // average of NUM_READINGS
    std::cout << "Crossover at " << std::left << std::setw(5)
              << crossoverSizes[i] << " --> " << std::setw(5)
              << std::setprecision(3) << elapsed << std::endl;
  }
  return 0;
}

void sort(Vector<int> &vec, int crossover) {
  hybridQuickSort(vec, 0, vec.size() - 1, crossover);
}

void hybridQuickSort(Vector<int> &vec, int start, int finish, int crossover) {
  if (finish - start <= crossover) {
    selectionSort(vec, start, finish);
  } else {
    if (start >= finish)
      return;
    int boundary = partition(vec, start, finish);
    hybridQuickSort(vec, start, boundary - 1, crossover);
    hybridQuickSort(vec, boundary + 1, finish, crossover);
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
