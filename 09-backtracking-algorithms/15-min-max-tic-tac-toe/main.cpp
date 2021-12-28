/* Programming Abstractions in C++
 *
 * Exercise 09-15
 *
 * The game of tic-tac-toe is played by two players who take turns placing
 * Xs and Os in a 3!3 grid that looks like this:
 *
 *     |   |
 *  ---+---+---
 *     |   |
 *  ---+---+---
 *     |   |
 *
 * The object of the game is to line up three of your own symbols in a row,
 * horizontally, vertically, or diagonally. In the following game, for example,
 * X has won the game by completing three in a row across the top:
 *
 *   X | X | X
 *  ---+---+---
 *     | O | O
 *  ---+---+---
 *   O |   |
 *
 * If the board fills up without anyone completing a row, the game is a draw,
 * which is called a cat’s game in tic-tac-toe.
 *
 * Write a program that uses the minimax algorithm to play a perfect game of
 * tic-tac-toe. Figure 9-8 shows a sample run against a particularly inept
 * player.
 *
 *  <image of trial run>
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/point.h"
#include "../../StanfordCPPLib/include/set.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"

enum Player { HUMAN, COMPUTER };

const int WINNING_POSITION = 100;
const int LOSING_POSITION = -WINNING_POSITION;
const int MAX_DEPTH = 6;
const Player STARTING_PLAYER = COMPUTER;
const char COMPUTER_TOKEN = 'X';
const char HUMAN_TOKEN = 'O';

struct Move {
  int squareID;
  Point square;
};

class TicTacToe {
public:
  void play() {
    initGame();
    while (!gameIsOver()) {
      // displayGame();
      if (getCurrentPLayer() == HUMAN) {
        displayGame();
        makeMove(getUserMove());
      } else {
        Move move = getComputerMove();
        displayMove(move);
        makeMove(move);
      }
      switchTurn();
    }
    announceResult();
  }

  void printInsructions() {
    std::cout << "Welcome to TicTacToe, the game of three in a row."
              << std::endl;
    std::cout << "I'll be X, and you'll be O." << std::endl;
    std::cout << "The squares are numbered like this:" << std::endl
              << std::endl;
    std::cout << " 1 | 2 | 3 " << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " 4 | 5 | 6 " << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " 7 | 8 | 9 " << std::endl << std::endl;
  }

private:
  void initGame() {
    whoseTurn = STARTING_PLAYER;
    row0 += ' ', ' ', ' ';
    row1 += ' ', ' ', ' ';
    row2 += ' ', ' ', ' ';
    gameBoard += row0, row1, row2;
  }

  bool gameIsOver() {
    if (isWinningToken(HUMAN_TOKEN) || isWinningToken(COMPUTER_TOKEN))
      return true;
    for (int i = 0; i < gameBoard.size(); i++) {
      for (int j = 0; j < gameBoard[0].size(); j++) {
        if (gameBoard[i][j] == ' ')
          return false;
      }
    }
    return true;
  }

  void displayGame() {
    std::cout << " " << gameBoard[0][0] << " | " << gameBoard[0][1] << " | "
              << gameBoard[0][2] << " " << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | "
              << gameBoard[1][2] << " " << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << gameBoard[2][0] << " | " << gameBoard[2][1] << " | "
              << gameBoard[2][2] << " " << std::endl;
  }

  Player getCurrentPLayer() { return whoseTurn; }

  Move getComputerMove() { return findBestMove(); }

  void displayMove(Move move) {
    std::cout << "I'll move to " << move.squareID << "." << std::endl;
    std::cout << "The game now looks like this:" << std::endl;
  }

  void makeMove(Move move) {
    char token;
    if (whoseTurn == HUMAN)
      token = HUMAN_TOKEN;
    else
      token = COMPUTER_TOKEN;
    gameBoard[move.square.getX()][move.square.getY()] = token;
  }

  Player opponent(Player player) {
    return (player == HUMAN) ? COMPUTER : HUMAN;
  }

  void switchTurn() { whoseTurn = opponent(whoseTurn); }

  Move findBestMove() {
    int rating;
    return findBestMove(0, rating);
  }

  Move findBestMove(int depth, int &rating) {
    Vector<Move> moveList;
    Move bestMove;
    int minRating = WINNING_POSITION + 1;
    generateMoveList(moveList);
    if (moveList.isEmpty())
      error("No moves available");
    for (Move move : moveList) {
      makeMove(move);
      switchTurn();
      int moveRating = evaluatePosition(depth + 1);
      if (moveRating < minRating) {
        bestMove = move;
        minRating = moveRating;
      }
      switchTurn();
      retractMove(move);
    }
    rating = -minRating;
    return bestMove;
  }

  int evaluatePosition(int depth) {
    if (gameIsOver() || depth >= MAX_DEPTH) {
      return evaluateStaticPosition();
    }
    int rating;
    findBestMove(depth, rating);
    return rating;
  }

  Point getPointFromID(int id) {
    switch (id) {
    case 1:
      return Point(0, 0);
    case 2:
      return Point(0, 1);
    case 3:
      return Point(0, 2);
    case 4:
      return Point(1, 0);
    case 5:
      return Point(1, 1);
    case 6:
      return Point(1, 2);
    case 7:
      return Point(2, 0);
    case 8:
      return Point(2, 1);
    case 9:
      return Point(2, 2);
    default:
      return Point(-1, -1);
    }
  }
  bool isAvailible(Move move) {
    if (gameBoard[move.square.getX()][move.square.getY()] == ' ')
      return true;
    else
      return false;
  }

  Move getUserMove() {
    Move move;
    while (true) {
      std::cout << "Your move." << std::endl;
      move.squareID = getInteger("What square? ");
      move.square = getPointFromID(move.squareID);
      if (!isAvailible(move) || move.squareID < 1 || move.squareID > 9)
        std::cout << "Not valid location." << std::endl;
      else
        break;
    }
    std::cout << "The game now looks like this:" << std::endl;
    return move;
  }

  void generateMoveList(Vector<Move> &moveList) {
    Move move;
    for (int i = 0; i < gameBoard.size(); i++) {
      for (int j = 0; j < gameBoard[0].size(); j++) {
        if (gameBoard[i][j] == ' ') {
          move.square = Point(i, j);
          move.squareID = i * 3 + j + 1;
          moveList.add(move);
        }
      }
    }
  }

  void retractMove(Move move) {
    gameBoard[move.square.getX()][move.square.getY()] = ' ';
  }

  bool isWinningToken(char token) {
    Vector<Set<char>> rows(3);
    Vector<Set<char>> columns(3);
    Vector<Set<char>> diagonals(3);
    for (int i = 0; i < gameBoard.size(); i++) {
      for (int j = 0; j < gameBoard[0].size(); j++) {
        rows[i].add(gameBoard[i][j]);
        columns[i].add(gameBoard[j][i]);
        if (i == j)
          diagonals[0].add(gameBoard[i][j]);
        if (i + j == 2)
          diagonals[1].add(gameBoard[i][j]);
      }
    }
    for (int i = 0; i < 3; i++) {
      if (i < 2 && diagonals[i].contains(token) && diagonals[i].size() == 1)
        return true;
      if (rows[i].contains(token) && rows[i].size() == 1)
        return true;
      if (columns[i].contains(token) && columns[i].size() == 1)
        return true;
    }
    return false;
  }

  bool isOneMoveAway(char token) {
    Vector<Set<char>> rows(3);
    Vector<Set<char>> columns(3);
    Vector<Set<char>> diagonals(3);
    for (int i = 0; i < gameBoard.size(); i++) {
      for (int j = 0; j < gameBoard[0].size(); j++) {
        rows[i].add(gameBoard[i][j]);
        columns[i].add(gameBoard[j][i]);
        if (i == j)
          diagonals[0].add(gameBoard[i][j]);
        if (i + j == 2)
          diagonals[1].add(gameBoard[i][j]);
      }
    }
    for (int i = 0; i < 3; i++) {
      if (i < 2 && diagonals[i].contains(token) && diagonals[i].contains(' ') &&
          diagonals[i].size() == 2)
        return true;
      if (rows[i].contains(token) && rows[i].contains(' ') &&
          rows[i].size() == 2)
        return true;
      if (columns[i].contains(token) && rows[i].contains(' ') &&
          columns[i].size() == 2)
        return true;
    }
    return false;
  }

  int evaluateStaticPosition() {
    if (isOneMoveAway(HUMAN_TOKEN))
      return LOSING_POSITION;
    if (isOneMoveAway(COMPUTER_TOKEN))
      return WINNING_POSITION;
    if (isWinningToken(HUMAN_TOKEN))
      return LOSING_POSITION;
    if (isWinningToken(COMPUTER_TOKEN))
      return WINNING_POSITION;
    return 0;
  }

  void announceResult() {
    std::cout << "The final position looks like this:" << std::endl;
    displayGame();
    if (isWinningToken(HUMAN_TOKEN))
      std::cout << "I lose." << std::endl;
    else if (isWinningToken(COMPUTER_TOKEN))
      std::cout << "I win." << std::endl;
    else
      std::cout << "Cat's game." << std::endl;
  }

  Vector<char> row0;
  Vector<char> row1;
  Vector<char> row2;
  Vector<Vector<char>> gameBoard;
  Player whoseTurn;
};

int main() {
  TicTacToe game;
  game.printInsructions();
  game.play();
  return 0;
}
