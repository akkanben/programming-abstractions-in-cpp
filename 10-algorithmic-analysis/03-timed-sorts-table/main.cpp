/* Programming Abstractions in C++
 *
 * Exercise 10-03
 *
 * Write a function that keeps track of the elapsed time as it executes the sort
 * procedure on a randomly chosen vector. Use that function to write a program
 * that produces a table of the observed running times for a predefined set of
 * sizes, as shown in the following sample run:
 *
 *  <image of sample run>
 *
 * The best way to measure elapsed system time for programs of this sort is to
 * use the ANSI clock function, which is exported by the ctime interface. The
 * clock function takes no arguments and returns the amount of time the
 * processing unit of the computer has used in the execution of the program. The
 * unit of measurement and even the type used to store the result of clock
 * differ depending on the type of machine, but you can always convert the
 * system-dependent clock units into seconds by using the following expression:
 *
 *  double(clock()) / CLOCKS_PER_SEC
 *
 * If you record the starting and finishing times in the variables start and
 * finish, you can use the following code to compute the time required by a
 * calculation:
 *
 *  double start = double(clock()) / CLOCKS_PER_SEC;
 *  . . . Perform some calculation . . .
 *  double finish = double(clock()) / CLOCKS_PER_SEC;
 *  double elapsed = finish - start;
 *
 * Unfortunately, calculating the time requirements for a program that runs
 * quickly requires some subtlety because there is no guarantee that the system
 * clock unit is precise enough to measure the elapsed time. For example, if you
 * used this strategy to time the process of sorting 10 integers, the odds are
 * good that the time value of elapsed at the end of the code fragment would be
 * 0. The reason is that the processing unit on most machines can execute many
 * instructions in the space of a single clock tick—almost certainly enough to
 * get the entire sorting process done for a vector of 10 elements. Because the
 * system’s internal clock may not tick in the interim, the values recorded for
 * start and finish are likely to be the same.
 *
 * The best way to get around this problem is to repeat the calculation many
 * times between the two calls to the clock function. For example, if you want
 * to determine how long it takes to sort 10 numbers, you can perform the
 * sort-10-numbers experiment 1000 times in a row and then divide the total
 * elapsed time by 1000. This strategy gives you a timing measurement that is
 * much more accurate.
 *
 * Solution 2021 Ben Mills
 */

#include <ctime>
#include <iomanip>
#include <iostream>

#include "../../StanfordCPPLib/include/random.h"
#include "../../StanfordCPPLib/include/vector.h"

Vector<int> randomVectorOfSize(int size, int max);
void sort(Vector<int> &vec);

int main() {
  Vector<int> nSizes;
  nSizes += 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000;
  std::cout << "    N    |  Time (msec)  " << std::endl;
  std::cout << "---------+---------------" << std::endl;
  for (int i = 0; i < nSizes.size(); i++) {
    Vector<int> vec = randomVectorOfSize(nSizes[i], 10000);
    double start = double(clock()) / CLOCKS_PER_SEC;
    sort(vec);
    double finish = double(clock()) / CLOCKS_PER_SEC;
    double elapsed = finish - start;
    std::cout << std::fixed << std::right << std::setw(7) << nSizes[i]
              << "  |  " << setw(10) << elapsed << std::endl;
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
  if (vec.size() <= 1)
    return;
  for (int i = 1; i < vec.size(); i++) {
    int backPosition = i;
    while (backPosition > 0 && vec[backPosition] < vec[backPosition - 1]) {
      int temp = vec[backPosition - 1];
      vec[backPosition - 1] = vec[backPosition];
      vec[backPosition] = temp;
      backPosition--;
    }
  }
}
