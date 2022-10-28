#include "display.hpp"
#include <iostream>
#include <vector>
using std::vector;

void gfx::display(vector<gfx::sint> data, int size) 
{
    std::cout << "test1";
    data[0] = 2;
    std::cout << data[0];
    std::cout << "test2";

    char s[] = {'#', 'X', 'O'};
    for (int x=0; x<size; x++) {
        for (int y=0; y<size; y++) {
            std::cout << data[y*size + x];
            std::cout << x << y << size;
        } 
        std::cout << "\n";
    }   
}