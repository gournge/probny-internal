#include "utils.hpp"
#include <algorithm>
#include <utility>
#include <iostream>
using std::max;
using std::min;


typedef uts::State st;
typedef uts::Pos p;

// - returns the best atttainable score
// - it doesnt matter if sign is circle or cross
// - Cross is maximizing Circle is minimizing
int uts::minimax(
st& state, uts::Sign sign, int depth, p pos)
{   
    if (uts::check(state, sign, pos)) 
    {
        return sign == uts::Cross ? 1 : -1;
    }
    auto opts = uts::options(state);
    if (!depth || !opts.size()) return 0;
    
    if (sign == uts::Cross)
    {
        int max_eval = -2;
        for (p child : opts)
        {
            state.put(sign, child);
            int eval = uts::minimax(state, uts::Circle, depth-1, pos);
            max_eval = max(max_eval, eval);
            state.put(uts::empty, child);
        }
        return max_eval;
    } 
    else
    {
        int min_eval  = 2;
        for (p child : opts)
        {
            state.put(sign, child);
            int eval = uts::minimax(state, uts::Cross, depth-1, pos);
            min_eval = min(min_eval, eval);
            state.put(uts::empty, child);
        }
        return min_eval;
    }

}

bool uts::check(st& state, uts::Sign sign, p pos)
{
    if (!pos.below(state.size)) return 0;

    int to_win = state.size > 4 ? 4 : 3;

    // perpendicular lines check 
    for (int i{0}; i < to_win; i++) 
    {
        int ver{1}, hor{1}, diag1{1}, diag2{1};
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

            // std::cout << i << " " << j << "\n";
            // std::cout << ver << " " << hor << " " 
            //         << diag1 << " " << diag2 << "\n";    
            // std::cout << " - - - \n";
        }
        if (ver == to_win || hor == to_win || 
          diag1 == to_win || diag2 == to_win) return 1;
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