/* Programming Abstractions in C++
 *
 * Exercise 05-11
 *
 * The resize method in the Grid class resets the dimensions of the grid but
 * also initializes every element of the grid to its default value. Write a
 * function
 *
 *  void reshape(Grid<int> & grid, int nRows, int nCols);
 *
 * that resizes the grid but fills in the data from the original grid by copying
 * elements in the standard row-major order (left-to-right/top-to-bottom). For
 * example, if myGrid initially contains the values
 *
 *  <image of 4x3 grid of numbers 1-1>
 *
 * calling the function
 *
 *  reshape(myGrid, 4, 3)
 *
 * should change the dimensions and contents of myGrid as follows:
 *
 *  <image of 3x4 grid of numbers 1-12>
 *
 * If the new grid does not include enough space for all of the original values,
 * the values at the bottom of the grid are simply dropped. For example, if you
 * call
 *
 *  reshape(myGrid, 2, 5)
 *
 * there is no room for the last two elements, so the new grid will look like
 * this:
 *
 *  <image of 5x2 grid of numbers 1-10>
 *
 * Conversely, if there are not enough elements in the original grid to fill the
 * available space, the entries at the end should simply retain their default
 * values.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>

void reshape(Grid<int> &grid, int nRows, int nCols);
void printGrid(Grid<int> counts);
void fillGrid(Grid<int> &grid, Vector<int> &values);

int main() {
  Vector<int> values;
  Grid<int> grid(3, 4);
  values += 1, 2, 3, 4;
  values += 5, 6, 7, 8;
  values += 9, 10, 11, 12;
  fillGrid(grid, values);
  printGrid(grid);
  std::cout << std::endl;
  reshape(grid, 4, 3);
  printGrid(grid);
  std::cout << std::endl;
  reshape(grid, 2, 5);
  printGrid(grid);
  std::cout << std::endl;
  reshape(grid, 5, 3);
  printGrid(grid);
  return 0;
}

void reshape(Grid<int> &grid, int nRows, int nCols) {
  Vector<int> values;
  for (int i = 0; i < grid.numRows(); i++) {
    for (int j = 0; j < grid.numCols(); ++j) {
      values.add(grid.get(i, j));
    }
  }
  grid.resize(nRows, nCols);
  int numleft = values.size();
  int count = 0;
  for (int i = 0; i < grid.numRows(); ++i) {
    for (int j = 0; j < grid.numCols(); ++j) {
      if (numleft > 0) {
        grid.set(i, j, values[count]);
        count++;
      } else {
        grid.set(i, j, 0);
      }
      numleft--;
    }
  }
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

void printGrid(Grid<int> counts) {
  for (int i = 0; i < counts.numRows(); i++) {
    for (int j = 0; j < counts.numCols(); j++) {
      std::cout << counts.get(i, j) << " ";
    }
    std::cout << std::endl;
  }
}
