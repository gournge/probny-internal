#include <iostream>
#include <vector>
#include <functional>
#include <random>

using std::vector;

namespace gm 
{

typedef unsigned short int sint;

class game 
{
public:
        game();
        vector<sint> data;


    private: 
        bool if_computer;
        int size; 
        int to_win; // # of signs in line to win

        // sign of the first player
        sint sign1, sign2; 
        std::string name1, name2;

        bool is_1_first;
        sint who_won; // 0 no one, 1 player one, 2 player two
        bool skip; // in case of mistake, skip the round

        void play();

        // move in a position (pvp)
        void player1();
        void player2(); 

        // first arg only true if we are checking player 1
        void check(bool, sint, sint);

        // return a move in machine vs human 
        void machine(sint&, sint&);

        void display();
};

}