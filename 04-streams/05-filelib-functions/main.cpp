/* Programming Abstractions in C++
 *
 * Exercise
 *
 * The filelib.h interface exports several functions that make it easy to work
 * with filenames. Two functions that are particularly useful are getRoot and
 * getExtension, which divide a function into its root, which is the identifying
 * part of the filename, and the extension, which indicates its type. For
 * example, given the filename Middlemarch.txt used in the preceding exercise,
 * the root is Middlemarch and the extension is .txt (note that filelib.h
 * defines the extension to includes the dot). Write the code necessary to
 * implement these functions. To find out how to handle special cases, such as
 * filenames that don’t include a dot, consult the filelib.h interface in
 * Appendix A.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

std::string promptUser(std::string prompt = "");
std::string getRoot(std::string fileName);
std::string getExtension(std::string fileName);

int main() {
  while (true) {
    std::string fileName = promptUser("Input file: ");
    std::cout << "The root of the file name is: " << getRoot(fileName)
              << std::endl;
    std::cout << "The extension of the file is: " << getExtension(fileName)
              << std::endl;
  }
  return 0;
}

std::string promptUser(std::string prompt) {
  std::cout << prompt;
  std::string fileName;
  std::cin >> fileName;
  return fileName;
}

std::string getRoot(std::string fileName) {
  for (int i = fileName.length() - 1; i > 0; i--) {
    if (fileName.at(i) == '.')
      return fileName.substr(0, i);
  }
  return fileName;
}

std::string getExtension(std::string fileName) {
  for (int i = fileName.length() - 1; i > 0; i--) {
    if (fileName.at(i) == '.')
      return fileName.substr(i);
  }
  return "";
}
