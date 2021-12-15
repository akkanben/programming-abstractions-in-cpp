/* Programming Abstractions in C++
 *
 * Exercise 09-02
 *
 * As implemented in Figure 9-3, the solveMaze function unmarks each square
 * as it discovers there are no solutions from that point. Although this design
 * strategy has the advantage that the final configuration of the maze shows the
 * solution path as a series of marked squares, the decision to unmark squares
 * as you backtrack has a cost in terms of the overall efficiency of the
 * algorithm. If you’ve marked a square and then backtracked through it, you’ve
 * already explored the possibilities leading from that square. If you come back
 * to it by some other path, you might as well rely on your earlier analysis
 * instead of exploring the same options again.
 *
 * To give yourself a sense of how much these unmarking operations cost in
 * terms of efficiency, extend the solveMaze program so that it records the
 * number of recursive calls as it proceeds. Use this program to calculate how
 * many recursive calls are required to solve the following maze if the call to
 * unmarkSquare remains part of the program:
 *
 *  <image of maze>
 *
 * Run your program again, this time without the call to unmarkSquare. What
 * happens to the number of recursive calls?
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
