/* Programming Abstractions in C++
 *
 * Exercise 10-05
 *
 * Write a program that generates a table comparing the performance of two
 * algorithms—linear and binary search—when used to find a randomly chosen
 * integer key in a sorted Vector<int>. The linear search algorithm simply
 * goes through each element of the vector in turn until it finds the desired
 * one or determines that the key does not appear. The binary search algorithm,
 * which is implemented for string vectors in Figure 7-5, uses a
 * divide-and-conquer strategy by checking the middle element of the vector and
 * then deciding which half of the remaining elements to search.
 *
 * The table you generate in this problem, rather than computing the time as
 * in exercise 3, should instead calculate the number of comparisons made
 * against elements of the vector. To ensure that the results are not completely
 * random, your program should average the results over several independent
 * trials. A sample run of the program might look like this:
 *
 *  <image of trial run>
 *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>

#include "../../StanfordCPPLib/include/random.h"
#include "../../StanfordCPPLib/include/vector.h"

const int LARGEST_INT = 100000;
const int NUM_TRIALS = 25;
enum SearchType { LINEAR, BINARY };

Vector<int> randomVectorOfSize(int size, int max);
void printResults(Vector<int> nSizes, Vector<Vector<double>> results);
int getComparisonCount(Vector<int> &vec, SearchType search);
void runComparisons(Vector<int> nSizes, Vector<Vector<double>> &results);
int binarySearch(int key, Vector<int> &vec, int p1, int p2, int &comparisons);
int linearSearch(int key, Vector<int> &vec, int &comparisons);
void sort(Vector<int> &vec);
void quicksort(Vector<int> &vec, int start, int finish);
int partition(Vector<int> &vec, int start, int finish);

int main() {
  Vector<int> nSizes;
  nSizes += 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000;
  Vector<Vector<double>> results; // index 0 = linear, index 1 = binary
  Vector<double> initialize(nSizes.size());
  results += initialize, initialize;
  runComparisons(nSizes, results);
  printResults(nSizes, results);
  return 0;
}

Vector<int> randomVectorOfSize(int size, int max) {
  Vector<int> output;
  for (int i = 0; i < size; i++) {
    int randomNumber = randomInteger(0, max);
    output.add(randomNumber);
  }
  return output;
}

void runComparisons(Vector<int> nSizes, Vector<Vector<double>> &results) {
  for (int i = 0; i < nSizes.size(); i++) {
    int linearComparisons = 0;
    int binaryComparisons = 0;
    for (int trial = 0; trial < NUM_TRIALS; trial++) {
      Vector<int> vec = randomVectorOfSize(nSizes[i], LARGEST_INT);
      sort(vec);
      linearComparisons += getComparisonCount(vec, LINEAR);
      binaryComparisons += getComparisonCount(vec, BINARY);
    }
    results[0][i] = (double)linearComparisons / (double)NUM_TRIALS;
    results[1][i] = (double)binaryComparisons / (double)NUM_TRIALS;
  }
}

void printResults(Vector<int> nSizes, Vector<Vector<double>> results) {
  std::cout << "    N   |  Linear |  Binary " << std::endl;
  std::cout << "--------+---------+---------" << std::endl;
  for (int i = 0; i < nSizes.size(); i++) {
    std::cout << std::right << std::fixed << std::setprecision(1)
              << std::setw(7) << nSizes[i] << " | " << setw(7) << results[0][i]
              << " | " << setw(6) << results[1][i] << std::endl;
  }
}

int getComparisonCount(Vector<int> &vec, SearchType search) {
  int comparisons = 0;
  int randomKeyIndex = randomInteger(0, vec.size() - 1);
  if (search == LINEAR)
    linearSearch(vec[randomKeyIndex], vec, comparisons);
  else if (search == BINARY)
    binarySearch(vec[randomKeyIndex], vec, 0, vec.size() - 1, comparisons);
  return comparisons;
}

int binarySearch(int key, Vector<int> &vec, int p1, int p2, int &comparisons) {
  comparisons++;
  if (p1 > p2)
    return -1;
  int mid = (p1 + p2) / 2;
  if (key == vec[mid])
    return mid;
  if (key < vec[mid])
    return binarySearch(key, vec, p1, mid - 1, comparisons);
  else
    return binarySearch(key, vec, mid + 1, p2, comparisons);
}

int linearSearch(int key, Vector<int> &vec, int &comparisons) {
  for (int i = 0; i < vec.size(); i++) {
    comparisons++;
    if (vec[i] == key)
      return i;
  }
  return -1;
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
  int pivot = vec[start];
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
