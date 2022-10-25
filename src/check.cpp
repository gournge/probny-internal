#include "game.hpp"

// true if gm::signs::empty
bool gm::game::empty() {
    return data[x*(size-1)+y] == gm::signs::empty;
}


// true if first player wins, false otherwise
bool gm::game::check() {
    for 
}