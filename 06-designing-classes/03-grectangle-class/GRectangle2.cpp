#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/gtypes.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "GRectangle2.h"

GRectangle2::GRectangle2() {
  width = 0;
  height = 0;
}

GRectangle2::GRectangle2(double x_i, double y_i, double width_i,
                         double height_i) {
  x = x_i;
  y = y_i;
  width = width_i;
  height = height_i;
}

double GRectangle2::getX() { return x; }

double GRectangle2::getY() { return y; }

double GRectangle2::getWidth() { return width; }

double GRectangle2::getHeight() { return height; }

bool GRectangle2::isEmpty() { return width <= 0 && height <= 0 ? true : false; }

bool GRectangle2::contains(GPoint pt) {
  bool withinX = pt.getX() >= x && pt.getX() <= x + width;
  bool withinY = pt.getY() >= y && pt.getY() <= y + height;
  return withinX && withinY ? true : false;
}

bool GRectangle2::contains(double x, double y) {
  GPoint pt(x, y);
  return contains(pt);
}

std::string GRectangle2::toString() {
  return "(" + integerToString(x) + ", " + integerToString(y) + ", " +
         integerToString(width) + ", " + integerToString(height) + ")";
}

bool operator==(const GRectangle2 &rect1, const GRectangle2 &rect2) {
  if (rect1.x == rect2.x && rect1.y == rect2.y && rect1.width == rect2.width &&
      rect1.height == rect2.height)
    return true;
  return false;
}

bool operator!=(const GRectangle2 &rect1, const GRectangle2 &rect2) {
  return rect1 == rect2 ? false : true;
}
