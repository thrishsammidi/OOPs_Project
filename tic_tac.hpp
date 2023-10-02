#pragma once 

#include <iostream>
using namespace std;

class Player;

class Board
{
    public:
        Board();
        char **board;   // dynamic 2d array for creating a board
        const int size;     // constant size variable representing size of board
        friend class Player;    // making Player class as a friend so that it can access all the data members
        ~Board();      // destructor to delete the dynamically created array
};

class Player
{
    private:

        char currPlayer;    // private data members
        int row, col;

    public:
        static int num_steps;
        Player(Board &b,char player);   // parameterized constructor
        Player(Player &p); // copy constructor
        friend ostream& operator<<(ostream& os, const Board& b);    // Operator overloading 
        void Play(Board &b);    // displays the updated board
        void dispCoords(Board &b);  // displays the cell coordinates of the box
        void dispCoords();      // Function Overloading
        bool checkWin(char player,Board &b);    // checks for the victory
        inline void reset_num_steps();      // displaying use of inline function by resetting num_steps to 0
        Player& checkMatchOver();       // displays the use of this pointer
        ~Player();
};
