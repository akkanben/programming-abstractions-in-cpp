#include <string>

#include "domino.h"

Domino::Domino() {
  dotA = 0;
  dotB = 0;
}

Domino::Domino(int dA, int dB) {
  dotA = dA;
  dotB = dB;
}

int Domino::getDotA() { return dotA; }

int Domino::getDotB() { return dotB; }

void Domino::flip() {
  int dotC = dotA;
  dotA = dotB;
  dotB = dotC;
}

string Domino::toString() {
  return "[" + integerToString(dotA) + "|" + integerToString(dotB) + "]";
}

bool operator==(Domino tile1, Domino tile2) {
  return tile1.dotA == tile2.dotA && tile1.dotB == tile2.dotB;
}

bool operator!=(Domino tile1, Domino tile2) { return !(tile1 == tile2); }

ostream &operator<<(ostream &os, Domino tile) { return os << tile.toString(); }

/* Functions */

Vector<Domino> getVectorOfDominoes(int numSides) {
  Vector<Domino> dominoTiles;
  for (int i = 0; i <= numSides; i++) {
    for (int j = 0; j <= numSides; j++) {
      if (i <= j) {
        Domino tile(i, j);
        dominoTiles.add(tile);
      }
    }
  }
  return dominoTiles;
}
