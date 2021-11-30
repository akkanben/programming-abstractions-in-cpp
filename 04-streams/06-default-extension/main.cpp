/* Programming Abstractions in C++
 *
 * Exercise 04-06
 *
 * Another useful function in filelib.h is
 *
 *  string defaultExtension(string filename, string ext);
 *
 * which adds ext to the end of filename if it doesn’t already have an
 * extension. For example,
 *
 *  defaultExtension("Shakespeare", ".txt")
 *
 * would return "Shakespeare.txt". If filename already has an extension,
 * that name is returned unchanged, so that
 *
 *  defaultExtension("library.h", ".cpp")
 *
 * would ignore the specified extension and return "library.h" unchanged. If,
 * however, ext includes a star before the dot, defaultExtension removes
 * any existing extension from filename and adds the new one (minus the star).
 * Thus,
 *
 *  defaultExtension("library.h", "*.cpp")
 *
 * would return "library.cpp". Write the code for defaultExtension so
 * that it behaves as described in this exercise.
 *
 * Solution 2021 Ben Mills
 */
#include <iostream>
#include <string>

std::string defaultExtension(std::string fileName, std::string ext);
std::string getRoot(std::string fileName);

int main() {
  std::string a = defaultExtension("Shakespeare", ".txt");
  std::string b = defaultExtension("library.h", ".cpp");
  std::string c = defaultExtension("library.h", "*.cpp");

  std::cout << "defaultExtension(\"Shakespeare\", \".txt\"\nreturns: " << a
            << std::endl;
  std::cout << "defaultExtension(\"library.h\", \".cpp\"\nreturns: " << b
            << std::endl;
  std::cout << "defaultExtension(\"library.h\", \"*.cpp\"\nreturns: " << c
            << std::endl;
  return 0;
}

std::string getRoot(std::string fileName) {
  for (int i = fileName.length() - 1; i > 0; i--) {
    if (fileName.at(i) == '.')
      return fileName.substr(0, i);
  }
  return fileName;
}

std::string defaultExtension(std::string fileName, std::string ext) {
  if (fileName == getRoot(fileName))
    return fileName + ext;
  if (ext.at(0) == '*')
    return getRoot(fileName) + ext.substr(1);
  return fileName;
}
