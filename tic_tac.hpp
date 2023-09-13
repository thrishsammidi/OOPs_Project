#pragma once 

#include <iostream>
using namespace std;

class Player;

class Board
{
    public:
        char **board;
        int size;
        friend class Player;
};

class Player
{
    private:

        char currPlayer;
        int row, col;

    public:

        Player(Board &b,char player);   // parameterized constructor
        Player(Player &p); // copy constructor
        friend ostream& operator<<(ostream& os, const Board& b);    // Operator overloading 
        void Play(Board &b);
        void dispCoords(Board &b);
        bool checkWin(char player,Board &b); 
        ~Player();  // Destructor
};