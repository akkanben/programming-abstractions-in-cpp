/* Programming Abstractions in C++
 *
 * Exercise 05-16
 *
 * The checkout-line simulation in Figure 5-5 can be extended to investigate
 * important practical questions about how waiting lines behave. As a first
 * step, rewrite the simulation so that there are several independent queues, as
 * is usually the case in supermarkets. A customer arriving at the checkout area
 * finds the shortest checkout line and enters that queue. Your revised
 * simulation should calculate the same results as the simulation in the
 * chapter.
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
  Queue<int> queueA;
  Queue<int> queueB;
  Queue<int> queueC;
  int timeRemainingA = 0;
  int timeRemainingB = 0;
  int timeRemainingC = 0;
  nServed = 0;
  totalWait = 0;
  totalLength = 0;
  for (int t = 0; t < SIMULATION_TIME; t++) {
    if (randomChance(ARRIVAL_PROBABILITY)) {
      if (queueA.size() <= queueB.size() && queueA.size() <= queueC.size()) {
        queueA.enqueue(t);
      } else if (queueB.size() < queueA.size() &&
                 queueB.size() < queueC.size()) {
        queueB.enqueue(t);
      } else
        queueC.enqueue(t);
    }
    if (timeRemainingA > 0) {
      timeRemainingA--;
    } else if (!queueA.isEmpty()) {
      totalWait += t - queueA.dequeue();
      nServed++;
      timeRemainingA = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
    }
    totalLength += queueA.size();
    if (timeRemainingB > 0) {
      timeRemainingB--;
    } else if (!queueB.isEmpty()) {
      totalWait += t - queueB.dequeue();
      nServed++;
      timeRemainingB = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
    }
    totalLength += queueB.size();
    if (timeRemainingC > 0) {
      timeRemainingC--;
    } else if (!queueC.isEmpty()) {
      totalWait += t - queueC.dequeue();
      nServed++;
      timeRemainingC = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
    }
    totalLength += queueC.size();
  }
}

void printReport(int nServed, int totalWait, int totalLength) {
  std::cout << "Simulation result given the following consants:" << endl;
  std::cout << fixed << setprecision(2);
  std::cout << " SIMULATION_TIME :     " << setw(4) << SIMULATION_TIME << endl;
  std::cout << "  ARRIVAL_PROBABILITY: " << setw(7) << ARRIVAL_PROBABILITY
            << endl;
  std::cout << "  MIN_SERVICE_TIME:    " << setw(4) << MIN_SERVICE_TIME << endl;
  std::cout << "  MAX_SERVICE_TIME:    " << setw(4) << MAX_SERVICE_TIME << endl;
  std::cout << endl;
  std::cout << "Customers served:      " << setw(4) << nServed << endl;
  std::cout << "Average waiting time:  " << setw(7)
            << double(totalWait) / nServed << endl;
  std::cout << "Average queue length:  " << setw(7)
            << double(totalLength) / SIMULATION_TIME << endl;
}
