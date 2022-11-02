#include "game.hpp"

int main() 
{
    uts::State s(3);
    s.put(uts::Cross, uts::Pos{0, 0});
    s.put(uts::Cross, uts::Pos{0, 1});
    s.put(uts::Cross, uts::Pos{1, 1});
    s.put(uts::Circle, uts::Pos{0, 2});
    s.put(uts::Circle, uts::Pos{2, 0});
    s.put(uts::Circle, uts::Pos{2, 1});

    // X X O
    //   X  
    // O O 


    uts::Pos p{-1, -1};
    uts::minimax(s, uts::Circle, 10, p);
    std::cout << p.x << " " << p.y << "\n";

    return 0;
}