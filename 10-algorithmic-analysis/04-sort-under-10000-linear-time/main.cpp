/* Programming Abstractions in C++
 *
 * Exercise 10-04
 *
 * Suppose you know that all the values in an integer array fall into the range
 * 0 to 9999. Show that it is possible to write a O (N ) algorithm to sort
 * arrays with this restriction. Implement your algorithm and evaluate its
 * performance by taking empirical measurements using the strategy outlined in
 * exercise 3. Explain why the performance of the algorithm is so bad for small
 * values of N.
 *
 * Solution 2021 Ben Mills
 *
 * If we know that the vector contains integers from 0 to 9999, we can sort in
 * linear time by just using another vector that has 10000 indexes and count the
 * number of times a number shows up in the sorting vector. The times for
 * low N counts are not as low as other sorts due to the added overhead of
 * iterating 10,000 indexes even if we're only using 10.
 *
 */

#include <ctime>
#include <iomanip>
#include <iostream>

#include "../../StanfordCPPLib/include/random.h"
#include "../../StanfordCPPLib/include/vector.h"

Vector<int> randomVectorOfSize(int size, int max);
void sort(Vector<int> &vec);
void quicksort(Vector<int> &vec, int start, int finish);
int partition(Vector<int> &vec, int start, int finish);

int main() {
  Vector<int> nSizes;
  nSizes += 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000;
  std::cout << "    N      |  Time (msec)  " << std::endl;
  std::cout << "-----------+---------------" << std::endl;
  for (int i = 0; i < nSizes.size(); i++) {
    Vector<int> vec = randomVectorOfSize(nSizes[i], 9999);
    // Repeating the smaller numbers 1000 times and divide the time by 1000 to
    // get a more accurate time.
    if (i < 2) {
      double start = double(clock()) / CLOCKS_PER_SEC;
      for (int j = 0; j < 1000; j++) {
        sort(vec);
      }
      double finish = double(clock()) / CLOCKS_PER_SEC;
      double elapsed = finish - start;
      elapsed /= 1000;
      std::cout << std::fixed << std::right << std::setw(9) << nSizes[i]
                << "  |  " << setw(10) << elapsed << std::endl;
    } else {

      double start = double(clock()) / CLOCKS_PER_SEC;
      sort(vec);
      double finish = double(clock()) / CLOCKS_PER_SEC;
      double elapsed = finish - start;
      std::cout << std::fixed << std::right << std::setw(9) << nSizes[i]
                << "  |  " << setw(10) << elapsed << std::endl;
    }
  }
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

void sort(Vector<int> &vec) {
  Vector<int> counts(10000);
  // First for loop increments the value at the index that matches our current
  // location in the Vector.
  for (int i = 0; i < vec.size(); i++) {
    counts[vec[i]]++;
  }
  int pos = 0;
  // Second for loop adds any index number in the counts vector that has a value
  // higher than 0 (and adds multiple if there are more than 1).
  for (int i = 0; i < counts.size(); i++) {
    while (counts[i] > 0) {
      vec[pos] = i;
      counts[i]--;
      pos++;
    }
  }
}
