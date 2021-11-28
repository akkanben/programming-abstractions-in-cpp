/* Programming Abstractions in C++
 *
 * Exercise 02-13
 *
 * Despite Einstein’s metaphysical objections, the current models of physics,
 * and particularly of quantum theory, are based on the idea that nature does
 * indeed involve random processes. A radioactive atom, for example, does not
 * decay for any specific reason that we mortals understand. Instead, that atom
 * has a random probability of decaying within a period of time. Sometimes it
 * does, sometimes it doesn’t, and there is no way to know for sure.
 *
 * Because physicists consider radioactive decay a random process, it is not
 * surprising that random numbers can be used to simulate it. Suppose you start
 * with a collection of atoms, each of which has a certain probability of
 * decaying in any unit of time. You can then approximate the decay process by
 * taking each atom in turn and deciding randomly whether it decays, considering
 * the probability.
 *
 * Write a program that simulates the decay of a sample that contains 10,000
 * atoms of radioactive material, where each atom has a 50 percent chance of
 * decaying in a year. The output of your program should show the number of
 * atoms remaining at the end of each year, which might look something like
 * this:
 *
 * <image of console log>
 *
 * As the numbers indicate, roughly half the atoms in the sample decay each
 * year. In physics, the conventional way to express this observation is to say
 * that the sample has a half-life of one year.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/random.h"
#include <iostream>

int decay(int numAtoms);

int main() {
  int atoms = 10000;
  int year = 0;
  std::cout << "There are " << atoms << " initially." << std::endl;
  while (atoms > 0) {
    atoms = decay(atoms);
    year++;
    std::cout << "There are " << atoms << " at the end of year " << year
              << std::endl;
  }
  return 0;
}

int decay(int numAtoms) {
  for (int i = numAtoms; i > 0; i--) {
    if (randomChance(0.5)) {
      numAtoms--;
    }
  }
  return numAtoms;
}
