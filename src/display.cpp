#include "display.hpp"
#include <iostream>
#include <vector>

void gfx::display(std::vector<int> table, int size) 
{
    std::cout << "test3\n";
    // table[0] = 2;
    std::cout << table[0];
    std::cout << "test4\n";

    char s[] = {'#', 'X', 'O'};
    for (int x=0; x<size; x++) {
        for (int y=0; y<size; y++) {
            std::cout << table[y*size + x];
            std::cout << x << y << size;
        } 
        std::cout << "\n";
    }   
}