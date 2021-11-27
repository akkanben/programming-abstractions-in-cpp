/* Programming Abstractions in C++
 *
 * Exercise 01-12
 *
 * You can also compute PI by approximating the area bounded by a circular arc.
 * Consider the following quarter circle which has a radius r equal to two
 * inches.
 *
 * From the formula for the area of a circle, you can easily determine that the
 * area of the quarter circle should be PI square inches.
 *
 * You can also approximate the area computationally by adding
 * up the areas of a series of rectangles, where each rectangle has a fixed
 * width and the height is chosen so that the circle passes through the midpoint
 * of the top of the rectangle. For example, if you divide the area into 10
 * rectangles from left to right (see diagram).
 *
 * The sum of the areas of the rectangles approximates the area of the quarter
 * circle. The more rectangles there are, the closer the approximation.
 *
 * For each rectangle, the width w is a constant derived by dividing the radius
 * by the number of rectangles. The height h, on the other hand, varies
 * depending on the position of the rectangle. If the midpoint of the rectangle
 * in the horizontal direction is given by x, the height of the rectangle can be
 * computed using the sqrt function to express the distance formula
 *
 * h = sqrt of r^2 - x^2
 *
 * The area of each rectangle is then simply h * w.
 *
 * Write a program to compute the area of the quarter circle by dividing it into
 * 10,000 rectangles.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <math.h>

int const NUMBER_OF_RECTANGLES = 10000;
double const RADIUS = 2.0;
double const WIDTH = RADIUS / NUMBER_OF_RECTANGLES;

int main() {
  double x = WIDTH / 2;
  double h = 0.0;
  double area = 0.0;
  for (int i = 0; i < NUMBER_OF_RECTANGLES; i++) {
    h = sqrt((RADIUS * RADIUS) - (x * x));
    area += (h * WIDTH);
    x += WIDTH;
  }
  std::cout << area << std::endl;
}
