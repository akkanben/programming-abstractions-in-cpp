/* Programming Abstractions in C++
 *
 * Exercise
 *
 * For each of the two recursive implementations of the function fib(n)
 * presented in this chapter, write a recursive function (you can call these
 * countFib1 and countFib2 for the two algorithms) that counts the number of
 * function calls made during the evaluation of the corresponding Fibonacci
 * calculation. Write a main program that uses these functions to display a
 * table showing the number of calls made by each algorithm for various values
 * of n, as shown in the following sample run:
 *
 *  <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>

int countFib1(int n, int &count);
int countFib2(int n, int &count);
int additiveSequence(int n, int t0, int t1, int &count);

int main() {
  std::cout << "This program counts the number of calls made by the two "
               "algorithms used to computer the Fibonacci sequence."
            << std::endl;
  std::cout << std::right << std::setw(4) << "n" << std::setw(8) << "fib1"
            << std::setw(8) << "fib2" << std::endl;
  std::cout << std::right << std::setw(4) << "--" << std::setw(8) << "----"
            << std::setw(8) << "----" << std::endl;
  for (int i = 0; i < 13; i++) {
    int count1 = 0;
    int count2 = 0;
    countFib1(i, count1);
    countFib2(i, count2);
    std::cout << std::right << std::setw(4) << i << std::setw(8) << count1
              << std::setw(8) << count2 << std::endl;
  }
  return 0;
}

int countFib1(int n, int &count) {
  count++;
  if (n < 2) {
    return n;
  } else
    return countFib1(n - 1, count) + countFib1(n - 2, count);
}

int countFib2(int n, int &count) {
  count++;
  return additiveSequence(n, 0, 1, count);
}

int additiveSequence(int n, int t0, int t1, int &count) {
  count++;
  if (n == 0) {
    return t0;
  }
  if (n == 1) {
    return t1;
  }
  return additiveSequence(n - 1, t1, t0 + t1, count);
}
