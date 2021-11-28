/* Programming Abstractions in C++
 *
 * Exercise 02-17
 *
 * Use the graphics library to write a program that draws a checkerboard on the
 * graphics window. Your picture should include the red and black pieces, as
 * they exist at the beginning of the game, like this:
 *
 * <image of checkerboard game>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/gwindow.h"

double const SQUARE_SIZE = 100;
double const PIECE_SIZE = 0.85 * SQUARE_SIZE;
double const PIECE_OFFSET = (SQUARE_SIZE - PIECE_SIZE) / 2;
double const WINDOW_WIDTH = SQUARE_SIZE * 8;

void drawBoard(GWindow &gw);
void drawGreySquare(GWindow &gw, int x, int y, double width);
void drawWhiteSquare(GWindow &gw, int x, int y, double width);
void drawRedPiece(GWindow &gw, int x, int y, double width);
void drawBlackPiece(GWindow &gw, int x, int y, double width);

int main() {
  GWindow gw(WINDOW_WIDTH, WINDOW_WIDTH);
  drawBoard(gw);
  return 0;
}

void drawBoard(GWindow &gw) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      double x = SQUARE_SIZE * j;
      double y = SQUARE_SIZE * i;

      if ((j + i) % 2 == 1) {
        drawGreySquare(gw, x, y, SQUARE_SIZE);
        if (i < 3) {
          drawRedPiece(gw, x + PIECE_OFFSET, y + PIECE_OFFSET, PIECE_SIZE);
        }
        if (i > 4) {
          drawBlackPiece(gw, x + PIECE_OFFSET, y + PIECE_OFFSET, PIECE_SIZE);
        }
      } else {
        drawWhiteSquare(gw, x, y, SQUARE_SIZE);
      }
    }
  }
}

void drawGreySquare(GWindow &gw, int x, int y, double width) {
  gw.setColor("LIGHT_GRAY");
  gw.fillRect(x, y, width, width);
}

void drawWhiteSquare(GWindow &gw, int x, int y, double width) {
  gw.setColor("WHITE");
  gw.fillRect(x, y, width, width);
}

void drawRedPiece(GWindow &gw, int x, int y, double width) {
  gw.setColor("RED");
  gw.fillOval(x, y, width, width);
}

void drawBlackPiece(GWindow &gw, int x, int y, double width) {
  gw.setColor("BLACK");
  gw.fillOval(x, y, width, width);
}
