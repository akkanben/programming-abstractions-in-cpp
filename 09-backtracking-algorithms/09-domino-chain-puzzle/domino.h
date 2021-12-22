#ifndef _point_h
#define _point_h

#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>
#include <string>

class Domino {

public:
  Domino();
  Domino(int dA, int dB);

  int getDotA();
  int getDotB();
  void flip();
  std::string toString();
  friend bool operator==(Domino tile1, Domino tile2);

private:
  int dotA;
  int dotB;
};

bool operator==(Domino tile1, Domino tile2);
bool operator!=(Domino tile1, Domino tile2);
std::ostream &operator<<(std::ostream &os, Domino tile);

Vector<Domino> getVectorOfDominoes(int numSides);

#endif
