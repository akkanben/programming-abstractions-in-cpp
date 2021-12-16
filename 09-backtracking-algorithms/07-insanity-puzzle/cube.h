/*
 * cube.h
 *
 * Cube class to define a cube of 6 sides.
 * Cube sides are numbered top to bottom left to right when viewed in the
 * flat diagram in the book.
 *
 *      0
 *  1 2 3 4
 *      5
 *
 */

#ifndef _cube_h_
#define _cube_h_

#include <string>

#include "../../StanfordCPPLib/include/vector.h"

class Cube {

public:
  Cube();
  Cube(char s0, char s1, char s2, char s3, char s4, char s5);
  char getFace(int sideNum);

  // This function will return a vector of just the 4 sides we need to test
  // against the other cubes (not the hidden "heads"). We just supply the cube
  // object and which side we are using as a head. The returned vector will
  // never include the head or the side opposite the head in 3d space.
  Vector<char> getRotationSides(int head);

  std::string toString();

private:
  char side0;
  char side1;
  char side2;
  char side3;
  char side4;
  char side5;
};

#endif
