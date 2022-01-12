/* Programming Abstractions in C++
 *
 * Exercise 12-03
 *
 * The names of the towers in the BeaconsOfGondor program from Figure 12-1
 * are listed explicitly in the createBeaconsOfGondor function. One way to
 * provide mode flexibility would be to read the names of the beacons from a
 * data file instead. Modify the BeaconsOfGondor program so that the first
 * statement in the main program calls a function
 *
 *  Tower *readBeaconsFromFile(string filename);
 *
 * that reads in the list of towers from the specified file. For example, if the
 * file BeaconsOfGondor.txt contains
 *
 *  Minas Tirith
 *  Amon Din
 *  Eilenach
 *  Nardol
 *  Erelas
 *  Min-Rimmon
 *  Calenhad
 *  Halifirien
 *  Rohan
 *
 * the program should run exactly as it does in the chapter.
 *
 * Solution 2021 Ben Mills
 */

#include <fstream>
#include <iostream>
#include <string>

struct Tower {
  std::string name;
  Tower *link;
};

Tower *readBeaconsFromFile(std::string filename);
Tower *createTower(std::string name, Tower *link);
void signal(Tower *start);

int main() {
  Tower *tower = readBeaconsFromFile("BeaconsOfGondor.txt");
  signal(tower);
  return 0;
}

Tower *readBeaconsFromFile(std::string filename) {
  std::ifstream infile;
  infile.open(filename.c_str());
  std::string line;
  getline(infile, line);
  Tower *tp = createTower(line, NULL);
  while (getline(infile, line)) {
    tp = createTower(line, tp);
  }
  infile.close();
  return tp;
}

Tower *createTower(std::string name, Tower *link) {
  Tower *tp = new Tower;
  tp->name = name;
  tp->link = link;
  return tp;
}

// Adding the cout after the recursive call lets us display the linked list in
// reverse so it matches figure 12-3 and the file.
void signal(Tower *start) {
  if (start != NULL) {
    signal(start->link);
    std::cout << "Lighting " << start->name << std::endl;
  }
}
