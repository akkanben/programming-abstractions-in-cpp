/* Programming Abstractions in C++
 *
 * Exercise 04-09
 *
 * Books were bks and Robin Hood was Rbinhd. Little Goody Two
 * Shoes lost her Os and so did Goldilocks, and the former became a
 * whisper, and the latter sounded like a key jiggled in a lck. It was
 * impossible to read “cockadoodledoo” aloud, and parents gave up
 * reading to their children, and some gave up reading altogether. . . .
 *
 *  —James Thurber, The Wonderful O, 1957
 *
 * In James Thurber’s children’s story The Wonderful O, the island of Ooroo is
 * invaded by pirates who set out to banish the letter O from the alphabet. Such
 * censorship would be much easier with modern technology. Write a program
 * that asks the user for an input file, an output file, and a string of letters
 * to be eliminated. The program should then copy the input file to the output
 * file, deleting any of the letters that appear in the string of censored
 * letters, no matter whether they appear in uppercase or lowercase form. As an
 * example, suppose that you have a file containing the first few lines of
 * Thurber’s novel, as follows:
 *
 *  <image of TheWonderfulO.txt>
 *
 * If you run your program with the input
 *
 *  <image of running program>
 *
 * it should write the following file:
 *
 *  <image of TheWnderful.txt>
 *
 * If you try to get greedy and banish all the vowels by entering aeiou in
 * response to the prompt, the contents of the output file would be
 *
 *  <image of ThWndrfl.txt>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include <fstream>
#include <iostream>
#include <string>

void banishcharacters(std::ifstream &infile, std::ofstream &outfile,
                      std::string tobanish);

int main() {
  std::ifstream infile;
  std::ofstream outfile;
  promptUserForFile(infile, "Input file: ");
  promptUserForFile(outfile, "Output file: ");
  std::string tobanish = getLine("Enter letters to remove: ");
  std::cout << std::endl;
  banishcharacters(infile, outfile, tobanish);
  infile.close();
  outfile.close();
  return 0;
}

void banishcharacters(std::ifstream &infile, std::ofstream &outfile,
                      std::string tobanish) {
  char ch;
  while (infile.get(ch)) {
    bool toput = true;
    for (int i = 0; i < tobanish.length(); i++) {
      if (tobanish.at(i) == ch) {
        toput = false;
      }
    }
    if (toput) {
      std::cout.put(ch);
      outfile.put(ch);
    }
  }
}
