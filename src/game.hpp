#include "utils.hpp"
#include <iostream>
#include <functional>
#include <random>

class Game 
{
    public:
        Game();

    private:
        uts::State state;
        int to_win;

        bool is_1_first;
        bool if_computer;
        uts::Sign   sign1, sign2;
        std::string name1, name2;

        bool skip;
        uts::Sign who_won;

        void play();
        void display();

        // move in a position (pvp)
        void player1();
        void player2(); 

        // move in machine vs human 
        // pos gets the value 
        void machine(uts::Pos&);

        bool check(uts::Sign, uts::Pos);

};