/* Programming Abstractions in C++
 *
 * Exercise 05-08
 *
 * A magic square is a two-dimensional grid of integers in which the rows,
 * columns, and diagonals all add up to the same value. One of the most famous
 * magic squares appears in the 1514 engraving “Melencolia I” by Albrecht
 * Dürer shown in Figure 5-12, in which a 4 ! 4 magic square appears in the
 * upper right, just under the bell. In Dürer’s square, which can be read more
 * easily in the magnified inset shown at the right of the figure, all four
 * rows, all four columns, and both diagonals add up to 34. A more familiar
 * example is the following 3 ! 3 magic square in which each of the rows,
 * columns, and diagonals add up to 15, as shown:
 *
 * <magic square diagrams>
 *
 * Implement a function
 *
 *  bool isMagicSquare(Grid<int> & square);
 *
 * that tests to see whether the grid contains a magic square. Your program
 * should work for square grids of any size. If you call isMagicSquare with a
 * grid in which the number of rows and columns are different, it should simply
 * return false.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/map.h"
#include "../../StanfordCPPLib/include/set.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>

void fillGrid(Grid<int> &grid, Vector<int> &values);
void printGrid(Grid<int> &g);
bool isMagicSquare(Grid<int> &square);

int main() {
  Grid<int> matrix(3, 3);
  Vector<int> values;
  values += 8, 1, 6;
  values += 3, 5, 7;
  values += 4, 9, 2;
  fillGrid(matrix, values);
  printGrid(matrix);
  if (isMagicSquare(matrix)) {
    std::cout << "This is a magic square." << std::endl;
  } else {
    std::cout << "This is NOT a magic square" << std::endl;
  }
  return 0;
}

void fillGrid(Grid<int> &grid, Vector<int> &values) {
  int count = 0;
  for (int i = 0; i < grid.numRows(); i++) {
    for (int j = 0; j < grid.numCols(); j++) {
      grid.set(i, j, values.get(count));
      count++;
    }
  }
}

void printGrid(Grid<int> &g) {
  for (int i = 0; i < g.numRows(); i++) {
    for (int j = 0; j < g.numCols(); j++) {
      std::cout << g.get(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

/*
 * isMagicSquare() sums all rows/columns/diagonals and puts
 * the total into a set. If the set it larger than one
 * we know the square is not magic. The totals Map() holds
 * all the totals as they are tallied. The rows get cleared
 * each row and the colums get keys of "cols" plus the column
 * number as a string i.e. "cols2".
 *
 * Forward diagonals always have matching rows/cols and
 * backward diagonal row + col always add up to the length
 * of a row (or column) minus 1;
 */

bool isMagicSquare(Grid<int> &square) {
  if (square.numCols() != square.numRows()) {
    return false;
  }
  Set<int> sum;
  Map<std::string, int> totals;
  for (int row = 0; row < square.numRows(); row++) {
    for (int col = 0; col < square.numCols(); col++) {
      totals["rows"] += square[row][col];
      totals["cols" + integerToString(col)] += square[row][col];
      if (col == row) {
        totals["forward"] += square[row][col];
      }
      if (col + row == square.numCols() - 1) {
        totals["backward"] += square[row][col];
      }
    }
    sum.add(totals["rows"]);
    totals["rows"] = 0;
  }
  sum.add(totals["forward"]);
  sum.add(totals["backward"]);
  for (int i = 0; i < square.numCols(); i++) {
    sum.add(totals["cols" + integerToString(i)]);
  }
  if (sum.size() == 1)
    return true;
  return false;
}
