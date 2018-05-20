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
    return false;
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

  std::ostream & operator<< (std::ostream & os, const TTT & board) {
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
