/* Programming Abstractions in C++
 *
 * Exercise 02-16
 *
 * Use the graphics library to draw a rainbow that looks something like this:
 *
 * <image of rainbow arcs>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/gwindow.h"
#include <iostream>

using namespace std;

/* Constants */
double const RAINBOW_THICKNESS = 15;
double const RAINBOW_SIZE = 200;

enum Color { RED = 1, ORANGE, YELLOW, GREEN, BLUE, MAGENTA, CYAN, BLACK };

/* Function Prototypes */
void setBackgroundColor(GWindow &gw);
void drawRainbow(GWindow &gw);
string colorToString(Color color);

/* main */
int main() {
  GWindow gw;
  setBackgroundColor(gw);
  drawRainbow(gw);
  return 0;
}

void setBackgroundColor(GWindow &gw) {
  double width = gw.getWidth();
  double height = gw.getHeight();
  gw.setColor("CYAN");
  gw.fillRect(0, 0, width, height);
}

void drawRainbow(GWindow &gw) {
  for (int i = (int)RED; i < (int)BLACK; i++) {
    double width =
        (gw.getWidth() + (RAINBOW_SIZE * 2) - (RAINBOW_THICKNESS * i) * 2);
    double y = RAINBOW_THICKNESS * i;
    double x = (RAINBOW_THICKNESS * i) - RAINBOW_SIZE;
    gw.setColor(colorToString((Color)i));
    gw.fillOval(x, y, width, width);
  }
}

string colorToString(Color color) {
  switch (color) {
  case RED:
    return "RED";
  case ORANGE:
    return "ORANGE";
  case YELLOW:
    return "YELLOW";
  case GREEN:
    return "GREEN";
  case BLUE:
    return "BLUE";
  case MAGENTA:
    return "MAGENTA";
  case CYAN:
    return "CYAN";
  default:
    return "BLACK";
  }
}
