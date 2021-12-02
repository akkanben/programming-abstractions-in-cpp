/* Programming Abstractions in C++
 *
 * Exercise
 *
 * And the first one now
 * Will later be last
 * For the times they are a-changin’.
 *
 *              —Bob Dylan, “The Times They Are a-Changin’,” 1963
 *
 * Following the inspiration from Bob Dylan’s song (which is itself inspired by
 * Matthew 19:30), write a function
 *
 * void reverseQueue(Queue<string> & queue);
 *
 * that reverses the elements in the queue. Remember that you have no access to
 * the internal representation of the queue and must therefore come up with an
 * algorithm—presumably involving other structures—that accomplishes the
 * task.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/queue.h"
#include "../../StanfordCPPLib/include/stack.h"
#include <iostream>

void reverseQueue(Queue<string> &queue);
void printQueue(Queue<string> queue);

int main() {
  std::ifstream inFile;
  Queue<string> queue;
  std::string fileName = promptUserForFile(inFile, "Enter a file to reverse: ");
  std::string line;
  while (getline(inFile, line)) {
    queue.enqueue(line);
  }
  printQueue(queue);
  std::cout << std::endl << "~becomes~\n" << std::endl;
  reverseQueue(queue);
  printQueue(queue);
  return 0;
}

/* functions */

void reverseQueue(Queue<string> &queue) {
  int size = queue.size();
  Stack<std::string> stack;
  for (int i = 0; i < size; i++) {
    stack.push(queue.dequeue());
  }
  queue.clear();
  for (int i = 0; i < size; i++) {
    queue.enqueue(stack.pop());
  }
}

void printQueue(Queue<string> queue) {
  int size = queue.size();
  for (int i = 0; i < size; i++) {
    std::cout << queue.dequeue() << std::endl;
  }
}
