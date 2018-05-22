#ifndef TTT_HEADER
#define TTT_HEADER

#include <ostream>
#include <vector>
namespace solution {
    class TTT {
      public:
        // Constructor for class. Defaults to 3 by 3 board
        TTT (const int rows = 3, const int columns = 3);
        // Sets grid at row and column to current player
        // Returns false if location is already set, else true
        bool insert (const int row, const int column);
        // Checks for a winner based on the current player
        bool isWinner () const;
        // switches current player 
        void switchPlayer ();
        // overload for printing
        friend std::ostream & operator<< (std::ostream & os,
                                          const TTT & board);
      private:
          bool checkVertical (const int column) const;
        bool checkHorizontal (const int row) const;
        bool checkDiagonal () const;
          std::vector < std::vector < char >>d_board;
        char d_currentPlayer = 'x';
        char d_secondPlayer = 'o';
        char d_empty = ' ';
    };

    inline void TTT::switchPlayer () {
        char temp = d_currentPlayer;
          d_currentPlayer = d_secondPlayer;
          d_secondPlayer = temp;
    } inline bool TTT::insert (const int row, const int column) {
        if(row < 0 || column < 0) {
            return false;
        }
        if(row >= d_board.size () || column >= d_board[0].size ()) {
            return false;
        }
        if(d_board[row][column] != d_empty) {
            return false;
        }
        d_board[row][column] = d_currentPlayer;
        return true;
    }
}
#endif
