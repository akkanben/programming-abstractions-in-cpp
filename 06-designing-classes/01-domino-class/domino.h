#ifndef _point_h
#define _point_h

#include <iostream>
#include <string>

class Domino {

private:
  int leftDots;
  int rightDots;

public:
  Domino();
  Domino(int leftDots_i, int rightDots_i);
  int getLeftDots();
  int getRightDots();
  std::string toString();
};

#endif
