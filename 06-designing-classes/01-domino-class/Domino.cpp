#include <string>

#include "../../StanfordCPPLib/include/strlib.h"
#include "Domino.h"

Domino::Domino() {
  leftDots = 0;
  rightDots = 0;
}

Domino::Domino(int leftDots_i, int rightDots_i) {
  leftDots = leftDots_i;
  rightDots = rightDots_i;
}

int Domino::getLeftDots() { return leftDots; }
int Domino::getRightDots() { return rightDots; }

std::string Domino::toString() {
  return "[" + integerToString(leftDots) + "|" + integerToString(rightDots) +
         "]";
}
