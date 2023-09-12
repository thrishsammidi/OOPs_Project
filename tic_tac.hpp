#pragma once 

#include <iostream>
#include <vector>
using namespace std;

class Tic_Tac_Toe
{
    private:

        char **board;
        char currPlayer;
        int row, col;
        int size;

    public:

        Tic_Tac_Toe();
        void Play();
        void printBoard();
        void dispCoords();
        bool checkWin(char player); 
        ~Tic_Tac_Toe();       
};

