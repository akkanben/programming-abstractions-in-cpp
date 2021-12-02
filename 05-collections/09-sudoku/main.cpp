/* Programming Abstractions in C++
 *
 * Exercise 05-09
 *
 * In the last several years, a new logic puzzle called Sudoku has become quite
 * popular throughout the world. In Sudoku, you start with a 9 ! 9 grid of
 * integers in which some of the cells have been filled in with digits between 1
 * and 9. Your job in the puzzle is to fill in each of the empty spaces with a
 * digit between 1 and 9 so that each digit appears exactly once in each row,
 * each column, and each of the smaller 3 ! 3 squares. Each Sudoku puzzle is
 * carefully constructed so that there is only one solution. For example, Figure
 * 5-13 shows a typical Sudoku puzzle on the left and its unique solution on the
 * right.
 *
 *  <image of figure 5-13>
 *
 * Although you won’t discover the algorithmic strategies you need to solve
 * Sudoku puzzles until later in this book, you can easily write a method that
 * checks to see whether a proposed solution follows the Sudoku rules against
 * duplicating values in a row, column, or outlined 3 ! 3 square. Write a
 * function
 *
 *  bool checkSudokuSolution(Grid<int> & puzzle);
 *
 * that performs this check and returns true if the puzzle is a valid solution.
 * Your program should check to make sure that puzzle contains a 9 x 9 grid of
 * integers and report an error if this is not the case.
 *
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/map.h"
#include "../../StanfordCPPLib/include/set.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>

void fillGrid(Grid<int> &grid, Vector<int> &values);
void populateTotals(Grid<int> &sudoku, Map<std::string, Set<int>> &totals);
bool checkSudokuSolution(Grid<int> &sudoku);
int getSquare(int row, int col);

int main() {
  Grid<int> sudoku(9, 9);
  Vector<int> values;
  values += 3, 9, 2, 4, 6, 5, 8, 1, 7;
  values += 7, 4, 1, 8, 9, 3, 6, 2, 5;
  values += 6, 8, 5, 2, 7, 1, 4, 3, 9;
  values += 2, 5, 4, 1, 3, 8, 7, 9, 6;
  values += 8, 3, 9, 6, 2, 7, 1, 5, 4;
  values += 1, 7, 6, 9, 5, 4, 2, 8, 3;
  values += 9, 6, 7, 5, 8, 2, 3, 4, 1;
  values += 4, 2, 3, 7, 1, 9, 5, 6, 8;
  values += 5, 1, 8, 3, 4, 6, 9, 7, 2;
  fillGrid(sudoku, values);
  if (checkSudokuSolution(sudoku)) {
    std::cout << "This is a valid solution" << std::endl;
  } else {
    std::cout << "This is NOT a valid solution" << std::endl;
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

/*
 * checkSudokuSolution() uses a map of sets to add each square in
 * this sudoku board to the corrosponding set. There are sets for each
 * row, column and square (27 all together). Each set must be 9 elements long to
 * return true.
 */

bool checkSudokuSolution(Grid<int> &sudoku) {
  Map<std::string, Set<int>> totals;
  populateTotals(sudoku, totals);
  for (std::string element : totals) {
    if (totals[element].size() != 9)
      return false;
  }
  return true;
}

void populateTotals(Grid<int> &sudoku, Map<std::string, Set<int>> &totals) {
  for (int row = 0; row < sudoku.numRows(); row++) {
    for (int col = 0; col < sudoku.numCols(); col++) {
      totals["row" + integerToString(row)].add(sudoku[row][col]);
      totals["col" + integerToString(col)].add(sudoku[row][col]);
      totals["square" + integerToString(getSquare(row, col))].add(
          sudoku[row][col]);
    }
  }
}

int getSquare(int row, int col) {
  if (row >= 6 && col >= 6)
    return 8;
  if (row >= 6 && col >= 3)
    return 7;
  if (row >= 6 && col >= 0)
    return 6;
  if (row >= 3 && col >= 6)
    return 5;
  if (row >= 3 && col >= 3)
    return 4;
  if (row >= 3 && col >= 0)
    return 3;
  if (row >= 0 && col >= 6)
    return 2;
  if (row >= 0 && col >= 3)
    return 1;
  return 0;
}
