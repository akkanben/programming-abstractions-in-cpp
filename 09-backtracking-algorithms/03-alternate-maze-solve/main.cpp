/* Programming Abstractions in C++
 *
 * Exercise 09-03
 *
 * As the result of the preceding exercise makes clear, the idea of keeping
 * track of the path through a maze by using the markSquare facility in the Maze
 * class has a substantial cost. A more practical approach is to change the
 * definition of the recursive function so that it keeps track of the current
 * path as it goes. Following the logic of solveMaze, write a function
 *
 *  bool findSolutionPath(Maze & maze, Point start, Vector<Point> & path);
 *
 * that takes, in addition to the coordinates of the starting position, a vector
 * of Point values called path. Like solveMaze, findSolutionPath returns a
 * Boolean value indicating whether the maze is solvable. In addition, the
 * findSolutionPath function initializes the elements of the path vector to a
 * sequence of coordinates beginning with the starting position and ending with
 * the coordinates of the first square that lies outside the maze. For this
 * exercise, it is sufficient for findPath to find any solution path. It need
 * not find the shortest one.
 *
 * Solution 2021 Ben Mills
 *
 * This is already the basic approach I have used in exercise 09-01 and 09-02.
 * The download that included maze.cpp and maze.h included this general setup
 * already:
 * https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1134/lectures/08-RecursiveBacktracking/08-RecursiveBacktracking.zip
 *
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/direction.h"
#include "../../StanfordCPPLib/include/point.h"
#include "../../StanfordCPPLib/include/vector.h"
#include "maze.h"

bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path);
Point adjacentPoint(Point start, Direction dir);
void unmarkAllSquares(Maze &maze);
void markPath(Maze &maze, Vector<Point> path);

int main() {
  GWindow gw;
  Maze maze("maze.txt", gw);
  Vector<Point> path;
  if (findSolutionPath(maze, maze.getStartPosition(), path)) {
    unmarkAllSquares(maze);
    markPath(maze, path);
    std::cout << path << std::endl;
  }
  return 0;
}

bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path) {
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
      if (findSolutionPath(maze, neighbor, path)) {
        return true;
      }
    }
  }
  path.remove(path.size() - 1);
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

void markPath(Maze &maze, Vector<Point> path) {
  for (int i = 0; i < path.size(); i++) {
    maze.markSquare(path[i]);
  }
}

void unmarkAllSquares(Maze &maze) {
  for (int x = 0; !maze.isOutside(Point(x, 0)); x++) {
    for (int y = 0; !maze.isOutside(Point(0, y)); y++) {
      maze.unmarkSquare(Point(x, y));
    }
  }
}
