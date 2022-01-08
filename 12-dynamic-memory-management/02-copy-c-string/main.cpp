/* Programming Abstractions in C++
 *
 * Exercise 12-02
 *
 * The definition of strcpy on page 505 is marked with a skull-and-crossbones
 * icon to remind you how dangerous this function can be. The danger stems
 * from the fact that strcpy fails to check that there is sufficient space in
 * the character array that receives the copy, thereby increasing the chance of
 * a buffer-overflow error. It is possible, however, to eliminate much of the
 * danger by using dynamic allocation to create memory space for the copied
 * string.
 *
 * Write a function
 *
 *  char *copyCString(char *str);
 *
 * that allocates enough memory for the C-style string str and then copies the
 * characters—along with the terminating null character—into the newly
 * allocated memory.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

char *copyCString(char *str);

int main() {
  char a[10] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
  int pos = 0;
  std::cout << &a << " --> ";
  while (a[pos] != '\0')
    std::cout << a[pos++];
  std::cout << std::endl;
  char *b = copyCString(a);
  pos = 0;
  std::cout << &b << " --> ";
  while (b[pos] != '\0')
    std::cout << a[pos++];
  std::cout << std::endl;
  delete[] b;
  return 0;
}

char *copyCString(char *str) {
  int size = 0;
  while (str[size++] != '\0')
    ; // just incrementing size
  char *output = new char[size];
  for (int i = 0; i < size; i++)
    output[i] = str[i];
  return output;
}
