/* Programming Abstractions in C++
 *
 * Exercise 05-07
 *
 * One of the problems in using the Grid class is that it isn’t as easy to set
 * up a particular set of initial values as it is with a vector, where you can
 * add the elements you want with the += operator. One way to streamline the
 * process of initializing a grid is to define a function
 *
 *  void fillGrid(Grid<int> & grid, Vector<int> & values);
 *
 * that fills the elements of the grid from the values in the vector. For
 * example, the code
 *
 *  Grid<int> matrix(3, 3);
 *  Vector<int> values;
 *  values += 1, 2, 3;
 *  values += 4, 5, 6;
 *  values += 7, 8, 9;
 *  fillGrid(matrix, values);
 *
 * initializes the variable matrix to be a 3 x 3 grid containing the values
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>

void fillGrid(Grid<int> &grid, Vector<int> &values);

int main() {
  Grid<int> matrix(3, 3);
  Vector<int> values;
  values += 1, 2, 3;
  values += 4, 5, 6;
  values += 7, 8, 9;
  fillGrid(matrix, values);
  for (int i = 0; i < matrix.numRows(); i++) {
    for (int j = 0; j < matrix.numCols(); j++) {
      std::cout << matrix.get(i, j) << " ";
    }
    std::cout << std::endl;
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
