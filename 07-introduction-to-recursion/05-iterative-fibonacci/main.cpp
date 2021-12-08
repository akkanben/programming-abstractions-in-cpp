/* Programming Abstractions in C++
 *
 * Exercise 07-05
 *
 * Write an iterative implementation of the function fib(n).
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int fib(int n);

int main() {
  for (int i = 0; i < 45; i++) {
    std::cout << "Fibonacci " << i + 1 << ": " << fib(i) << std::endl;
  }
  return 0;
}

int fib(int n) {
  int fib = 1;
  int previousFib = 0;
  int count = 0;
  int temp = 0;
  while (n != count) {
    temp = previousFib;
    previousFib = fib;
    fib = fib + temp;
    count++;
  }
  return fib;
}
