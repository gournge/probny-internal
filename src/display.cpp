#include "game.hpp"

void Game::display() 
{
    auto &t {state.data}; auto s {state.size};
    char c[] = {' ', 'X', 'O'};
    for (int x=0; x<s-1; x++) {
        for (int y=0; y<s-1; y++) {
            std::cout << c[t[y*s + x]] << '|';
        } 
        std::cout << c[t[(s-1)*s + x]] << '\n';
        for (int y=0; y<2*s-1; y++) {
            std::cout << '-';
        } 
        std::cout << '\n';
    }
    for (int y=0; y<s-1; y++) {
        std::cout << c[t[s*(y+1)-1]] << '|';
    } 
    std::cout << c[t[s*s-1]] << '\n' << '\n';  
}
