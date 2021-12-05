/* Programming Abstractions in C++
 *
 * Exercise 06-03
 *
 * The gtypes.h interface included in Appendix A exports a few useful classes
 * designed to work together with the graphics library. The simplest of these
 * classes is GPoint, which is identical to the Point class from this chapter
 * except for the fact that it uses floating-point numbers for the coordinates
 * instead of integers. Another useful class is GRectangle, which represents a
 * rectangular region defined by the x and y coordinates of its upper left
 * corner along with a width and a height. Using the description of the
 * GRectangle class in Appendix A for reference, implement the GRectangle class.
 *
 * Solution 2021 Ben Mills
 */

#include "GRectangle2.h"

int main() {
  GRectangle2 rect1 = GRectangle2();
  GRectangle2 rect2 = GRectangle2(0, 0, 100, 200);
  GRectangle2 rect3 = GRectangle2(50, 10, 30, 30);
  std::cout << rect1.toString() << std::endl;
  std::cout << rect2.toString() << std::endl;
  std::cout << rect3.toString() << std::endl;
}
