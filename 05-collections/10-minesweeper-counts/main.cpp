/* Programming Abstractions in C++
 *
 * Exercise 05-10
 *
 * In the game of Minesweeper, a player searches for hidden mines on a
 * rectangular grid that might—for a very small board—look like this:
 *
 *  <image of minesweeper game>
 *
 * One way to represent that grid in C++ is to use a grid of Boolean values
 * marking mine locations, where true indicates the location of a mine. In
 * Boolean form, this sample grid therefore looks like this:
 *
 *  <image of T F grid>
 *
 * Given such a grid of mine locations, write a function
 *
 * void fixCounts(Grid<bool> & mines, Grid<int> & counts);
 *
 * that creates a grid of integers storing the number of mines in each
 * neighborhood. The neighborhood of a location includes the location itself and
 * the eight adjacent locations, but only if they are inside the boundaries of
 * the grid. The reference parameter counts is used to store the result. Your
 * job in this exercise is to make sure that it has the same size as the mines
 * grid and then to assign to each element an integer between 0 and 9. For
 * example, if mineLocations contains the Boolean grid shown earlier, the code
 *
 * Grid<int> mineCounts;
 * fixCounts(mineLocations, mineCounts);
 *
 * should initialize mineCounts as follows:
 *
 *  <image of 0-4 mine grid>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>

void fixCounts(Grid<bool> &mines, Grid<int> &counts);
int countBools(Grid<bool> bools, int row, int col);
void fillGrid(Grid<bool> &grid, Vector<bool> &values);
void printGrid(Grid<int> counts);

int main() {
  Grid<int> counts(6, 6);
  Grid<bool> mines(6, 6);
  Vector<bool> values;
  values += true, false, false, false, false, true;
  values += false, false, false, false, false, true;
  values += true, true, false, true, false, true;
  values += true, false, false, false, false, false;
  values += false, false, true, false, false, false;
  values += false, false, false, false, false, false;
  fillGrid(mines, values);
  fixCounts(mines, counts);
  printGrid(counts);
  return 0;
}

void fixCounts(Grid<bool> &mines, Grid<int> &counts) {
  for (int i = 0; i < mines.numRows(); i++) {
    for (int j = 0; j < mines.numCols(); j++) {
      counts.set(i, j, countBools(mines, i, j));
    }
  }
}

/*
 * countBools() iterates a smaller 3x3 grid with row/col
 * at the center. The inBounds() method asures we don't
 * get an undefined square.
 */

int countBools(Grid<bool> bools, int row, int col) {
  int mineCount = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (bools.inBounds(i + row, j + col)) {
        if (bools.get(i + row, j + col)) {
          mineCount++;
        }
      }
    }
  }
  return mineCount;
}

void fillGrid(Grid<bool> &grid, Vector<bool> &values) {
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
