/* Programming Abstractions in C++
 *
 * Exercise 11-06
 *
 * Using the definitions of MAX_JUDGES and scores on page 498 as a starting
 * point, write a program that reads in gymnastics scores between 0 and 10 from
 * a set of judges and then computes the average of the scores after eliminating
 * both the highest and lowest scores from consideration. Your program should
 * accept input values until the maximum number of judges is reached or the user
 * enters a blank line. A sample run of this program might look like this:
 *
 *  <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"

void sort(double arr[], int count);
double getAverageScore(double arr[], int count);
double getAverageFromTo(double arr[], int from, int to);
const int MAX_JUDGES = 10;

int main() {
  std::cout << "Enter score for each judge in the range 0 to 10." << std::endl;
  std::cout << "Enter a blank line to signal the end of the list." << std::endl;
  double scores[MAX_JUDGES];
  int nJudges = 0;
  while (nJudges <= MAX_JUDGES) {
    std::string input;
    input = getLine("Judge #" + integerToString(nJudges + 1) + ": ");
    if (input != "") {
      double value = stringToReal(input);
      if (value < 0 || value > 10)
        error("Value out of bounds.");
      scores[nJudges] = stringToReal(input);
      nJudges++;
    } else
      break;
  }
  if (nJudges < 1)
    error("No judges to average.");
  double average = getAverageScore(scores, nJudges);
  if (nJudges < 4) {
    std::cout << "Judge count too low to remove highest and lowest scores."
              << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "The average is "
              << average << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(1)
              << "The average after eliminating " << scores[0] << " and "
              << scores[nJudges - 1] << " is " << average << std::endl;
  }
  return 0;
}

void sort(double arr[], int count) {
  if (count <= 1)
    return;
  for (int i = 1; i < count; i++) {
    int backPosition = i;
    while (backPosition > 0 && arr[backPosition] < arr[backPosition - 1]) {
      double temp = arr[backPosition - 1];
      arr[backPosition - 1] = arr[backPosition];
      arr[backPosition] = temp;
      backPosition--;
    }
  }
}

double getAverageScore(double arr[], int count) {
  sort(arr, count);
  if (count < 3) {
    return getAverageFromTo(arr, 0, count - 1);
  } else {
    return getAverageFromTo(arr, 1, count - 2);
  }
}

double getAverageFromTo(double arr[], int from, int to) {
  double total = 0;
  int count = 0;
  for (int i = from; i <= to; i++) {
    total += arr[i];
    count++;
  }
  return total / count;
}
