/* Programming Abstractions in C++
 *
 * Exercise 06-04
 *
 * The classes exported by the gtypes.h interface described in the preceding
 * exercise make it simpler to create intricate graphical patterns, in part
 * because they make it easy to store coordinate information inside collection
 * classes and other abstract data types. In this exercise, for example, you get
 * to have some fun with a vector of GPoint objects. Imagine that you start with
 * a rectangular board and then arrange pegs around the edges so that they are
 * evenly spaced along all four edges, with N_ACROSS pegs along the top and
 * bottom and N_DOWN pegs along the left and right edges. To model this process
 * using the graphics window, what you want to do is create a Vector<GPoint>
 * that holds the coordinates of each of these pegs, which are inserted into the
 * vector starting at the upper right and then proceeding clockwise around the
 * edges of the rectangle, as follows:
 *
 *  <image of numbered pegs>
 *
 * From here, you create a figure by drawing lines between the pegs, starting
 * at peg 0 and then moving ahead a fixed number of spaces on each cycle, as
 * specified by the constant DELTA. For example, if DELTA is 11, the first line
 * goes from peg 0 to peg 11, the second goes from peg 11 to peg 22, and the
 * third—which has to count 11 pegs clockwise past the beginning—goes from
 *
 *  <figure 6-13>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/gtypes.h"
#include "../../StanfordCPPLib/include/gwindow.h"
#include "../../StanfordCPPLib/include/vector.h"

const int N_ACROSS = 50;
const int N_DOWN = 30;
const int DELTA = 67;

void createPoints(Vector<GPoint> &vec, GWindow &window);
void drawStringPattern(Vector<GPoint> &vec, GWindow &window);

int main() {
  GWindow window;
  Vector<GPoint> vec;
  createPoints(vec, window);
  drawStringPattern(vec, window);
  return 0;
}

void createPoints(Vector<GPoint> &vec, GWindow &window) {
  const int W_WIDTH = window.getWidth();
  const int W_HEIGHT = window.getHeight();
  const int H_PEG_SPACER = W_WIDTH / N_ACROSS;
  const int V_PEG_SPACER = W_HEIGHT / N_DOWN;
  // Top row
  for (int i = 0; i < N_ACROSS; i++) {
    GPoint point(H_PEG_SPACER * i, 0);
    vec.add(point);
  }
  // Right column
  for (int i = 0; i < N_DOWN; i++) {
    GPoint point(W_WIDTH, V_PEG_SPACER * i);
    vec.add(point);
  }
  // Bottom row
  for (int i = 0; i < N_ACROSS; i++) {
    GPoint point(W_WIDTH - (H_PEG_SPACER * i), W_HEIGHT);
    vec.add(point);
  }
  // Left Column
  for (int i = 0; i < N_DOWN; i++) {
    GPoint point(0, (W_HEIGHT - (V_PEG_SPACER * i)));
    vec.add(point);
  }
}

void drawStringPattern(Vector<GPoint> &vec, GWindow &window) {
  for (int i = 0; i < vec.size(); i++) {
    if (i == 0) {
      window.drawLine(vec[i], vec[i + (DELTA)]);
    } else {
      window.drawLine(vec[i], vec[(i + DELTA) % vec.size()]);
    }
  }
}
