/* Programming Abstractions in C++
 *
 * Exercise
 *
 * In the third century B.C.E., the Greek astronomer Eratosthenes developed an
 * algorithm for finding all the prime numbers up to some upper limit N. To
 * apply the algorithm, you start by writing down a list of the integers between
 * 2 and N. For example, if N were 20, you would begin by writing the following
 * list:
 *
 *  2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 *
 * You then circle the first number in the list, indicating that you have found
 * a prime. Whenever you mark a number as a prime, you go through the rest of
 * the list and cross off every multiple of that number, since none of those
 * multiples can itself be prime. Thus, after executing the first cycle of the
 * algorithm, you will have circled the number 2 and crossed off every multiple
 * of 2, as follows:
 *
 *  (2) 3 x 5 x 7 x 9 x 11 x 13 x 15 x 17 x 19 x
 *
 * To complete the algorithm, you simply repeat the process by circling the
 * first number in the list that is neither crossed off nor circled, and then
 * crossing off its multiples. In this example, you would circle 3 as a prime
 * and cross off all multiples of 3 in the rest of the list, which results in
 * the following state:
 *
 *  (2) (3) x 5 x 7 x x x 11 x 13 x x x 17 x 19 x
 *
 * Eventually, every number in the list will either be circled or crossed out,
 * as shown in this diagram:
 *
 *  (2) (3) x (5) x (7) x x x (11) x (13) x x x (17) x (19) x
 *
 * The circled numbers are the primes; the crossed-out numbers are composites.
 * This algorithm is called the sieve of Eratosthenes.
 *
 * Write a program that uses the sieve of Eratosthenes to generate a list of the
 * primes between 2 and 1000.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>
#include <string>

int main() {
  int n = getInteger("Enter the upper limit to find primes: ");
  Vector<int> sieve;
  Vector<int> primes;
  for (int i = 0; i < n - 1; i++) {
    sieve.add(2 + i);
  }
  int currentPrimePos = 0;
  while (currentPrimePos != sieve.size()) {
    for (int i = currentPrimePos + 1; i < sieve.size(); i++) {
      if (sieve.get(i) % sieve.get(currentPrimePos) == 0) {
        sieve.remove(i);
      }
    }
    currentPrimePos++;
  }
  for (int i = 0; i < sieve.size(); i++) {
    std::cout << sieve.get(i) << std::endl;
  }

  return 0;
}
