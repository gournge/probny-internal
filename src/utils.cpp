#include "utils.hpp"

bool uts::Pos::below(int m) 
{
    return (0 <= x) and (x < m) and
           (0 <= y) and (y < m);
}

uts::Pos::Pos()
{ }

uts::Pos::Pos(int nx, int ny) : x(nx), y(ny)
{ }

// - - -

uts::State::State() 
{ }

uts::State::State(int s) : 
size(s)
{
    data = std::vector<uts::Sign>(size*size);
}

void uts::State::put(uts::Sign s, uts::Pos p)
{
    data[p.y*size + p.x] = s;
}

uts::Sign uts::State::at(uts::Pos p) 
{
    return data[p.y*size + p.x];
}

uts::Sign uts::State::at(int x, int y)
{
    return at(uts::Pos{x, y});
}

bool uts::State::empty(uts::Pos p)
{
    return at(p) == uts::empty;
}

// - - -

