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
    sign1 = one_circle ? uts::Circle : uts::Cross;
    sign2 = one_circle ? uts::Cross : uts::Circle;


    std::cout << "Who will play first is now being randomly chosen.\n";

    auto gen = std::bind(std::uniform_int_distribution<>(0,2),std::default_random_engine());
    is_1_first = gen();

    skip = 0;

    play();
}

void Game::play() 
{  
    do {
        display();

        if (is_1_first) {
            player1();
            if (!skip) display();
            player2();
        } else {
            player2();
            if (!skip) display();
            player1();
        }

    } while (who_won);
   
    std::cout << "Player " << (who_won == 1 ? name1 : name2) << " won!";
}

void Game::player1() 
{
    if (!who_won || skip) 
    { skip=0; return; } 

    uts::Pos p;
    std::cout << name1 << " moves at:\n";
    std::cin >> p.x >> p.y;

    // if occupied or invalid
    if (!state.at(p) || !p.below(state.size))
    { 
        skip=1; 
        std::cout << "try again!\n"; 
        return; 
    }

    state.put(sign1, p);

    who_won = check(sign1, p) ? sign1 : sign2;
}

void Game::player2() 
{
    if (!who_won || skip) 
    { skip=0; return; } 

    uts::Pos p{-1, -1}; // init with value for Game:machine 
    if (if_computer) {
        machine(p);
        std::cout << "Computer moves:\n";
        std::cout << p.x << " " << p.y << "\n";
    } else {
        std::cout << name2 << " moves at:\n";
        std::cin >> p.x >> p.y;
    }

    // if occupied or invalid
    if (!state.at(p) || !p.below(state.size))
    { 
        skip=1; 
        std::cout << "try again!\n"; 
        return; 
    }

    state.put(sign2, p);

    who_won = check(sign2, p) ? sign2 : sign1;
}

void Game::machine(uts::Pos& final)
{
    if(sign2 == uts::Circle) 
    {
        int best_v = 2;
        uts::Pos best_p;
        for (auto temp_p : uts::options(state)) 
        {
            state.put(sign2, temp_p);

            int temp_v = uts::minimax(state, sign2, state.data.size(), temp_p); 
            if (temp_v < best_v)
            {
                best_p = temp_p;
                best_v = temp_v;
            }
            state.put(uts::empty, temp_p);
        }
        final = best_p;
    }
    else
    {
        int best_v = -2;
        uts::Pos best_p;
        for (auto temp_p : uts::options(state)) 
        {
            state.put(sign2, temp_p);

            int temp_v = uts::minimax(state, sign2, state.data.size(), temp_p); 
            if (temp_v > best_v)
            {
                best_p = temp_p;
                best_v = temp_v;
            }
            state.put(uts::empty, temp_p);
        }
        final = best_p;
    }
}

bool Game::check(uts::Sign sign, uts::Pos pos)
{
    return uts::check(state, sign, pos);
}