/* Programming Abstractions in C++
 *
 * Exercise 09-05
 *
 * The most powerful piece in the game of chess is the queen, which can move
 * any number of squares in any direction, horizontally, vertically, or
 * diagonally. For example, the queen shown in this chessboard can move to any
 * of the marked squares:
 *
 * Even though the queen can cover a large number of squares, it is possible to
 * place eight queens on an 8 ! 8 chessboard so that none of them attacks any of
 * the others, as shown in the following diagram:
 *
 * Write a program that solves the more general problem of whether it is
 * possible to place N queens on an N ! N chessboard so that none of them can
 * move to a square occupied by any of the others in a single turn. Your program
 * should either display a solution if it finds one or report that no solutions
 * exist.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/gobjects.h"
#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/gwindow.h"

const int SQUARE_SIZE = 100;
const int NQEEENS = 8;
const int SCREEN_WIDTH_AND_HEIGHT = SQUARE_SIZE * NQEEENS;

bool nQueensPossible(GWindow &gw, Grid<bool> &board, int col);
void drawBoard(GWindow &gw, Grid<bool> board);
bool queenIsSafe(Grid<bool> board, int row, int col);
bool diagonalIsSafe(Grid<bool> board, int row, int col);
bool cardinalIsSafe(Grid<bool> board, int row, int col);

int main() {
  GWindow gw(SCREEN_WIDTH_AND_HEIGHT, SCREEN_WIDTH_AND_HEIGHT);
  Grid<bool> board(NQEEENS, NQEEENS);
  GLabel *outcome = new GLabel("");
  outcome->setFont("SansSerif-" + integerToString((NQEEENS * 10)));
  outcome->setColor("Orange");
  if (!nQueensPossible(gw, board, 0)) {
    outcome->setLabel("Not Possible!");
  } else {
    outcome->setLabel("Possible!");
  }
  gw.add(outcome, gw.getWidth() / 2 - (outcome->getWidth() / 2),
         gw.getHeight() / 2 + outcome->getHeight() / 4);
  return 0;
}

void drawBoard(GWindow &gw, Grid<bool> board) {
  for (int i = 0; i < board.numRows(); i++) {
    for (int j = 0; j < board.numCols(); j++) {
      if ((i + j) % 2 != 0) {
        gw.setColor("Black");
      } else {
        gw.setColor("White");
      }
      gw.fillRect(SQUARE_SIZE * j, SQUARE_SIZE * i, SQUARE_SIZE, SQUARE_SIZE);
      if (board[i][j]) {
        gw.setColor("Red");
        gw.fillOval(SQUARE_SIZE * j, SQUARE_SIZE * i, SQUARE_SIZE, SQUARE_SIZE);
      }
    }
  }
}

bool nQueensPossible(GWindow &gw, Grid<bool> &board, int col) {
  drawBoard(gw, board);
  if (col >= board.numCols()) {
    return true;
  }
  for (int i = 0; i < board.numRows(); i++) {
    pause(3);
    if (queenIsSafe(board, i, col)) {
      // Placing Queen
      board.set(i, col, true);
      if (nQueensPossible(gw, board, col + 1)) {
        return true;
      }
      // Removing Queen
      board.set(i, col, false);
    }
  }
  return false;
}

bool queenIsSafe(Grid<bool> board, int row, int col) {
  if (diagonalIsSafe(board, row, col) && cardinalIsSafe(board, row, col)) {
    return true;
  } else {
    return false;
  }
}

// diagonalIsSafe is safe checks 4 points expanding from board[row][col]
// rows moving north y decreases, moving south y increases
// cols moving west x decreases, moving east x increases
//
// NW N NE
//  W * E
// SW S SE
//
bool diagonalIsSafe(Grid<bool> board, int row, int col) {
  int n = row;
  int s = row;
  int e = col;
  int w = col;
  bool nw, ne, se, sw = true;
  while (nw || ne || se || sw) {
    nw = board.inBounds(n, w);
    ne = board.inBounds(n, e);
    se = board.inBounds(s, e);
    sw = board.inBounds(s, w);
    if ((nw && board.get(n, w)) || (ne && board.get(n, e)) ||
        (se && board.get(s, e)) || (sw && board.get(s, w)))
      return false;
    n--;
    s++;
    e++;
    w--;
  }
  return true;
}

bool cardinalIsSafe(Grid<bool> board, int row, int col) {
  for (int i = 0; i < NQEEENS; i++) {
    if (board[row][i] || board[i][col]) {
      return false;
    }
  }
  return true;
}
