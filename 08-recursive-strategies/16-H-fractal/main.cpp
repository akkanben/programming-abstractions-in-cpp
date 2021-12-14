/* Programming Abstractions in C++
 *
 * Exercise
 *
 * If you search the web for fractal designs, you will find many intricate
 * wonders beyond the Koch snowflake illustrated in this chapter. H-fractal, in
 * which the repeated pattern is shaped like an elongated letter H in which the
 * horizontal bar and vertical lines on the sides have the same length. Thus,
 * the order-0 H- fractal looks like this:
 *
 *  <image of order 0 fractal H>
 *
 * To create the order-1 fractal, all
 * you do is add four new H-fractals—each one half of the original size—at each
 * open end of the order-0 fractal, like this:
 *
 *  <image of order 1 fractal H>
 *
 * To create the order-2 fractal,
 * all you have to do is add even smaller H-fractals (again half the size of the
 * fractal to which they connect) to each of the open endpoints. This process
 * gives rise to the following order-2 fractal:
 *
 *  <image of order 2 fractal H>
 *
 * Write a recursive function
 *
 *  drawHFractal(GWindow & gw, double x, double y, double size, int order);
 *
 * where x and y are the coordinates of the center of the H-fractal, size
 * specifies the width and the height, and order indicates the order of the
 * fractal. As an example, the main program
 *
 *  int main() {
 *    GWindow gw;
 *    double xc = gw.getWidth() / 2;
 *    double yc = gw.getHeight() / 2;
 *    drawHFractal(gw, xc, yc, 100, 3);
 *    return 0;
 *  }
 *
 * would draw an order-3 H-fractal at the center of the graphics window, like
 * this:
 *
 *  <image of order 3 fractal H>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/gwindow.h"

void drawHFractal(GWindow gw, double x, double y, double size, int order);

int main() {
  GWindow gw;
  double cx = gw.getWidth() / 2;
  double cy = gw.getHeight() / 2;
  drawHFractal(gw, cx, cy, 100, 3);
  return 0;
}

void drawHFractal(GWindow gw, double x, double y, double size, int order) {
  double reducedSize = size / 2.0;
  if (order == 0) {
    gw.drawLine(x - reducedSize, y, x + reducedSize, y);
    gw.drawLine(x - reducedSize, y - reducedSize, x - reducedSize,
                y + reducedSize);
    gw.drawLine(x + reducedSize, y - reducedSize, x + reducedSize,
                y + reducedSize);

  } else {
    drawHFractal(gw, x, y, size, order - 1);
    drawHFractal(gw, x - reducedSize, y - reducedSize, size / 2, order - 1);
    drawHFractal(gw, x - reducedSize, y + reducedSize, size / 2, order - 1);
    drawHFractal(gw, x + reducedSize, y - reducedSize, size / 2, order - 1);
    drawHFractal(gw, x + reducedSize, y + reducedSize, size / 2, order - 1);
  }
}
