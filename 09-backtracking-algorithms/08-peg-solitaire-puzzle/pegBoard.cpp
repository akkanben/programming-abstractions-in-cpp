#include <iostream>
#include <string>

#include "pegBoard.h"

const char EMPTY_SPACE = '.';
const char PEG = 'x';
const char HOLE = 'O';
const int START_HOLE_POINT = 3;

PegBoard::PegBoard(int cRows, int cColumns, int cCornerSize) {
  numRows = cRows;
  numColumns = cColumns;
  cornerSize = cCornerSize;
  board.resize(numRows, numColumns);
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      if ((i < cornerSize && j < cornerSize) ||
          (i < cornerSize && j >= (numColumns - cornerSize)) ||
          (i >= (numRows - cornerSize) && j < cornerSize) ||
          (i >= (numRows - cornerSize) && j >= (numRows - cornerSize))) {
        board.set(i, j, EMPTY_SPACE);
      } else if (i == START_HOLE_POINT && j == START_HOLE_POINT) {
        board.set(i, j, HOLE);
      } else {
        board.set(i, j, PEG);
      }
    }
  }
}

Vector<Point> PegBoard::getListOfPegs() {
  Vector<Point> list;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      Point test = Point(j, i);
      std::string kind = isPeg(test) ? "peg" : "not peg";
      if (isOnBoard(Point(j, i)) && isPeg(Point(j, i))) {
        list.add(Point(j, i));
      }
    }
  }
  return list;
}

Vector<Point> PegBoard::getThreatenedPegs() {
  Vector<Point> output;
  Vector<Point> list = getListOfPegs();
  for (int i = 0; i < list.size(); i++) {
    if (pegIsThreatened(list[i])) {
      output.add(list[i]);
    }
  }
  return output;
}

int PegBoard::numPegsLeft() {
  int count = 0;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      Point check(i, j);
      if (isOnBoard(check) && board.get(i, j) == PEG) {
        count++;
      }
    }
  }
  return count;
}

bool PegBoard::pegIsThreatened(Point p) {
  Point north = Point(p.getX(), p.getY() + 1);
  Point east = Point(p.getX() + 1, p.getY());
  Point south = Point(p.getX(), p.getY() - 1);
  Point west = Point(p.getX() - 1, p.getY());
  if (isOnBoard(north) && isOnBoard(south) &&
      ((isPeg(north) && isHole(south)) || (isPeg(south) && isHole(north))))
    return true;
  else if (isOnBoard(east) && isOnBoard(west) &&
           ((isPeg(east) && isHole(west)) || (isPeg(west) && isHole(east))))
    return true;
  else
    return false;
}

bool PegBoard::pegInCenter() {
  return isPeg(Point(board.numCols() / 2, board.numRows() / 2));
}

bool PegBoard::canBeJumpedFrom(Point p, Direction dir) {
  Point jumpingPeg;
  Point landingHole;
  switch (dir) {
  case NORTH:
    jumpingPeg = Point(p.getX(), p.getY() - 1);
    landingHole = Point(p.getX(), p.getY() + 1);
    break;
  case EAST:
    jumpingPeg = Point(p.getX() + 1, p.getY());
    landingHole = Point(p.getX() - 1, p.getY());
    break;
  case SOUTH:
    jumpingPeg = Point(p.getX(), p.getY() + 1);
    landingHole = Point(p.getX(), p.getY() - 1);
    break;
  case WEST:
    jumpingPeg = Point(p.getX() - 1, p.getY());
    landingHole = Point(p.getX() + 1, p.getY());
    break;
  default:
    break;
  }
  return isHole(landingHole) && isPeg(jumpingPeg) ? true : false;
}

bool PegBoard::isOnBoard(Point p) {
  if (board.inBounds(p.getY(), p.getX()) &&
      board.get(p.getY(), p.getX()) != EMPTY_SPACE) {
    return true;
  } else {
    return false;
  }
}

bool PegBoard::isHole(Point p) {
  if (isOnBoard(p) && board.get(p.getY(), p.getX()) == HOLE) {
    return true;
  } else {
    return false;
  }
}

bool PegBoard::isPeg(Point p) {
  if (isOnBoard(p) && board.get(p.getY(), p.getX()) == PEG) {
    return true;
  } else {
    return false;
  }
}

void PegBoard::jump(Point p, Direction dir) {
  switch (dir) {
  case NORTH:
    board.set(p.getY(), p.getX(), HOLE);
    board.set(p.getY() - 1, p.getX(), HOLE);
    board.set(p.getY() + 1, p.getX(), PEG);
    break;
  case EAST:
    board.set(p.getY(), p.getX(), HOLE);
    board.set(p.getY(), p.getX() + 1, HOLE);
    board.set(p.getY(), p.getX() - 1, PEG);
    break;
  case SOUTH:
    board.set(p.getY(), p.getX(), HOLE);
    board.set(p.getY() + 1, p.getX(), HOLE);
    board.set(p.getY() - 1, p.getX(), PEG);
    break;
  case WEST:
    board.set(p.getY(), p.getX(), HOLE);
    board.set(p.getY(), p.getX() - 1, HOLE);
    board.set(p.getY(), p.getX() + 1, PEG);
    break;
  default:
    break;
  }
}

void PegBoard::unJump(Point p, Direction dir) {
  switch (dir) {
  case NORTH:
    board.set(p.getY(), p.getX(), PEG);
    board.set(p.getY() - 1, p.getX(), PEG);
    board.set(p.getY() + 1, p.getX(), HOLE);
    break;
  case EAST:
    board.set(p.getY(), p.getX(), PEG);
    board.set(p.getY(), p.getX() + 1, PEG);
    board.set(p.getY(), p.getX() - 1, HOLE);
    break;
  case SOUTH:
    board.set(p.getY(), p.getX(), PEG);
    board.set(p.getY() + 1, p.getX(), PEG);
    board.set(p.getY() - 1, p.getX(), HOLE);
    break;
  case WEST:
    board.set(p.getY(), p.getX(), PEG);
    board.set(p.getY(), p.getX() - 1, PEG);
    board.set(p.getY(), p.getX() + 1, HOLE);
    break;
  default:
    break;
  }
}
std::string PegBoard::toString() {
  string str;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      str += board.get(i, j);
      str += ' ';
    }
    str += '\n';
  }
  return str;
}
