#include <vector>
#include <utility>

namespace uts
{

enum Sign
{
    //  0,     1,      2
    empty, Cross, Circle
}; 

struct Pos 
{
    int x; int y;

    Pos();
    Pos(int, int);

    // if x and y are both positive
    // and below some value
    bool below(int); 
};

struct State
{
    std::vector<Sign> data;
    int size; 

    State();
    State(int);
    void put(Sign, Pos);
    Sign at(Pos);
    Sign at(int, int);
    bool empty(Pos);
};

int              minimax(State&, Sign, int, Pos);
bool             check  (State&, Sign, Pos);
std::vector<Pos> options(State&);

}
