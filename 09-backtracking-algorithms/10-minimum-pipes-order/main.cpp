/* Programming Abstractions in C++
 *
 * Exercise 09-10
 *
 * Suppose that you have been assigned the job of buying the plumbing pipes for
 * a construction project. Your foreman gives you a list of the varying lengths
 * of pipe needed, but the distributor sells stock pipe only in one fixed size.
 * You can, however, cut each stock pipe in any way needed. Your job is to
 * figure out the minimum number of stock pipes required to satisfy the list of
 * requests, thereby saving money and minimizing waste.
 *
 * Your job is to write a recursive function
 *
 *  int cutStock(Vector<int> & requests, int stockLength);
 *
 * that takes two arguments—a vector of the lengths needed and the length of
 * stock pipe that the distributor sells—and returns the minimum number of stock
 * pipes needed to service all requests in the vector. For example, if the
 * vector contains [ 4, 3, 4, 1, 7, 8 ] and the stock pipe length is 10, you can
 * purchase three stock pipes and divide them as follows:
 *
 * Pipe 1: 4, 4, 1
 * Pipe 2: 3, 7
 * Pipe 3: 8
 *
 * Doing so leaves you with two small remnants left over. There are other
 * possible arrangements that also fit into three stock pipes, but it cannot be
 * done with fewer.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/stack.h"
#include "../../StanfordCPPLib/include/vector.h"

int cutStock(Vector<int> requests, int stockLength);
int getNumStockNeeded(Vector<int> requests, int stockLength,
                      Vector<int> remainingRequests, int cutSum, int numStock);
Vector<int> sortRequests(Vector<int> requests);

int main() {
  Vector<int> requests;
  requests += 4, 3, 4, 1, 7, 8;
  int stockLength = 10;
  Vector<int> temp = sortRequests(requests);
  cout << "Cutting Stock of: " << requests << endl;
  cout << "Stock length: " << stockLength << endl;
  cout << "Total Pipes Needed: " << cutStock(temp, stockLength) << endl;
  requests.clear();
  temp.clear();
  requests += 11, 2, 6, 1, 7, 7, 6, 3, 12;
  temp = sortRequests(requests);
  stockLength = 12;
  cout << "Cutting Stock of: " << requests << endl;
  cout << "Stock length: " << stockLength << endl;
  cout << "Total Pipes Needed: " << cutStock(temp, stockLength) << endl;
  return 0;
}

int cutStock(Vector<int> requests, int stockLength) {
  return getNumStockNeeded(requests, stockLength, requests, 0, 0);
}

int getNumStockNeeded(Vector<int> requests, int stockLength,
                      Vector<int> remainingRequests, int cutSum, int numStock) {
  if (remainingRequests.isEmpty()) {
    return numStock;
  }

  for (int i = 0; i < remainingRequests.size(); i++) {
    if (remainingRequests[i] > stockLength)
      error("Stock too too short for request.");
    cutSum += remainingRequests[i];
    if (cutSum == stockLength) {
      cutSum = 0; // reset
      remainingRequests.remove(i);
      return getNumStockNeeded(requests, stockLength, remainingRequests, cutSum,
                               numStock + 1);
    } else if (cutSum > stockLength) {
      cutSum -= remainingRequests[i];
    } else {
      remainingRequests.remove(i);
      i--;
    }
  }
  return getNumStockNeeded(requests, stockLength, remainingRequests, 0,
                           numStock + 1);
}

Vector<int> sortRequests(Vector<int> requests) {
  Vector<int> temp;
  int count = 0;
  while (!requests.isEmpty()) {
    if (temp.isEmpty()) {
      temp.add(requests[0]);
      requests.remove(0);
    }
    for (int i = 0; i < temp.size(); i++) {
      if (requests[count] <= temp[i]) {
        temp.insert(i, requests[count]);
        requests.remove(count);
        break;
      } else if (i == temp.size() - 1) {
        temp.add(requests[count]);
        requests.remove(count);
        break;
      }
    }
  }
  Stack<int> stack;
  for (int i = 0; i < temp.size(); i++) {
    stack.push(temp[i]);
  }
  while (!stack.isEmpty()) {
    requests.add(stack.pop());
  }

  return requests;
}
