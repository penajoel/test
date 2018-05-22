#include "ttt.h"
#include <ostream>
#include <vector>

namespace solution {

  TTT::TTT (const int rows, const int columns) {
    std::vector < char >toCopy;
    for (int i = 0; i < columns; ++i) {
      toCopy.push_back (d_empty);
    } for (int i = 0; i < rows; ++i) {
      d_board.push_back (toCopy);
    }
  }

  bool TTT::isWinner () const {
    for (int i = 0; i < d_board.size (); ++i) {
      if (checkHorizontal (i)) {
	return true;
      }
    }
    for (int i = 0; i < d_board[0].size (); ++i) {
      if (checkVertical (i)) {
	return true;
      }
    }
    return checkDiagonal();
  }

  bool TTT::checkVertical (const int column) const {
    for (int i = 0; i < d_board.size (); ++i) {
      if (d_board[i][column] != d_currentPlayer) {
	return false;
      }
    }
    return true;
  }

  bool TTT::checkHorizontal (const int row) const {
    for (int i = 0; i < d_board[row].size (); ++i) {
      if (d_board[row][i] != d_currentPlayer) {
	return false;
      }
    }
    return true;
  }

  bool TTT::checkDiagonal() const {
    if (d_board.size() != d_board[0].size()) {
        return false;
    }
    bool isWinner = true;
    int horizontalIndex = 0;
    int verticalIndex = 0;
    while(horizontalIndex != d_board.size() && verticalIndex != d_board.size()) {
        if (d_board[horizontalIndex][verticalIndex] != d_currentPlayer) {
            isWinner = false;
            break;
        }
        ++horizontalIndex;
        ++verticalIndex;
    }
    if (isWinner) {
        return isWinner;
    }
    isWinner = true;
    horizontalIndex = d_board.size() - 1;
    verticalIndex = 0;
    while(horizontalIndex != -1 && verticalIndex != d_board.size()) {
        if (d_board[horizontalIndex][verticalIndex] != d_currentPlayer) {
            isWinner = false;
            break;
        }
        --horizontalIndex;
        ++verticalIndex;
    }
    return isWinner;
  }
  

  std::ostream & operator<< (std::ostream & os, const TTT& board) {
    for (auto it = board.d_board.begin (); it != board.d_board.end (); ++it) {
      os << '|';
      for (auto jt = it->begin (); jt != it->end (); ++jt) {
	os << *jt;
	os << '|';
      }
      os << '\n';
    }
    return os;
  }

}
