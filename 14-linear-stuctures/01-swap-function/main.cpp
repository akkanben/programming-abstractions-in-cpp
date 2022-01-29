/* Programming Abstractions in C++
 *
 * Exercise 14-01
 *
 * The standard C++ header file <algorithm> (which you will learn more about
 * in Chapter 20) includes a template function swap(x, y) that interchanges the
 * values of x and y. Write and test your own implementation of the swap
 * function.
 *
 * Solution 2021 Ben Mills
 */

#include <cassert>
#include <iostream>

template <typename ValueType> void swap(ValueType *x, ValueType *y);

int main() {
  int x = 5;
  int y = 12;
  float f1 = 3.14;
  float f2 = 8.125;
  double d1 = 1.2345;
  double d2 = 6.780123;
  char a = 'A';
  char b = 'B';
  std::string str1 = "hello";
  std::string str2 = "world!";
  bool t = true;
  bool f = false;
  swap(&x, &y);
  swap(&f1, &f2);
  swap(&d1, &d2);
  swap(&a, &b);
  swap(&str1, &str2);
  swap(&t, &f);
  assert(x == 12);
  assert(y == 5);
  assert(f1 == (float)8.125);
  assert(f2 == (float)3.14);
  assert(a == 'B');
  assert(b == 'A');
  assert(str1 == "world!");
  assert(str2 == "hello");
  assert(t == false);
  assert(f == true);
  std::cout << "Swap template function unit test succeeded." << std::endl;
  return 0;
}

template <typename ValueType> void swap(ValueType *x, ValueType *y) {
  ValueType temp = *x;
  *x = *y;
  *y = temp;
}
