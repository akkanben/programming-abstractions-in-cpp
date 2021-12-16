#include <string>

#include "cube.h"

Cube::Cube() {
  // empty
}

Cube::Cube(char s0, char s1, char s2, char s3, char s4, char s5) {
  side0 = s0;
  side1 = s1;
  side2 = s2;
  side3 = s3;
  side4 = s4;
  side5 = s5;
}

char Cube::getFace(int sideNum) {
  switch (sideNum) {
  case 0:
    return side0;
  case 1:
    return side1;
  case 2:
    return side2;
  case 3:
    return side3;
  case 4:
    return side4;
  case 5:
    return side5;
  default:
    return -1;
  }
}

Vector<char> Cube::getRotationSides(int head) {
  Vector<char> vec;
  switch (head) {
  case 0:
    return vec += side1, side4, side3, side2;
  case 1:
    return vec += side0, side2, side5, side4;
  case 2:
    return vec += side0, side3, side5, side1;
  case 3:
    return vec += side0, side4, side5, side2;
  case 4:
    return vec += side0, side1, side5, side3;
  case 5:
    return vec += side3, side4, side1, side2;
  default:
    return vec;
  }
}

string Cube::toString() {
  std::string output = "{ ";
  output += side0;
  output += ", ";
  output += side1;
  output += ", ";
  output += side2;
  output += ", ";
  output += side3;
  output += ", ";
  output += side4;
  output += ", ";
  output += side5;
  output += " }";
  return output;
}
