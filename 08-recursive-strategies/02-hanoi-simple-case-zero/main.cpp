/* Programming Abstractions in C++
 *
 * Exercise 08-02
 *
 * To make the operation of the program somewhat easier to explain, the
 * implementation of moveTower in this chapter uses
 *
 *  if (n == 1)
 *
 * as its simple case test. Whenever you see a recursive program use 1 as its
 * simple case, it pays to be a little skeptical; in most applications, 0 is a
 * more appropriate choice. Rewrite the Towers of Hanoi program so that the
 * moveTower function checks whether n is 0 instead. What happens to the
 * length of the moveTower implementation?
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

void moveTower(int n, char start, char finish, char tmp);
void moveSingleDisk(char start, char finish);

int main() {
  std::cout << "This program uses the simple test of n == 0 instead of n == 1"
            << std::endl;
  std::cout << "Hanoi tower with 3 disks increases to 15 moves from 7: "
            << std::endl;
  moveTower(3, 'A', 'B', 'C');
  return 0;
}

void moveTower(int n, char start, char finish, char tmp) {
  if (n == 0)
    moveSingleDisk(start, finish);
  else {
    moveTower(n - 1, start, tmp, finish);
    moveSingleDisk(start, finish);
    moveTower(n - 1, tmp, finish, start);
  }
}

void moveSingleDisk(char start, char finish) {
  std::cout << start << " -> " << finish << std::endl;
}
