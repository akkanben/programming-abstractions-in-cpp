/* Programming Abstractions in C++
 *
 * Exercise 12-08
 *
 * As in the preceding exercise, draw a heap-stack diagram showing the state of
 * memory at the indicated point in Figure 12-16, which asks you to diagram
 * memory during the second call to the constructor.
 *
 * Solution 2021 Ben Mills
 */

#include <csignal>
#include <iostream>

class Student {
public:
  Student() {
    id = 0;
    gpa = 4.0;
  }

  Student(int id, double gpa) {
    this->id = id;
    this->gpa = gpa;
  } //<-- Diagram at this point on the second call to the constructor

private:
  int id;
  double gpa;
};

int main() {
  Student *advisees = new Student[2];
  advisees[0] = Student(2718281, 3.61);
  advisees[1] = Student(3141592, 4.2);
  return 0;
}
