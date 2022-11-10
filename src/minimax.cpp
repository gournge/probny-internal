#include "utils.hpp"
#include <algorithm>
#include <utility>
#include <iostream>
using std::max;
using std::min;


typedef uts::State st;
typedef uts::Sign  sn;
typedef uts::Pos    p;

// evaluate the action of putting a sign at a pos during a state
// the sign is not yet put on the board
// cross max
// circle min
int uts::eval(st& state, sn sign, p pos)
{
    state.put(sign, pos);

    auto opts = uts::options(state);

    // if no options : it is a draw
    if (!opts.size()) 
    { 
        state.put(sn::empty, pos);
        return 0; 
    }

    // eval of putting a sign at pos
    if (uts::check(state, sign, pos)) 
    {   
        state.put(sn::empty, pos);
        return (sign == sn::Cross) ? 1 : -1;
    }

    auto other = (sign == sn::Circle) ? sn::Cross : sn::Circle;

    for (p child : opts)
    {
        state.put(sign, child);
        int e = eval(state, other, child);
        state.put(sn::empty, child);

        if (e != 0) 
        { 
            state.put(sn::empty, pos);
            return e;
        }
    }
    state.put(sn::empty, pos);
    return 0;
}

// if putting a sign at a pos (on a grid "state") will result in a win
bool uts::check(st& state, uts::Sign sign, p pos)
{
    if (!pos.below(state.size)) return 0;

    int to_win = (state.size > 4) ? 4 : 3;
    int init_val = state.empty(pos) ? 1 : 0;
    
    // perpendicular lines check 
    for (int i{0}; i < to_win; i++) 
    {
        int ver{init_val}, hor{init_val}, diag1{init_val}, diag2{init_val};
        for (int j{0}; j<to_win; j++) {

            int xnew = pos.x-i+j, ynew = pos.y-i+j;

            // count if belongs to a certain line
            if (p{xnew, 0}.below(state.size) &&
                state.at(xnew, pos.y) == sign) ver++;

            if (p{0, pos.y-i+j}.below(state.size) &&
                state.at(pos.x, ynew) == sign) hor++;

            if (p{xnew, ynew}.below(state.size) &&
                state.at(xnew, ynew) == sign) diag1++;

            if (p{pos.x-i-j, ynew}.below(state.size) &&
                state.at(pos.x-i-j, ynew) == sign) diag2++;  

            // std::cout << "\n" << i << " " << j << "\n";
            // std::cout << ver << " " << hor << " " 
            //         << diag1 << " " << diag2 << "\n";    
            // std::cout << to_win << "\n";
            // std::cout << " - - - \n";
        }
        if ((ver >= to_win) || (hor >= to_win) || 
          (diag1 >= to_win) || (diag2 >= to_win)) return 1;
    }
    return 0;
}

std::vector<p> uts::options(st& state)
{
    std::vector<p> ret;
    for (int x{0}; x<state.size; x++) {
        for (int y{0}; y<state.size; y++) {
            if(state.empty(p{x, y})) ret.push_back(p{x, y});
        }
    }
    return ret;
}