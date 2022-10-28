#include "game.hpp"
#include <iostream>
using std::max; using std::min;

// DATA(x, y) represents the symbol at xth row and yth column
#define DATA(x, y) data[y*size+x]

// true if first player wins, false otherwise.
// arg. player1 should be true only if it is 
// the first player making the move
void game::check(bool player1, int x, int y) {
    int tocheck = player1 ? sign1 : sign2; 
    if (to_win > 3) 
    {
        // perpendicular lines check 
        for (int i{0}; i < 2*to_win; i++) 
        {
            int ver{0}, hor{0}, diag1{0}, diag2{0};
            for (int j{0}; j<to_win; j++) {

                int xnew = x-i+j, ynew = y-i+j;

                // count if belongs to a certain line
                if ((0 <= xnew < size) &&
                    DATA(xnew, y) == tocheck) ver++;

                if ((0 <= y-i+j < size) &&
                    DATA(x, ynew) == tocheck) hor++;

                if ((0 <= xnew < size) && (0 <= ynew < size) &&
                    DATA(x, ynew) == tocheck) diag1++;

                if ((0 <= ynew < size) && (0 <= x-i-j < size) &&
                    DATA(x-i-j, ynew) == tocheck) diag2++; 
                
            }
            if (  ver == to_win || hor == to_win 
             || diag1 == to_win || diag2 == to_win) who_won = player1 ? 1 : 2;
        }
    }
    // } else 
    // {

    // }
}



