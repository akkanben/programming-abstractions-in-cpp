/* Programming Abstractions in C++
 *
 * Exercise 03-20
 *
 * The genetic code for all living organisms is carried in its DNA—a molecule
 * with the remarkable capacity to replicate its own structure. The DNA
 * molecule itself consists of a long strand of chemical bases wound together
 * with a similar strand in a double helix. DNA’s ability to replicate comes
 * from the fact that its four constituent bases—adenosine, cytosine, guanine,
 * and thymine—combine with each other only in the following ways:
 *
 *  • Cytosine on one strand links only with guanine on the other, and vice
 * versa. • Adenosine links only with thymine, and vice versa.
 *
 * Biologists abbreviate the names of the bases by writing only the initial
 * letter: A, C, G, or T.
 *
 * Inside the cell, a DNA strand acts as a template to which other DNA
 * strands can attach themselves. As an example, suppose that you have the
 * following DNA strand, in which the position of each base has been numbered
 * as it would be in a C++ string:
 *
 *   T  A  A  C  G  G  T  A  C  G  T C
 *   |  |  |  |  |  |  |  |  |  |  | |
 *  ----------------------------------
 *   0  1  2  3  4  5  6  7  8  9 10 11
 *
 * Your mission in this exercise is to determine where a shorter DNA strand can
 * attach itself to the longer one. If, for example, you were trying to find a
 * match for the strand
 *
 *   -----------
 *    | | | | |
 *    T T G C C
 *
 * the rules for DNA dictate that this strand can bind to the longer one only at
 * position 1:
 *
 *      -------------
 *      |  |  |  |  |
 *      T  T  G  C  C
 *   T  A  A  C  G  G  T  A  C  G  T C
 *   |  |  |  |  |  |  |  |  |  |  | |
 *  ----------------------------------
 *   0  1  2  3  4  5  6  7  8  9 10 11
 *
 *
 * By contrast, the strand
 *
 *  -------
 *   | | |
 *   T G C
 *
 * matches at either position 2 or position 7.
 *
 *
 * Write a function
 *
 *  int findDNAMatch(string s1, string s2, int start = 0);
 *
 * that returns the first position at which the DNA strand s1 can attach to the
 * strand s2. As in the find method for the string class, the optional start
 * parameter indicates the index position at which the search should start. If
 * there is no match, findDNAMatch should return –1.
 *
 * Solution 2021 Ben Mills
 */

#include <cctype>
#include <iostream>
#include <string>

std::string DNAStrand = "TAACGGTACGTC";
std::string shorterStrandA = "TTGCC";
std::string shorterStrandB = "TGC";

std::string createMatchingStrand(std::string strand);
int findDNAMatch(std::string s1, std::string s2, int start = 0);

int main() {
  std::cout << "DNA Strand: [" << DNAStrand << "]." << std::endl;
  std::cout << "Matching [" << shorterStrandA << "], looking for ["
            << createMatchingStrand(shorterStrandA) << "] starting at pos 0: "
            << findDNAMatch(DNAStrand, shorterStrandA) << std::endl;
  std::cout << "Matching [" << shorterStrandB << "], looking for ["
            << createMatchingStrand(shorterStrandB) << "] starting at pos 0: "
            << findDNAMatch(DNAStrand, shorterStrandB) << std::endl;
  std::cout << "Matching [" << shorterStrandB << "], looking for ["
            << createMatchingStrand(shorterStrandB) << "] starting at pos 4: "
            << findDNAMatch(DNAStrand, shorterStrandB, 4) << std::endl;
  std::cout << "Matching [GTTC], looking for [" << createMatchingStrand("GTTC")
            << "] starting at 0: " << findDNAMatch(DNAStrand, "GTTC")
            << std::endl;
  return 0;
}

int findDNAMatch(std::string s1, std::string s2, int start) {
  std::string match = createMatchingStrand(s2);
  return s1.find(match, start);
}

std::string createMatchingStrand(std::string strand) {
  std::string output = "";
  for (int i = 0; i < strand.length(); i++) {
    switch (strand[i]) {
    case 'A':
      output += 'T';
      break;
    case 'T':
      output += 'A';
      break;
    case 'C':
      output += 'G';
      break;
    case 'G':
      output += 'C';
      break;
    default:
      output += '?';
    }
  }
  return output;
}
