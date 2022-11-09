#include "game.hpp"

int main() 
{


    // X X O
    //   X  
    // O O 

    // // should cout 1, 1 
    // std::cout << uts::check(s, uts::Cross, uts::Pos{2, 2}) << "\n";
    // std::cout << uts::check(s, uts::Circle, uts::Pos{2, 2}) << "\n";


    // // should cout 3
    // std::cout << uts::options(s).size() << "\n";


    // // should cout 2, 2 \n 2, 2 
    // uts::Pos p{-1, -1};
    // uts::minimax(s, uts::Circle, 10, p);
    // std::cout << p.x << " " << p.y << "\n";

    // uts::minimax(s, uts::Cross, 10, p);
    // std::cout << p.x << " " << p.y << "\n";

    // X X O
    // O X O 
    // O O 

    // // uts::Pos p(-1, -1);
    // uts::State s(3);
    // s.put(uts::Circle, uts::Pos{0, 0});
    // s.put(uts::Cross,  uts::Pos{0, 1});

    // for (auto p : uts::options(s)) 
    // {
    //     std::cout << uts::minimax(s, uts::Circle, 10, p) << "\n";
    //     std::cout << p.x << " " << p.y << "\n";
    // }
    Game game;
    return 0;
}