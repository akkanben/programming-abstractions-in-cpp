/* Programming Abstractions in C++
 *
 * Exercise 02-14
 *
 * Random numbers offer yet another strategy for approximating the value of PI.
 * Imagine that you have a dartboard hanging on your wall that consists of a
 * circle painted on a square backdrop, as in the following diagram:
 *
 * <image of grey circle in a white box with black outline>
 *
 * What happens if you throw a whole bunch of darts completely randomly,
 * ignoring any darts that miss the board altogether? Some of the darts will
 * fall inside the gray circle, but some will be outside the circle in the white
 * corners of the square. If the darts are random, the ratio of the number of
 * darts landing inside the circle to the total number of darts hitting the
 * square should be approximately equal to the ratio between the two areas. The
 * ratio of the areas is independent of the actual size of the dartboard, as
 * illustrated by the formula
 *
 * darts falling inside the circle  ~   area inside the circle     PIr^2     PI
 * -------------------------------  =   ----------------------  =  -----  =  --
 * darts falling inside the square      area inside the square      4r^2      4
 *
 *
 * To simulate this process in a program, imagine that the dart board is drawn
 * on the standard Cartesian coordinate plane with its center at the origin and
 * a radius of 1 unit. The process of throwing a dart randomly at the square can
 * be modeled by generating two random numbers, x and y, each of which lies
 * between –1 and +1. This (x, y) point always lies somewhere inside the square.
 * The point (x, y) lies inside the circle if
 *
 * sqrt(x^2+y^2) < 1
 *
 * This condition, however, can be simplified considerably by squaring each side
 * 1of the inequality, which gives the following more efficient test:
 *
 * x2 + y2 < 1
 *
 * If you perform this simulation many times and compute the fraction of darts
 * that fall within the circle, the result will be an approximation of PI/4.
 *
 * Write a program that simulates throwing 10,000 darts and then uses the
 * simulation technique described in this exercise to generate and display an
 * approximate value of PI. Don’t worry if your answer is correct only in the
 * first few digits. The strategy used in this problem is not particularly
 * accurate, even though it occasionally proves useful as an approximation
 * technique. In mathematics, this technique is called Monte Carlo integration,
 * after the capital city of Monaco.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/random.h"
#include <iostream>

int const DARTS_TROWN = 10000;

void throwDarts(int &in);
void printResults(double ratio, int in);

int main() {
  int dartsInside = 0;
  double ratio = 0.0;
  throwDarts(dartsInside);
  ratio = double(dartsInside) / DARTS_TROWN;
  printResults(ratio, dartsInside);
  return 0;
}

void throwDarts(int &in) {
  double x, y;
  for (int i = 0; i < DARTS_TROWN; i++) {
    x = randomReal(-1, 1);
    y = randomReal(-1, 1);
    if ((x * x) + (y * y) < 1)
      in++;
  }
}

void printResults(double ratio, int in) {
  std::cout << DARTS_TROWN << " darts reveal:" << std::endl;
  std::cout << in << " fell inside the circle" << std::endl;
  std::cout << "creating a ratio of " << ratio << std::endl;
  std::cout << "multiply by 4 to get the PI approximation of: " << ratio * 4.0
            << std::endl;
}
