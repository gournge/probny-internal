#include "game.hpp"
#include <iostream>


#define ASK(IN, OUT) std::cout << OUT; std::cin >> IN; std::cout << "\n";


Game::Game()
{ 
    int size;
    ASK(size, "Enter the size of the TicTacToe grid: ")
    ASK(if_computer, "Do you want to play against a computer? (0/1) ")

    state = uts::State(size);
    
    if (if_computer) {
        ASK(name1, "What is the player's 1 name? ");
        name2 = "Computer";
    } else {
        ASK(name1, "What is player's 1 name? ");
        ASK(name2, "What is player's 2 name? ");
    } 

    bool one_circle;
    ASK(one_circle, "Is player's 1 sign circle? (0/1) ");
    sign1 = !one_circle ? uts::Circle : uts::Cross;
    sign2 = !one_circle ? uts::Cross : uts::Circle;


    std::cout << "Who will play first is now being randomly chosen.\n";

    auto gen = std::bind(std::uniform_int_distribution<>(0,2),std::default_random_engine());
    is_1_first = gen();
    who_won = uts::empty;
    skip = 0;

    play();
}

void Game::play() 
{  
    do {
        if (!skip) display();

        if (is_1_first) {
            player1();
            if (!skip) display();
            if (who_won != uts::empty) break;
            player2();
        } else {
            player2();
            if (!skip) display();
            if (who_won != uts::empty) break;
            player1();
        }

    } while (who_won == uts::empty);
   
    std::cout << "Player " << ((who_won == sign1) ? name1 : name2) << " won!";
}

void Game::player1() 
{
    if ((who_won != uts::empty) || skip) 
    { skip=0; return; } 

    uts::Pos p;
    std::cout << name1 << " moves at:\n";
    std::cin >> p.x >> p.y;

    // if occupied or invalid
    if (!state.empty(p) || !p.below(state.size))
    { 
        skip=1; 
        std::cout << "try again!\n"; 
        return; 
    }

    state.put(sign1, p);

    who_won = check(sign1, p) ? sign1 : uts::empty;
}

void Game::player2() 
{
    if ((who_won != uts::empty) || skip) 
    { skip=0; return; } 

    uts::Pos p{-1, -1}; // init with value for Game:machine 
    if (if_computer) {
        std::cout << "Computer moves:\n";
        machine(p);
        std::cout << p.x << " " << p.y << "\n";
    } else {
        std::cout << name2 << " moves at:\n";
        std::cin >> p.x >> p.y;
    }

    // if occupied or invalid
    if (!state.empty(p) || !p.below(state.size))
    { 
        skip=1; 
        std::cout << "try again!\n"; 
        return; 
    }

    state.put(sign2, p);

    who_won = check(sign2, p) ? sign2 : uts::empty;
}

void Game::machine(uts::Pos& final)
{
    auto opts = uts::options(state);

    int win = (sign2 == uts::Circle) ? -1 : 1;

    for (auto pos : opts) 
    {
        if (uts::eval(state, sign2, pos) == win)
        {
            final = pos;
            return;
        }
    }
    final = opts[0];
}

bool Game::check(uts::Sign sign, uts::Pos pos)
{
    return uts::check(state, sign, pos);
}