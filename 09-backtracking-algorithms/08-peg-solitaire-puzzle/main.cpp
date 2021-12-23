/* Programming Abstractions in C++
 *
 * Exercise 09-08
 *
 * In theory, the recursive backtracking strategy described in this chapter
 * should be sufficient to solve most puzzles that involve performing a sequence
 * of moves looking for some solution. In practice, however, some of those
 * puzzles are too complex to solve in a reasonable amount of time. One puzzle
 * that is just at the limit of what recursive backtracking can accomplish
 * without using some additional cleverness is the peg solitaire puzzle, which
 * dates from the 17 th century. Peg solitaire is usually played on a board that
 * looks like this:
 *
 *  <image of peg solitaire board>
 *
 * The black dots in the diagram are pegs, which fill the board except for the
 * center hole. On a turn, you are allowed to jump over and remove a peg, as
 * illustrated in the following diagram, in which the colored peg jumps into the
 * vacant center hole and the peg in the middle is removed:
 * The object of the game is to perform a series of jumps that leaves only one
 * peg in the center hole. Write a program to solve this puzzle.
 *
 * Solution 2021 Ben Mills
 */
#include <iostream>

#include "pegBoard.h"

bool solvePegBoard(PegBoard &gameBoard, Vector<Point> threatened);

int main() {
  PegBoard gameBoard(7, 7, 2);
  std::cout << gameBoard.toString() << std::endl;
  Vector<Point> threatened = gameBoard.getThreatenedPegs();
  solvePegBoard(gameBoard, threatened);
  return 0;
}

bool solvePegBoard(PegBoard &gameBoard, Vector<Point> threatened) {
  if (gameBoard.numPegsLeft() == 1)
    cout << gameBoard.toString() << endl;
  if (gameBoard.numPegsLeft() == 1 && gameBoard.pegInCenter()) {
    std::cout << "WINNER" << std::endl;
    std::cout << gameBoard.toString() << std::endl;
    return true;
  }
  for (int i = 0; i < threatened.size(); i++) {
    for (Direction dir = NORTH; dir <= WEST; dir++) {
      if (gameBoard.canBeJumpedFrom(threatened[i], dir)) {
        gameBoard.jump(threatened[i], dir);
        if (solvePegBoard(gameBoard, gameBoard.getThreatenedPegs())) {
          return true;
        }
        gameBoard.unJump(threatened[i], dir);
      }
    }
  }
  return false;
}
