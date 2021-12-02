/* Programming Abstractions in C++
 *
 * Exercise 05-17
 *
 * As a second extension to the checkout-line simulation, change the program
 * from the previous exercise so that there is a single waiting line served by
 * multiple cashiers—a practice that has become more common in recent years.
 * In each cycle of the simulation, any cashier that becomes idle serves the
 * next customer in the queue. If you compare the data produced by this exercise
 * and the preceding one, what can you say about the relative advantages of
 * these two strategies?
 *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>

#include "../../StanfordCPPLib/include/queue.h"
#include "../../StanfordCPPLib/include/random.h"

const double ARRIVAL_PROBABILITY = 0.05;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;
const int SIMULATION_TIME = 2000;

void runSimulation(int &nServed, int &totalWait, int &totalLength);
void printReport(int nSer, int totalWait, int totalLength);

int main() {
  int nServed;
  int totalWait;
  int totalLength;
  runSimulation(nServed, totalWait, totalLength);
  printReport(nServed, totalWait, totalLength);
  return 0;
}

void runSimulation(int &nServed, int &totalWait, int &totalLength) {
  Queue<int> queue;
  int timeRemainingA = 0;
  int timeRemainingB = 0;
  int timeRemainingC = 0;
  nServed = 0;
  totalWait = 0;
  totalLength = 0;
  for (int t = 0; t < SIMULATION_TIME; t++) {
    if (randomChance(ARRIVAL_PROBABILITY)) {
      queue.enqueue(t);
    }
    if (timeRemainingA > 0) {
      timeRemainingA--;
    } else if (!queue.isEmpty()) {
      totalWait += t - queue.dequeue();
      nServed++;
      timeRemainingA = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
    }
    if (timeRemainingB > 0) {
      timeRemainingB--;
    } else if (!queue.isEmpty()) {
      totalWait += t - queue.dequeue();
      nServed++;
      timeRemainingB = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
    }
    if (timeRemainingC > 0) {
      timeRemainingC--;
    } else if (!queue.isEmpty()) {
      totalWait += t - queue.dequeue();
      nServed++;
      timeRemainingC = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
    }
    totalLength += queue.size();
  }
}

void printReport(int nServed, int totalWait, int totalLength) {
  cout << "Simulation result given the following consants:" << endl;
  cout << fixed << setprecision(2);
  cout << " SIMULATION_TIME :     " << setw(4) << SIMULATION_TIME << endl;
  cout << "  ARRIVAL_PROBABILITY: " << setw(7) << ARRIVAL_PROBABILITY << endl;
  cout << "  MIN_SERVICE_TIME:    " << setw(4) << MIN_SERVICE_TIME << endl;
  cout << "  MAX_SERVICE_TIME:    " << setw(4) << MAX_SERVICE_TIME << endl;
  cout << endl;
  cout << "Customers served:      " << setw(4) << nServed << endl;
  cout << "Average waiting time:  " << setw(7) << double(totalWait) / nServed
       << endl;
  cout << "Average queue length:  " << setw(7)
       << double(totalLength) / SIMULATION_TIME << endl;
}
