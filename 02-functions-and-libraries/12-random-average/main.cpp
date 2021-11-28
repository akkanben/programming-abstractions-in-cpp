/* Programming Abstractions in C++
 *
 * Exercise 02-12
 *
 * Write a program RandomAverage that repeatedly generates a random real
 * number between 0 and 1 and then displays the average after a specified number
 * of trials entered by the user.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/random.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include <iostream>

double computeAverageReal(int num);

int main() {
  std::cout << "This program will give an average of " << std::endl;
  std::cout << "random numbers beteen 0 and 1." << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Enter a number of trials to process: ";
  int num_trials = getInteger("Enter a number of trials to process: ");
  std::cout << "The average random number between 0 and 1 with " << num_trials
            << " trials was " << computeAverageReal(num_trials) << std::endl;
  return 0;
}

double computeAverageReal(int num) {
  double total = 0.0;
  for (int i = 0; i < num; i++) {
    double number = randomReal(0, 1);
    total += number;
  }
  return total / num;
}
