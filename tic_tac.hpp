#pragma once 

#include <iostream>
#include <vector>
# define SIZE 3
using namespace std;

class Tic_Tac_Toe
{
    private:

        char **board;
        int player;
        int row, col;

    public:

        Tic_Tac_Toe();
        void setRow(int r);
        void setCol(int c);
        void Play();
        void printBoard();
        bool checkWin(char player); 
        ~Tic_Tac_Toe();       
};

