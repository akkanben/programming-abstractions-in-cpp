/* Programming Abstractions in C++
 *
 * Exercise 05-18
 *
 * Write a program to simulate the following experiment, which was included in
 * the 1957 Disney film Our Friend the Atom, to illustrate the chain reactions
 * involved in nuclear fission. The setting for the experiment is a large
 * cubical box, the bottom of which is completely covered with 625 mousetraps
 * arranged to form a square grid 25 mousetraps on a side. Each of the
 * mousetraps is initially loaded with two ping-pong balls. At the beginning of
 * the simulation, an additional ping-pong ball is released from the top of the
 * box and falls on one of the mousetraps. That mousetrap springs and shoots its
 * two ping-pong balls into the air. The ping-pong balls bounce around the sides
 * of the box and eventually land on the floor, where they are likely to set off
 * more mousetraps. In writing this simulation, you should make the following
 * simplifying assumptions:
 *
 *  • Every ping-pong ball that falls always lands on a mousetrap, chosen
 *    randomly by selecting a random row and column in the grid. If the trap is
 *    loaded, its balls are released into the air. If the trap has already been
 *    sprung, having a ball fall on it has no effect.
 *
 *  • Once a ball falls on a mousetrap—whether or not the trap is sprung—that
 *    ball stops and takes no further role in the simulation.
 *
 *  • Balls launched from a mousetrap bounce around the room and land again
 *    after a random number of simulation cycles have gone by. That random
 *    interval is chosen independently for each ball and is always between one
 *    and four cycles.
 *
 * Your simulation should run until there are no balls in the air. At that
 * point, your program should report how many time units have elapsed since the
 * beginning, what percentage of the traps have been sprung, and the maximum
 * number of balls in the air at any time in the simulation.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/queue.h"
#include "../../StanfordCPPLib/include/random.h"

const int GRID_SIZE = 25;
const int BALLS_PER_TRAP = 2;
const int MIN_BALL_CYCLES = 1;
const int MAX_BALL_CYCLES = 4;

void runSimulation(int &timeElapsed, int &numSprung, int &maxAirborne);
void printReport(int timeElapsed, int numSprung, int maxAirborne);

int main() {
  int timeElapsed = 0;
  int numSprung = 0;
  int maxAirborne = 0;
  runSimulation(timeElapsed, numSprung, maxAirborne);
  printReport(timeElapsed, numSprung, maxAirborne);
  return 0;
}

void runSimulation(int &timeElapsed, int &numSprung, int &maxAirborne) {
  int ballsInAir = 0;
  Queue<int> queue;
  queue.enqueue(randomInteger(MIN_BALL_CYCLES, MAX_BALL_CYCLES));
  ballsInAir++;
  Grid<int> grid(GRID_SIZE, GRID_SIZE);
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid.set(i, j, BALLS_PER_TRAP);
    }
  }
  while (ballsInAir > 0) {
    if (queue.peek() > 0) {
      queue.enqueue(queue.dequeue() - 1);
    } else {
      int currentX = randomInteger(0, GRID_SIZE - 1);
      int currnetY = randomInteger(0, GRID_SIZE - 1); //
      if (grid.get(currentX, currnetY) > 0) {
        ballsInAir--;
        grid.set(currentX, currnetY, 0);
        queue.enqueue(randomInteger(MIN_BALL_CYCLES, MAX_BALL_CYCLES));
        queue.enqueue(randomInteger(MIN_BALL_CYCLES, MAX_BALL_CYCLES));
        ballsInAir += 2;
        numSprung++;
      } else {
        ballsInAir--;
      }
      if (maxAirborne < ballsInAir) {
        maxAirborne = ballsInAir;
      }
    }
    timeElapsed++;
  }
}

void printReport(int timeElapsed, int numSprung, int maxAirborne) {
  double totalGrid = (GRID_SIZE * GRID_SIZE);
  double totalNumSprung = numSprung / totalGrid * 100.0;
  std::cout << "---------- RESULTS --------------" << std::endl;
  std::cout << "Max number of balls airborne: " << maxAirborne << std::endl;
  std::cout << "Percentage of traps sprung:   " << totalNumSprung << "%"
            << std::endl;
  std::cout << "Total time units elapsed:     " << timeElapsed << std::endl;
}
