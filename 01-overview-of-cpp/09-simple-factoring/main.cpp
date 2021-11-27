/* Programming Abstractions in C++
 *
 * Exercise 01-09
 *
 * Every positive integer greater than 1 can be expressed as a product of prime
 * numbers. This factorization is unique and is called the prime factorization.
 * For example, the number 60 can be decomposed into the factors 2 x 2 x 3 x 5,
 * each of which is prime. Note that the same prime can appear more than once in
 * the factorization.
 *
 * Write a program to display the prime factorization of a number n
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

int main() {
  int number;
  std::string factors;
  std::cout << "This program factors a number." << std::endl;
  std::cout << "Enter a number to be factored: ";
  std::cin >> number;
  for (int i = 2; i <= number; i++) {
    while (number % i == 0) {
      factors += std::to_string(i) + " x ";
      number /= i;
    }
  }
  std::cout << factors.substr(0, factors.size() - 3) << std::endl;
  return 0;
}
