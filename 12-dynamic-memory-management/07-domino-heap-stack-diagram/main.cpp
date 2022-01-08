/* Programming Abstractions in C++
 *
 * Exercise 12-07
 *
 * Suppose that you have a file containing the code in Figure 12-15. Draw a
 * heap-stack diagram showing the contents of memory just before the function
 * initPair returns. For extra practice, draw two versions of this diagram: one
 * that uses explicit addresses and one that uses arrows to indicate the
 * pointers.
 *
 * Solution 2021 Ben Mills
 * see domino-heap-stack.png for diagram
 */

struct Domino {
  int leftDots;
  int rightDots;
};

void initPair(Domino list[], Domino &dom);

int main() {
  Domino onetwo;
  onetwo.leftDots = 1;
  onetwo.rightDots = 2;
  Domino *array = new Domino[2];
  initPair(array, onetwo);
  return 0;
}

void initPair(Domino list[], Domino &dom) {
  list[0] = dom;
  list[1].leftDots = dom.rightDots;
  list[1].rightDots = dom.leftDots;
  dom = list[1]; // <--- Diagram memory at this point in the execution
}
