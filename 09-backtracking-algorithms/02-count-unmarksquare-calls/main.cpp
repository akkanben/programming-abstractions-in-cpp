/* Programming Abstractions in C++
 *
 * Exercise
 *
 * QUESTION
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/direction.h"
#include "../../StanfordCPPLib/include/gwindow.h"
#include "../../StanfordCPPLib/include/point.h"
#include "../../StanfordCPPLib/include/vector.h"
#include "maze.h"

bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path,
                      int &recursiveCalls);
Point adjacentPoint(Point start, Direction dir);

int main() {
  GWindow gw;
  Maze maze("maze.txt", gw);
  Vector<Point> path;
  int recursiveCalls = 0;
  if (findSolutionPath(maze, maze.getStartPosition(), path, recursiveCalls)) {
    foreach (Point pt in path) { std::cout << pt << std::endl; }
  }
  std::cout << recursiveCalls << std::endl;
  return 0;
}

bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path,
                      int &recursiveCalls) {
  recursiveCalls++;
  if (maze.isOutside(start))
    return true;
  if (maze.isMarked(start))
    return false;
  path.add(start);
  maze.markSquare(start);
  pause(10);
  for (Direction dir = NORTH; dir <= WEST; dir++) {
    if (!maze.wallExists(start, dir)) {
      Point neighbor = adjacentPoint(start, dir);
      if (findSolutionPath(maze, neighbor, path, recursiveCalls)) {
        return true;
      }
    }
  }
  path.remove(path.size() - 1);
  // Uncomment unmarkSquare to see how many extra calls
  // are used -- spoilers it's a lot more!
  // You might want to decrease the pause(10) to pause(1)
  // maze.unmarkSquare(start);
  return false;
}

Point adjacentPoint(Point start, Direction dir) {
  switch (dir) {
  case NORTH:
    return Point(start.getX(), start.getY() - 1);
  case EAST:
    return Point(start.getX() + 1, start.getY());
  case SOUTH:
    return Point(start.getX(), start.getY() + 1);
  case WEST:
    return Point(start.getX() - 1, start.getY());
  }
  return start;
}
