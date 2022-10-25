#include "game.hpp"
#include <iostream>
using std::vector;

gm::game::game()
{ 
    int s; bool machine;
    std::cout << "Enter the size of the TicTacToe grid: ";
    std::cin >> size;
    std::cout << "\n";

    std::cout << "Do you want to play against a computer? (0/1) ";
    std::cin >> machine;
    std::cout << "\n";
    size=s; if_computer=machine;

    vector<gm::signs> data(size*size);

    if (if_computer) {
        std::cout << "What is the player's name? ";
        std::cin >> name1;
        std::cout << "\n";
        name2 = "Computer";
    } else {
        std::cout << "What is player's 1 name? ";
        std::cin >> name1;
        std::cout << "\n";
        
        std::cout << "What is player's 2 name? ";
        std::cin >> name2;
        std::cout << "\n";
    }

    bool temp;
    std::cout << "Is player's 1 sign circle? (0/1) ";
    std::cin >> temp;
    std::cout << "\n";
    sign1 = temp ? gm::signs::Circle : gm::signs::Cross;
}

void gm::game::player1(int x, int y) 
{
    // 0 <= x, y < size 
    data[x*(size-1) + y] = sign1;
}

void gm::game::player2(int x, int y) 
{
    // 0 <= x, y < size 
    data[x*(size-1) + y] = 
    sign1 == gm::signs::Circle ? gm::signss::Cross : gm::signs::Circle;
}
