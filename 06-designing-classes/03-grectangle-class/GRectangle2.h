#ifndef _grectangle2_h
#define _grectangle2_h

#include "../../StanfordCPPLib/include/gtypes.h"

class GRectangle2 {
public:
  GRectangle2();
  GRectangle2(double x_i, double y_i, double width_i, double height_i);
  double getX();
  double getY();
  double getWidth();
  double getHeight();
  bool isEmpty();
  bool contains(GPoint pt);
  bool contains(double x_i, double y_i);
  std::string toString();
  friend bool operator==(const GRectangle2 &rect1, const GRectangle2 &rect2);
  friend bool operator!=(const GRectangle2 &rect1, const GRectangle2 &rect2);

private:
  double x;
  double y;
  double width;
  double height;
};

#endif
