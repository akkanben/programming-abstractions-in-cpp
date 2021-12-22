#ifndef _pegBoard_h_
#define _pegBoard_h_

#include <string>

#include "../../StanfordCPPLib/include/direction.h"
#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/point.h"

class PegBoard {
public:
  PegBoard(int cRows, int cColumns, int cCornerSize);

  Vector<Point> getListOfPegs();

  Vector<Point> getThreatenedPegs();

  int numPegsLeft();

  bool pegIsThreatened(Point p);

  bool pegInCenter();

  bool canBeJumpedFrom(Point p, Direction dir);

  bool isOnBoard(Point p);

  bool isHole(Point p);

  bool isPeg(Point p);

  void jump(Point p, Direction dir);

  void unJump(Point p, Direction dir);

  std::string toString();

private:
  int numRows;
  int numColumns;
  int cornerSize;
  Grid<char> board;

  Point p;
  Point hole;
  Direction dir;
};

#endif
