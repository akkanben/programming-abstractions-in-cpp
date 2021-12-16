/* Programming Abstractions in C++
 *
 * Exercise 09-06 Alternative Version
 *
 * In chess, a knight moves in an L-shaped pattern: two squares in one direction
 * horizontally or vertically, and then one square at right angles to that
 * motion. For example, the white knight in the upper right side of the
 * following diagram can move to any of the eight squares marked with an "X".
 *
 *  <image of chessboard and knight moves>
 *
 * The mobility of a knight decreases near the edge of the board, as illustrated
 * by the black knight in the corner, which can reach only the two squares
 * marked with an "o".
 *
 * It turns out that a knight can visit all 64 squares on a chessboard without
 * ever moving to the same square twice. A path for the knight that moves
 * through all the squares without repeating a square is called a knight’s tour.
 * One such tour is shown in the following diagram, in which the numbers in the
 * squares indicate the order in which they were visited:
 *
 *  <image of knight’s tour moves>
 *
 * Write a program that uses backtracking recursion to find a knight’s tour.
 *
 * Solution 2021 Ben Mills
 *
 * This version of the solution animates the moves as they happen -- it takes a
 * very long time to complete.
 *
 */

#include <iostream>

#include "../../StanfordCPPLib/include/gobjects.h"
#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/gwindow.h"

const int SQUARE_SIZE = 100;
const int BOARD_SIZE = 8;

bool canHazKnightsTour(GWindow &gw, Grid<int> &board, GPoint start, int count);
void drawBoard(GWindow &gw, Grid<int> board);
void drawMoveNumbers(GWindow &gw, Grid<int> board);
void placeKnight(GWindow &gw, Grid<int> &board, GPoint point, int count);
void removeKnight(GWindow &gw, Grid<int> &board, GPoint point);
GPoint getNextPoint(int num, GPoint point);
bool spaceIsFree(Grid<int> board, GPoint point);

int main() {
  GWindow gw(BOARD_SIZE * SQUARE_SIZE, BOARD_SIZE * SQUARE_SIZE);
  Grid<int> board(BOARD_SIZE, BOARD_SIZE);
  GPoint start(0, 0);
  int count = 1;
  drawBoard(gw, board);
  if (canHazKnightsTour(gw, board, start, count)) {
    std::cout << "Possible!" << std::endl;
    std::cout << board << std::endl;
  } else {
    std::cout << "Not Possible!" << std::endl;
    std::cout << board << std::endl;
  }
  return 0;
}

bool canHazKnightsTour(GWindow &gw, Grid<int> &board, GPoint start, int count) {
  if (count > BOARD_SIZE * BOARD_SIZE) {
    return true;
  }
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board.inBounds(start.getX(), start.getY()) &&
        spaceIsFree(board, start)) {
      placeKnight(gw, board, start, count);
      if (canHazKnightsTour(gw, board, getNextPoint(i, start), count + 1)) {
        return true;
      }
      removeKnight(gw, board, start);
    }
  }
  return false;
}

void drawBoard(GWindow &gw, Grid<int> board) {
  for (int i = 0; i < board.numRows(); i++) {
    for (int j = 0; j < board.numCols(); j++) {
      if ((i + j) % 2 != 0) {
        gw.setColor("Black");
      } else {
        gw.setColor("White");
      }
      gw.fillRect(SQUARE_SIZE * j, SQUARE_SIZE * i, SQUARE_SIZE, SQUARE_SIZE);
    }
  }
}

void drawMove(GWindow &gw, Grid<int> board, int row, int col) {
  std::string color;
  if ((row + col) % 2 != 0) {
    color = "Black";
  } else {
    color = "White";
  }
  GLabel *clear = new GLabel("██");
  clear->setFont("SansSerif-50");
  clear->setColor(color);
  gw.add(clear, SQUARE_SIZE * col, SQUARE_SIZE * row + SQUARE_SIZE / 2);
  if (board[row][col] != 0) {
    GLabel *moveNumber = new GLabel(integerToString(board[row][col]));
    moveNumber->setColor("Red");
    moveNumber->setFont("SansSerif-50");
    gw.add(moveNumber, SQUARE_SIZE * col, SQUARE_SIZE * row + SQUARE_SIZE / 2);
  }
}

GPoint getNextPoint(int num, GPoint point) {
  switch (num) {
  case 0:
    return GPoint(point.getX() + 2, point.getY() + 1);
  case 1:
    return GPoint(point.getX() + 1, point.getY() + 2);
  case 2:
    return GPoint(point.getX() - 1, point.getY() + 2);
  case 3:
    return GPoint(point.getX() - 2, point.getY() + 1);
  case 4:
    return GPoint(point.getX() - 2, point.getY() - 1);
  case 5:
    return GPoint(point.getX() - 1, point.getY() - 2);
  case 6:
    return GPoint(point.getX() + 1, point.getY() - 2);
  case 7:
    return GPoint(point.getX() + 2, point.getY() - 1);
  default:
    return GPoint(-1, -1);
  }
}

void placeKnight(GWindow &gw, Grid<int> &board, GPoint point, int count) {
  board.set(point.getX(), point.getY(), count);
  drawMove(gw, board, point.getX(), point.getY());
}

void removeKnight(GWindow &gw, Grid<int> &board, GPoint point) {
  board.set(point.getX(), point.getY(), 0);
  drawMove(gw, board, point.getX(), point.getY());
}

bool spaceIsFree(Grid<int> board, GPoint point) {
  if (board.get(point.getX(), point.getY()) == 0) {
    return true;
  } else {
    return false;
  }
}
