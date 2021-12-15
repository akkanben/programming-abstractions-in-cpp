/* Programming Abstractions in C++
 *
 * Exercise
 *
 * In many mazes, there are multiple paths. For example, Figure 9-7 shows three
 * solutions for the same maze. None of these solutions, however, is optimal.
 * The shortest path through the maze has a path length of 11:
 *
 * <image of maze>
 *
 * Write a function
 *
 *  int shortestPathLength(Maze & maze, Point start);
 *
 * that returns the length of the shortest path in the maze from the specified
 * position to any exit. If there is no solution, shortestPathLength should
 * return –1.
 *
 * Solution 2021 Ben Mills
 *
 * maze.h and maze.cpp code from:
 * https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1134/lectures/08-RecursiveBacktracking/08-RecursiveBacktracking.zip
 *
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/direction.h"
#include "../../StanfordCPPLib/include/point.h"
#include "../../StanfordCPPLib/include/vector.h"
#include "maze.h"

/* Function prototypes */

int shortestPathLength(Maze &maze, Point start);
bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path,
                      Vector<int> &count);
Point adjacentPoint(Point start, Direction dir);
int getLowestCount(Vector<int> vec);

/* Main program */

int main() {
  GWindow gw;
  Maze maze("maze.txt", gw);
  std::cout << "The shortest path is "
            << shortestPathLength(maze, maze.getStartPosition())
            << " spaces long." << std::endl;
  return 0;
}

int shortestPathLength(Maze &maze, Point start) {
  Vector<int> count;
  Vector<Point> path;
  if (findSolutionPath(maze, maze.getStartPosition(), path, count) ||
      count.size() > 0) {
    return getLowestCount(count);
  } else {
    return -1;
  }
}

int getLowestCount(Vector<int> vec) {
  int total = vec[0];
  for (int i = 1; i < vec.size(); i++) {
    if (vec[i] < total) {
      total = vec[i];
    }
  }
  return total;
}

bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path,
                      Vector<int> &count) {
  if (maze.isOutside(start)) {
    count.add(path.size());
    return false;
  }
  if (maze.isMarked(start))
    return false;
  path.add(start);
  pause(10);
  maze.markSquare(start);
  for (Direction dir = NORTH; dir <= WEST; dir++) {
    if (!maze.wallExists(start, dir)) {
      Point neighbor = adjacentPoint(start, dir);
      if (findSolutionPath(maze, neighbor, path, count)) {
        return true;
      }
    }
  }
  path.remove(path.size() - 1);
  maze.unmarkSquare(start);
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
