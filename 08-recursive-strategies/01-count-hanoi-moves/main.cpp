/* Programming Abstractions in C++
 *
 * Exercise 08-01
 *
 * Following the logic of the moveTower function, write a recursive function
 * countHanoiMoves(n) that computes the number of moves required to solve
 * the Towers of Hanoi puzzle for n disks.
 *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>

int countHanoiMoves(int n);

int main() {
  for (int i = 2; i <= 15; i++) {
    std::cout << "A Hanoi tower of " << std::setw(2) << i
              << " disks would take " << std::setw(5) << countHanoiMoves(i)
              << " moves." << std::endl;
  }
  return 0;
}

int countHanoiMoves(int n) {
  if (n == 1)
    return 1;
  return 1 + countHanoiMoves(n - 1) + countHanoiMoves(n - 1);
}
