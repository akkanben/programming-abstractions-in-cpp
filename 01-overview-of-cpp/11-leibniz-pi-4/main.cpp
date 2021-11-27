/* Programming Abstractions in C++
 *
 * Exercise 01-11
 *
 * The German mathematician Leibniz (1646–1716) discovered the rather
 * remarkable fact that the mathematical constant ! can be computed using the
 * following mathematical relationship:
 *
 * PI/4 =~ 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...
 *
 * The formula to the right of the equal sign represents an infinite series;
 * each fraction represents a term in that series. If you start with 1, subtract
 * one-third, add one-fifth, and so on, for each of the odd integers, you get a
 * number that gets closer and closer to the value of !/4 as you go along.
 *
 * Write a program that calculates an approximation of ! consisting of the first
 * 10,000 terms in Leibniz’s series.
 *
 * Solution 2021 Ben Mills
 *
 * WolframAlpha gives me
 * 0.7853981633974483096156608458198757210492923498437764552437361480
 *
 */

#include <iostream>

int const TERM_COUNT = 20000;

int main() {
  double number = 1.0;
  int count = 1;
  for (int i = 1; i < TERM_COUNT; i += 2) {
    double fraction = 1.0 / (i + 2.0);
    if (count % 2 == 0)
      number += fraction;
    else
      number -= fraction;
    count++;
  }
  std::cout << "PI/4 is about: " << number << std::endl;
  std::cout << "PI is about: " << number * 4 << std::endl;
  return 0;
}
