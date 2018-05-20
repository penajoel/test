#include <iostream>
#include "ttt.h"

void
getInput (solution::TTT& board) {
    int row = 0;
    int column = 0;
    while (1) {
        std::cout << "Row: ";
        std::cin >> row;
        std::cout << "Column: ";
        std::cin >> column;
        if (board.insert(row, column)) {
            return;
        }
        std::cout << "Space is already taken/Invalid location. Please reselect!\n";
    }
}

bool turn(const int playerNum, solution::TTT& board) {
    std::cout << "Player " << playerNum << "'s turn:\n"; 
    std::cout << board;
    getInput(board);
      if (board.isWinner()) {
      std::cout << "Player " << playerNum << " is winner\n";
      std::cout << board;
      return true;
    }
    board.switchPlayer();
    return false;
}

int
main () {
  solution::TTT game;
  std::cout << "Game start\n";
  while (1) {
    if (turn(1, game)) {
        break;
    }
    if (turn(2, game)) {
        break;
    }
  }
  return 0;
}
