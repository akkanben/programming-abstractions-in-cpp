/* Programming Abstractions in C++
 *
 * Exercise 04-02
 *
 * In exercise 4 in Chapter 2, you wrote a function windChill that calculated
 * the wind chill for a given temperature and wind velocity. Write a program
 * that uses this function to display these values in tabular form, as
 * illustrated by the table from the National Weather service shown in Figure
 * 2-17 on page 116.
 *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

int getWindChill(int temp, int wind);

int main() {
  int maxTemp = 40;
  int minTemp = -45;
  int maxWind = 60;
  for (int i = 0; i < maxWind; i += 5) {
    if (i == 0) {
      std::cout << std::right << std::setw(5) << "calm ";
    } else if (i == 5) {
      std::cout << "     ------------------------------------------------------"
                   "------------------------------------"
                << std::endl;
      std::cout << " ";
      std::cout << std::right << std::setw(2) << i << " |";
    } else {
      std::cout << " ";
      std::cout << std::right << std::setw(2) << i << " |";
    }
    for (int j = maxTemp; j >= minTemp; j -= 5) {
      if (i == 0) {
        std::cout << std::right << std::setw(5) << j;
      } else {
        std::cout << std::right << std::setw(5) << getWindChill(j, i);
      }
    }
    std::cout << std::endl;
  }
  return 0;
}

int getWindChill(int temp, int wind) {
  int windChill;
  if (wind == 0) {
    windChill = temp;
  } else if (temp > 40) {
    windChill = 0;
    std::cout << "Out of range.";
  } else {
    windChill = 35.74 + 0.6215 * temp - 35.75 * pow(wind, 0.16) +
                0.4275 * temp * pow(wind, 0.16);
  }
  return windChill;
}
