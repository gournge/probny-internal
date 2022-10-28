#include "game.hpp"
#include "display.hpp"
#include "minimax.hpp"

#define ASK(IN, OUT) std::cout << OUT; std::cin >> IN; std::cout << "\n";

gm::game::game()
{ 
    ASK(size, "Enter the size of the TicTacToe grid: ")
    ASK(if_computer, "Do you want to play against a computer? (0/1) ")

    std::vector<gm::sint> data(size*size, 0);
    
    if (if_computer) {
        ASK(name1, "What is the player's 1 name? ");
        name2 = "Computer";
    } else {
        ASK(name1, "What is player's 1 name? ");
        ASK(name2, "What is player's 2 name? ");
    }

    ASK(sign1, "Is player's 1 sign circle? (0/1) ");
    sign2 =  sign1 == 1 ? sign2 : sign1;


    std::cout << "Who will play first is now being randomly chosen.\n";

    auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    is_1_first = gen();
    // std::cout << is_1_first;

    to_win = size > 4 ? 5 : 3;
    who_won = 0;
    skip = 0;

    play();
}

void gm::game::play() 
{   
    do {
        display();

        if (is_1_first) {
            player2();
            player1();
        } else {
            player2();
            player1();
        }

    } while (!who_won);
   
    std::cout << "Player " << (who_won == 1 ? name1 : name2) << "won!";
}

// make a move
void gm::game::player1() 
{
    if (who_won || skip) { skip=0; return; } 
    gm::sint x, y;
    std::cout << name1 << " moves at:\n";
    std::cin >> x >> y;

    // if occupied
    if (data[y*(size) + x]) { skip=1; return; }

    data[y*(size) + x] = sign1;

    check(1, x, y);
}

void gm::game::player2() 
{
    if (who_won || skip) { skip=0; return; } 

    gm::sint x, y;
    if (if_computer) {
        machine(x, y);
        std::cout << "Computer moves:\n";
        std::cout << x << " " << y << "\n";
    } else {
        std::cout << name2 << " moves at:\n";
        std::cin >> x >> y;
    }

    // if occupied
    if (data[y*(size) + x]) { skip=1; return; }

    data[y*(size) + x] = sign2;

    check(0, x, y);
}

// calculate next move on x, y
void gm::game::machine(gm::sint& x, gm::sint& y)
{
    alg::t_minimax(data, x, y, is_1_first);
}

// display
void gm::game::display() 
{
    std::cout << data[3]; // why not working?
    gfx::display(data, size);
}