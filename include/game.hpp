#include <iostream>
#include <vector>
#include "minimax.hpp"
using std::vector;

namespace gm 
{

enum sign {empty, Circle, Cross};

class game 
{
    private:
        int size; bool if_computer;
        std::string name1, name2;
        vector<gm::sign> data;
        sign sign1;
    public:
        game();
        // move in a position (pvp)
        void player1(int, int);
        void player2(int, int); 

        // move in machine vs human 
        void machine();
};

}