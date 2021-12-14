/* Programming Abstractions in C++
 *
 * Exercise 08-15
 *
 * One of the reasons that fractals have generated so much interest is that they
 * turn out to be useful in some surprising practical contexts. For example, the
 * most successful techniques for drawing computer images of mountains and
 * certain other landscape features involve using fractal geometry.
 * As a simple example of where this issue comes up, consider the problem of
 * connecting two points A and B with a fractal that looks like a coastline on a
 * map. The simplest possible strategy would be to draw a straight line between
 * the two points:
 *
 *  A ---------------- B
 *
 * This is the order-0 coastline and represents the base case of the recursion.
 * Of course, a real coastline will have small peninsulas or inlets somewhere
 * along its length, so you would expect a realistic drawing of a coastline to
 * jut in or out occasionally like a real one. As a first approximation, you
 * could replace the straight line with the same fractal line used to create the
 * snowflake fractal, as follows:
 *
 *           /\
 *          /  \
 *  A _____/    \_____ B
 *
 * This process gives the order-1 coastline. However, in order to give the
 * feeling of a traditional coastline, it is important for the triangular wedge
 * in this line sometimes to point up and sometimes down, with equal
 * probability.
 *
 * If you then replace each of the straight-line segments in the order-1 fractal
 * with a fractal line in a random direction, you get the order-2 coastline,
 * which might look like this:
 *
 *         _/\
 *         \ /_
 *  A __/\_/   \_  __ B
 *               \/
 *
 * Continuing this process eventually results in a drawing that conveys a
 * remarkably realistic sense, as in this order-5 coastline:
 *
 *  <image of sample run>
 *
 * Write a program to draw a fractal coastline on the graphics window.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/gwindow.h"
#include "../../StanfordCPPLib/include/random.h"

GPoint drawFractalCoastline(GWindow &gw, GPoint pt, double r, double theta,
                            int order);

const double SIZE = 900;
const double RANDOM_CHANCE_VALUE = 0.5;

int main() {
  GWindow gw(1000, 600);
  GPoint pt((gw.getWidth() / 2) - SIZE / 2, gw.getHeight() / 2);
  pt = drawFractalCoastline(gw, pt, SIZE, 0, 5);
  return 0;
}

GPoint drawFractalCoastline(GWindow &gw, GPoint pt, double r, double theta,
                            int order) {
  if (order == 0) {
    return gw.drawPolarLine(pt, r, theta);
  } else {
    pt = drawFractalCoastline(gw, pt, r / 3, theta, order - 1);
    if (randomChance(RANDOM_CHANCE_VALUE)) {
      pt = drawFractalCoastline(gw, pt, r / 3, theta + 60, order - 1);
      pt = drawFractalCoastline(gw, pt, r / 3, theta - 60, order - 1);
    } else {
      pt = drawFractalCoastline(gw, pt, r / 3, theta - 60, order - 1);
      pt = drawFractalCoastline(gw, pt, r / 3, theta + 60, order - 1);
    }
    return drawFractalCoastline(gw, pt, r / 3, theta, order - 1);
  }
}
