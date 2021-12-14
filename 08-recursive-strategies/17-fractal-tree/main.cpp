/* Programming Abstractions in C++
 *
 * Exercise
 *
 * To celebrate its 550th anniversary in 2008, Magdalen College at Oxford
 * commissioned the English artist Mark Wallinger to create a sculpture called Y
 * that has a decidedly recursive structure. A photograph of the sculpture
 * appears at the left of Figure 8-7 and a diagram illustrating its fractal
 * nature appears at the right. Given its branching structure, the underlying
 * pattern in Wallinger’s sculpture is called a fractal tree. The tree begins as
 * a simple trunk indicated by a straight vertical line, as follows:
 *
 *  <image of first order fractal tree>
 *
 * The trunk may branch at the top to form two lines that veer off at an angle,
 * as shown:
 *
 *  <image of second order fractal tree>
 *
 *  <image of eighth order fractal tree>
 *
 * These branches may themselves split to form new branches, which split to
 * form new ones, and so on.
 *
 * Write a program that uses the graphics library to draw the fractal tree in
 * Wallinger’s sculpture. If you carry this process on to the eighth-order
 * fractal, you get the image on the right of Figure 8-7.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/gwindow.h"
#include <stdio.h>

const double SIZE = 300;
const int ORDER = 8;

void drawFractalTree(GWindow &gw, GPoint pt, double r, double theta, int order);

int main() {
  GWindow gw(1200, 800);
  GPoint pt(gw.getWidth() / 2, gw.getHeight());
  drawFractalTree(gw, pt, SIZE, 90, ORDER);
  return 0;
}

void drawFractalTree(GWindow &gw, GPoint pt, double r, double theta,
                     int order) {
  if (order >= 0) {
    pt = gw.drawPolarLine(pt, r, theta);
    drawFractalTree(gw, pt, r * 0.6, theta + 45, order - 1);
    drawFractalTree(gw, pt, r * 0.6, theta - 45, order - 1);
  }
}
