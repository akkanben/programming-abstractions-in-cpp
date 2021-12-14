/* Programming Abstractions in C++
 *
 * Exercise
 *
 * In countries like the United States that still use the traditional English
 * system of measurement, each inch on a ruler is marked off into fractions
 * using tick marks that look like this:
 *
 *    _._:_._i_._|_._i_._:_._
 *
 * The longest tick mark falls at the half-inch position, two smaller tick marks
 * indicate the quarter inches, and even smaller ones are used to mark the
 * eighths and sixteenths. Write a recursive program that draws a 1-inch line at
 * the center of the graphics window and then draws the tick marks shown in the
 * diagram. Assume that the length of the tick mark indicating the half-inch
 * position is given by the constant definition
 *
 *  const double HALF_INCH_TICK = 0.2;
 *
 * and that each smaller tick mark is half the size of the next larger one.
 *
 * Solution 2021 Ben Mills
 */

#include <stdio.h>

#include "../../StanfordCPPLib/include/gwindow.h"

void oneInchLine(GWindow &gw, double tickSize, double xPos);

const int TICK_SIZER = 600;
const double HALF_INCH_TICK = 0.5 * TICK_SIZER;
const double SIXTEENTH_INCH_TICK = 0.0625 * TICK_SIZER;

int main() {
  GWindow gw(TICK_SIZER * 2, HALF_INCH_TICK * 1.5);
  oneInchLine(gw, HALF_INCH_TICK, gw.getWidth() / 2);
  return 0;
}

void oneInchLine(GWindow &gw, double tickSize, double xPos) {
  if (tickSize >= SIXTEENTH_INCH_TICK) {
    gw.drawLine(xPos, gw.getHeight(), xPos, gw.getHeight() - tickSize);
    oneInchLine(gw, tickSize / 2, xPos - tickSize);
    oneInchLine(gw, tickSize / 2, xPos + tickSize);
  }
}
