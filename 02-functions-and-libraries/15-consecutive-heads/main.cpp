/* Programming Abstractions in C++
 *
 * Exercise 02-15
 *
 * Heads. . . .
 * Heads. . . .
 * Heads. . . .
 *
 * A weaker man might be moved to re-examine his faith, if in
 * nothing else at least in the law of probability.
 *
 *   —Tom Stoppard, Rosencrantz and Guildenstern Are Dead, 1967
 *
 * Write a program that simulates flipping a coin repeatedly and continues until
 * three consecutive heads are tossed. At that point, your program should
 * display the total number of coin flips that were made.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/random.h"
#include <iostream>

std::string coinFlip();

int main() {
  int totalCount = 0;
  int consecutiveHeads = 0;
  while (consecutiveHeads < 3) {
    totalCount++;
    std::string toss = coinFlip();
    if (toss == "heads") {
      consecutiveHeads++;
    } else {
      consecutiveHeads = 0;
    }
    std::cout << "Flip " << totalCount << ": " << toss << std::endl;
  }
  std::cout << "It took " << totalCount << " flips to get 3 consecutive heads."
            << std::endl;
  return 0;
}

std::string coinFlip() { return randomChance(0.5) ? "heads" : "tails"; }
