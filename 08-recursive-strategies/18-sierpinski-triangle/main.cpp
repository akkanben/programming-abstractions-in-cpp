/* Programming Abstractions in C++
 *
 * Exercise
 *
 * Another interesting fractal is the Sierpinski Triangle, named after its
 * inventor, the Polish mathematician Wac!aw Sierpi"ski (1882–1969). The order-0
 * Sierpinski Triangle is an equilateral triangle:
 *
 *  <image of equilateral triangle>
 *
 * To create an order-N Sierpinski Triangle, you draw three Sierpinski Triangles
 * of order N – 1, each of which has half the edge length of the original. Those
 * three triangles are placed in the corners of the larger triangle, which means
 * that the order-1 Sierpinski Triangle looks like this:
 *
 *  <image of order-1 Sierpinski Triangle>
 *
 * The downward-pointing triangle in the middle of this figure is not drawn
 * explicitly, but is instead formed by the sides of the other three triangles.
 * That area, moreover, is not recursively subdivided and will remain unchanged
 * at every level of the fractal decomposition. Thus, the order-2 Sierpinski
 * Triangle has the same open area in the middle:
 *
 *  <image of order-2 Sierpinski Triangle>
 *
 * If you continue this process through three more recursive levels, you get the
 * order-5 Sierpinski Triangle, which looks like this:
 *
 *  <image of order-3 Sierpinski Triangle>
 *
 * Write a program that asks the user for an edge length and a fractal order
 * and draws the resulting Sierpinski Triangle in the center of the graphics
 * window.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/gwindow.h"
#include "../../StanfordCPPLib/include/simpio.h"

void drawSierpinski(GWindow &gw, double x, double y, double size, int order);

int main() {
  double edge = getReal("Enter a outer edge size in pixels: ");
  int order = getInteger("Enter a fractal order size: ");
  int windowSize = edge + edge * 0.2;
  GWindow gw(windowSize, windowSize);
  double x = gw.getWidth() / 2;
  double y = gw.getHeight() / 2 - edge / 2;
  drawSierpinski(gw, x, y, edge, order);
  return 0;
}

void drawSierpinski(GWindow &gw, double x, double y, double size, int order) {
  double reducedSize = size / 2;
  if (order == 0) {
    gw.drawLine(x, y, x - reducedSize, y + size);
    gw.drawLine(x - reducedSize, y + size, x + reducedSize, y + size);
    gw.drawLine(x + reducedSize, y + size, x, y);
  } else {
    drawSierpinski(gw, x, y, size, order - 1);
    drawSierpinski(gw, x, y, size / 2, order - 1);
    drawSierpinski(gw, x - (size / 4), y + reducedSize, size / 2, order - 1);
    drawSierpinski(gw, x + (size / 4), y + reducedSize, size / 2, order - 1);
  }
}
