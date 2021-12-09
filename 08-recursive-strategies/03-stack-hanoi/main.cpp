/* Programming Abstractions in C++
 *
 * Exercise 08-03
 *
 * Rewrite the Towers of Hanoi program so that it uses an explicit stack of
 * pending tasks instead of recursion. In this context, a task can be
 * represented most easily as a structure containing the number of disks to move
 * and the names of the spires used for the start, finish, and temporary
 * repositories. At the beginning of the process, you push onto your stack a
 * single task that describes the process of moving the entire tower. The
 * program then repeatedly pops the stack and executes the task found there
 * until no tasks are left. Except for the simple cases, the process of
 * executing a task results in the creation of more tasks that get pushed onto
 * the stack for later execution.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/stack.h"

struct Task {
  Task() {
    numDisks = 0;
    start = 'A';
    finish = 'B';
    temp = 'C';
  }
  Task(int n, char a, char b, char c) {
    numDisks = n;
    start = a;
    finish = b;
    temp = c;
  }
  int numDisks;
  char start;
  char finish;
  char temp;
};

void moveSingleDisk(Task t);
void moveTower(Task t, Stack<Task> &stackOfTasks);

int main() {
  std::cout << "Welcome to Tower of Hanoi." << std::endl;
  int n = getInteger("Enter number of disks: ");
  Stack<Task> stackOfTasks;
  Task moveAll(n, 'A', 'B', 'C');
  stackOfTasks.push(moveAll);
  while (!stackOfTasks.isEmpty()) {
    moveTower(stackOfTasks.pop(), stackOfTasks);
  }
  return 0;
}

void moveSingleDisk(Task t) { cout << t.start << " -> " << t.finish << endl; }

void moveTower(Task t, Stack<Task> &stackOfTasks) {
  if (t.numDisks == 1) {
    moveSingleDisk(t);
  } else {
    stackOfTasks.push(Task(t.numDisks - 1, t.temp, t.finish, t.start));
    stackOfTasks.push(Task(1, t.start, t.finish, t.temp));
    stackOfTasks.push(Task(t.numDisks - 1, t.start, t.temp, t.finish));
  }
}
