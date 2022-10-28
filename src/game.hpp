#include <iostream>
#include <vector>
#include <functional>
#include <random>

class game 
{
public:
    game();
    std::vector<int> data;
private: 
    bool if_computer;
    int size; 
    int to_win; // # of signs in line to win

    // sign of the first player
    int sign1, sign2; 
    std::string name1, name2;

    bool is_1_first;
    int who_won; // 0 no one, 1 player one, 2 player two
    bool skip; // in case of mistake, skip the round

    void play();

    // move in a position (pvp)
    void player1();
    void player2(); 

    // first arg only true if we are checking player 1
    void check(bool, int, int);

    // return a move in machine vs human 
    void machine(int&, int&);

    void display();
};
