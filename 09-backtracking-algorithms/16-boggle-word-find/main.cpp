/* Programming Abstractions in C++
 *
 * Exercise 09-16
 *
 * The game of Boggle is played with a 4!4 grid of cubes, each of which shows a
 * letter on its face. The goal is to form as many words of four or more letters
 * as possible, moving only between letter cubes that are adjacent—horizontally,
 * vertically, or diagonally—never using any cube more than once. Figure 9-9
 * shows a possible Boggle layout and the words in the EnglishWords.dat
 * lexicon that you can find from that starting position. As an example, you can
 * form the word programming using the following sequence of cubes:
 *
 *    X C E R
 *    I M G A
 *    N O M L
 *    G Z R P
 *
 * Write a function
 *
 * void findBoggleWords(const Grid<char> & board,
 *                      const Lexicon & english,
 *                      Vector<string> & wordsFound);
 *
 * that finds all the legal words on the board that appear in the english
 * lexicon and adds those words to the vector wordsFound.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/grid.h"
#include "../../StanfordCPPLib/include/lexicon.h"
#include "../../StanfordCPPLib/include/point.h"
#include "../../StanfordCPPLib/include/vector.h"

enum Direction { N, NE, E, SE, S, SW, W, NW };

void findBoggleWords(const Grid<char> &board, const Lexicon &english,
                     Vector<std::string> &wordsFound);
Vector<std::string> wordSearch(Lexicon english, Grid<char> &board, Point p,
                               std::string word);
void fillGrid(Grid<char> &board, Vector<char> &values);
void initBoard(Grid<char> &board);
char letterAtDirection(const Grid<char> &board, Point p,
                       Direction dir); // assumes point at direction is safe
bool isDirectionInBounds(const Grid<char> &board, Point p, Direction dir);
Point getPointFromDirection(Point p, Direction dir);

int main() {
  Lexicon english;
  english.addWordsFromFile("../../extras/dictionary.txt");
  Grid<char> boggleBoard;
  initBoard(boggleBoard);
  for (int i = 0; i < boggleBoard.numRows(); i++) {
    for (int j = 0; j < boggleBoard.numCols(); j++) {
      std::cout << boggleBoard[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl
            << "Computing words, may take up to 5 minutes or more..."
            << std::endl;
  Vector<std::string> wordsFound;
  findBoggleWords(boggleBoard, english, wordsFound);
  for (std::string word : wordsFound) {
    if (word.length() >= 4)
      std::cout << word << std::endl;
  }
  return 0;
}

void findBoggleWords(const Grid<char> &board, const Lexicon &english,
                     Vector<std::string> &wordsFound) {
  for (int i = 0; i < board.numRows(); i++) {
    for (int j = 0; j < board.numCols(); j++) {
      Grid<char> tempBoard = board;
      std::string firstLetter = "";
      firstLetter += tempBoard.get(i, j);
      wordsFound += wordSearch(english, tempBoard, Point(i, j), firstLetter);
    }
  }
}

Vector<std::string> wordSearch(Lexicon english, Grid<char> &board, Point p,
                               std::string word) {
  Vector<std::string> output;
  if (english.contains(word)) {
    output.add(word);
  }
  if (english.containsPrefix(word)) {
    char letter = board.get(p.getX(), p.getY());
    board.set(p.getX(), p.getY(), '?');
    for (int i = (int)N; i <= (int)NW; i++) {
      if (isDirectionInBounds(board, p, (Direction)i)) {
        output +=
            wordSearch(english, board, getPointFromDirection(p, (Direction)i),
                       word + letterAtDirection(board, p, (Direction)i));
      }
    }
    board.set(p.getX(), p.getY(), letter);
  }
  return output;
}

void initBoard(Grid<char> &board) {
  board.resize(4, 4);
  Vector<char> values;
  values += 'X', 'C', 'E', 'R';
  values += 'I', 'M', 'G', 'A';
  values += 'N', 'O', 'M', 'L';
  values += 'G', 'Z', 'R', 'P';
  fillGrid(board, values);
}

void fillGrid(Grid<char> &board, Vector<char> &values) {
  int count = 0;
  for (int i = 0; i < board.numRows(); i++) {
    for (int j = 0; j < board.numCols(); j++) {
      board.set(i, j, values.get(count));
      count++;
    }
  }
}

bool isDirectionInBounds(const Grid<char> &board, Point p, Direction dir) {
  switch (dir) {
  case N:
    return board.inBounds(p.getX() - 1, p.getY());
  case NE:
    return board.inBounds(p.getX() - 1, p.getY() + 1);
  case E:
    return board.inBounds(p.getX(), p.getY() + 1);
  case SE:
    return board.inBounds(p.getX() + 1, p.getY() + 1);
  case S:
    return board.inBounds(p.getX() + 1, p.getY());
  case SW:
    return board.inBounds(p.getX() + 1, p.getY() - 1);
  case W:
    return board.inBounds(p.getX(), p.getY() - 1);
  case NW:
    return board.inBounds(p.getX() - 1, p.getY() - 1);
  default:
    return false;
  }
}

Point getPointFromDirection(Point p, Direction dir) {
  switch (dir) {
  case N:
    return Point(p.getX() - 1, p.getY());
  case NE:
    return Point(p.getX() - 1, p.getY() + 1);
  case E:
    return Point(p.getX(), p.getY() + 1);
  case SE:
    return Point(p.getX() + 1, p.getY() + 1);
  case S:
    return Point(p.getX() + 1, p.getY());
  case SW:
    return Point(p.getX() + 1, p.getY() - 1);
  case W:
    return Point(p.getX(), p.getY() - 1);
  case NW:
    return Point(p.getX() - 1, p.getY() - 1);
  default:
    return Point(-1, -1);
  }
}

char letterAtDirection(const Grid<char> &board, Point p, Direction dir) {
  switch (dir) {
  case N:
    return board.get(p.getX() - 1, p.getY());
  case NE:
    return board.get(p.getX() - 1, p.getY() + 1);
  case E:
    return board.get(p.getX(), p.getY() + 1);
  case SE:
    return board.get(p.getX() + 1, p.getY() + 1);
  case S:
    return board.get(p.getX() + 1, p.getY());
  case SW:
    return board.get(p.getX() + 1, p.getY() - 1);
  case W:
    return board.get(p.getX(), p.getY() - 1);
  case NW:
    return board.get(p.getX() - 1, p.getY() - 1);
  default:
    return '?';
  }
}
