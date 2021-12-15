/* Programming Abstractions in C++
 *
 * Exercise 09-04
 *
 * Most drawing programs for personal computers make it possible to fill an
 * enclosed region on the screen with a solid color. Typically, you invoke this
 * operation by selecting a “paint bucket” tool and then clicking the mouse,
 with
 * the cursor somewhere in your drawing. When you do, the paint spreads to
 * every part of the picture it can reach without going through a line.
 *
 * for example, suppose you have just drawn the following picture of a
 * house:
 *
 *  <image of house>
 *
 * if you select the paint bucket and click inside the door, the drawing program
 * fills the area bounded by the door frame as shown at the left side of the
 * following diagram. if you instead click somewhere on the front wall of the
 * house, the program fills the entire wall space except for the windows and
 * doors, as shown on the right:
 *
 *  <image of two houses>
 *
 * in order to understand how this process works, it is important to understand
 * that the screen of the computer is broken down into an array of tiny dot
 * called pixels. on a monochrome display, pixels can be either white or black.
 * The paint-fill operation consists of painting black the starting pixel (i.e.,
 * the
 * pixel you click while using the paint-bucket tool) along with any pixels
 connected
 * to that starting point by an unbroken chain of white pixels. thus, the
 * patterns of pixels on the screen representing the preceding two diagrams
 * would look like this:
 *
 *  ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓  ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓
 *  ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓  ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ░ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓
 *  ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓  ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ░ ░ ░ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓
 *  ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓  ▓ ▓ ▓ ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓ ▓ ▓ ▓
 *  ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓  ▓ ▓ ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓ ▓ ▓
 *  ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓  ▓ ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓ ▓
 *  ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓  ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓
 *  ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓  ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓
 *  ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓  ▓ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ▓
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ░ ░ ░ ░ ▓ ▓ ▓ ▓ ▓ ░ ░ ░ ░ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ░ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ░ ▓ ▓ ░  ░ ░ ░ ░ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ░ ░ ░ ░
 *  ░ ▓ ▓ ░ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ░ ▓ ▓ ░  ░ ░ ░ ░ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ░ ░ ░ ░
 *  ░ ▓ ▓ ░ ░ ░ ░ ▓ ▓ ▓ ▓ ▓ ░ ░ ░ ░ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ░ ░ ░ ░ ░ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ▓ ▓ ▓ ▓ ▓ ▓ ░ ▓ ▓ ▓ ░ ▓ ▓ ▓ ▓ ▓ ▓ ░  ░ ░ ░ ░ ░ ░ ░ ░ ▓ ▓ ▓ ░ ░ ░ ░ ░ ░ ░ ░
 *  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░
 *
 * It is easy to represent a pixel grid using the type Grid<bool>. White
 * pixels in the grid have the value false, and black pixels have the value
 * true. Given this representation, write a function
 *
 *  void fillRegion(Grid<bool> & pixels, int row, int col)
 *
 * that simulates the operation of the paint-bucket tool by painting in black
 all
 * white pixels reachable from the specified row and column without crossing an
 * existing black pixel.
 *
 * Solution 2021 Ben Mills
*/

#include <fstream>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/grid.h"

std::string getFile(ifstream &infile);
Grid<bool> getPixelGrid(ifstream &infile);
void printGrid(Grid<bool> g);
void fillRegion(Grid<bool> &pixels, int row, int col);

const std::string FILE_NAME = "house.txt";

int main() {
  std::ifstream infile;
  getFile(infile);
  Grid<bool> house = getPixelGrid(infile);
  std::cout << "Before:" << std::endl;
  printGrid(house);
  fillRegion(house, 5, 10);
  std::cout << "\n\nAfter:" << std::endl;
  printGrid(house);
  infile.close();
  return 0;
}

std::string getFile(ifstream &infile) {
  std::string filename = FILE_NAME;
  infile.open(filename.c_str());
  if (!infile.fail())
    return filename;
  infile.clear();
  std::cout << "Unable to locate" << filename << std::endl;
  return 0;
}

Grid<bool> getPixelGrid(ifstream &infile) {
  Grid<bool> output(24, 20);
  char ch;
  int row = 0;
  int col = 0;
  while (infile.get(ch)) {
    bool b;
    if (ch == '\n') {
      row++;
      col = 0;
    } else {
      if (ch == '0')
        b = false;
      else
        b = true;
      output.set(row, col, b);
      col++;
    }
  }
  return output;
}

void printGrid(Grid<bool> g) {
  std::string letter;
  for (int i = 0; i < g.numRows(); i++) {
    for (int j = 0; j < g.numCols() - 1; j++) {
      if (g.get(i, j))
        letter = "░";
      else
        letter = "▓";
      std::cout << letter << " ";
    }
    std::cout << std::endl;
  }
}

void fillRegion(Grid<bool> &pixels, int row, int col) {
  if (!pixels[row][col]) {
    pixels[row][col] = true;
    fillRegion(pixels, row - 1, col);
    fillRegion(pixels, row + 1, col);
    fillRegion(pixels, row, col - 1);
    fillRegion(pixels, row, col + 1);
  }
}
