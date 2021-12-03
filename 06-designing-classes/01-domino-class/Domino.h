#ifndef _domino_h
#define _domino_h

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
