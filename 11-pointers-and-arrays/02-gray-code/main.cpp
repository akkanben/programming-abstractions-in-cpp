/* Programming Abstractions in C++
 *
 * Exercise 11-02
 *
 * Although the binary coding used in exercise 1 is ideal for most applications,
 * it has certain drawbacks. As you count in standard binary notation, there are
 * some points in the sequence at which several bits change at the same time.
 * For example, in the three-bit binary code, the value of every bit changes as
 * you move from 3 (011) to 4 (100).
 *
 * In some applications, this instability in the bit patterns used to represent
 * adjacent numbers can lead to problems. Imagine for the moment that you are
 * using some hardware measurement device that produces a three-bit value from
 * some real-world phenomenon that happens to be varying between 3 and 4.
 * Sometimes, the device will register 011 to indicate the value 3; at other
 * times, it will register 100 to indicate 4. For this device to work correctly,
 * the transitions for each of the individual bits must occur simultaneously. If
 * the first bit changes more quickly than the others, for example, there may be
 * an intermediate state in which the device reads 111, which would be a highly
 * inaccurate reading.
 *
 * It turns out that you can avoid this problem simply by changing the
 * numbering system. If instead of using binary representation in the
 * traditional way, you can assign three-bit values to each of the numbers 0
 * through 7 with the highly useful property that only one bit changes in the
 * representation between every pair of adjacent integers. Such an encoding is
 * called a Gray code (after its inventor, the mathematician Frank Gray) and
 * looks like this:
 *
 *  000 --> 0
 *  001 --> 1
 *  011 --> 2
 *  010 --> 3
 *  110 --> 4
 *  111 --> 5
 *  101 --> 6
 *  100 --> 7
 *
 * In the Gray code representation, the bit patterns for 3 and 4 differ only in
 * their leftmost bit. If the hardware measurement device used Gray codes, a
 * value oscillating between 3 and 4 would simply turn that bit on and off,
 * eliminating any problems with synchronization.
 *
 * The recursive insight that you need to create a Gray code of N bits is
 * summarized in the following informal procedure:
 *
 * 1.  Write down the Gray code for N – 1 bits.
 * 2.  Copy that same list in reverse order below the original one.
 * 3.  Add a 0 bit in front of the encodings in the original half of the list
 * and a 1 bit in front of those in the reversed copy.
 *
 * This procedure is illustrated in the following derivation of the Gray code
 * for three bits:
 *
 * 3-bit Gray code    2-bit Gray code     1-bit Gray code
 *        000 \
 *        000  | \
 *        000  |  \   00 \
 *        000 /    \  01  | \   / 0
 *                  >     |  > <
 *        000 \    /  11  |r/   \ 1
 *        000  |r /   10 / e
 *        000  |e/         v
 *        000 / v
 *
 *
 * Write a recursive function generateGrayCode(nBits) that generates
 * the Gray code patterns for the specified number of bits. For example, if you
 * call the function
 *
 *  generateGrayCode(3)
 *
 * the program should produce the following output:
 *
 * <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/vector.h"

void generateGrayCode(int nBits);
Vector<std::string> getGrayCodes(Vector<std::string> &vec, int nBits);

int main() {
  std::cout
      << "This program generates all the integers represented in Gray code"
         "that fit in a given bit size"
      << std::endl;
  int bitSize = getInteger("Enter a number of bits to use: ");
  generateGrayCode(bitSize);
  return 0;
}

Vector<std::string> getGrayCodes(Vector<std::string> &vec, int nBits) {
  Vector<std::string> output;
  if (nBits == 0) {
    return Vector<std::string>(1);
  } else {
    Vector<std::string> temp = getGrayCodes(vec, nBits - 1);
    for (int i = 0; i < temp.size(); i++)
      output.add('0' + temp[i]);
    for (int i = temp.size() - 1; i >= 0; i--)
      output.add('1' + temp[i]);
  }
  return output;
}

void generateGrayCode(int nBits) {
  Vector<std::string> output;
  int count = 0;
  for (std::string s : getGrayCodes(output, nBits)) {
    std::cout << s << " : " << count++ << std::endl;
  }
}
