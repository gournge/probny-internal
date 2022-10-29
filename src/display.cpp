#include "display.hpp"
#include <iostream>
#include <vector>

void gfx::display(std::vector<int> table, int size) 
{
    char s[] = {' ', 'X', 'O'};
    for (int x=0; x<size-1; x++) {
        for (int y=0; y<size-1; y++) {
            std::cout << s[table[y*size + x]] << '|';
        } 
        std::cout << s[table[(size-1)*size + x]] << '\n';
        for (int y=0; y<2*size-1; y++) {
            std::cout << '-';
        } 
        std::cout << '\n';
    }
    for (int y=0; y<size-1; y++) {
        std::cout << s[table[size*(y+1)-1]] << '|';
    } 
    std::cout << s[table[size*size-1]] << '\n' << '\n';  
}
