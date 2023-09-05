#include <iostream>
#include <vector>
#include "tic_tac.hpp"

using namespace std;


Tic_Tac_Toe::Tic_Tac_Toe()
{
    board = new char*[3];

    for(int i=0;i<3;i++)
        board[i] = new char[3]; 

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j] = ' ';
        }
    }
}

Tic_Tac_Toe::~Tic_Tac_Toe()
{
    delete board;
}

// Function to print the Tic Tac Toe board
void Tic_Tac_Toe::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

void Tic_Tac_Toe::setRow(int r) {
    row = r;
}

void Tic_Tac_Toe::setCol(int c) {
    col = c;
}

// Function to check if a player has won
bool Tic_Tac_Toe::checkWin(char player) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

void Tic_Tac_Toe::Play()
{
    cout << "Welcome to Tic Tac Toe!\n";

    char currPlayer = 'X';
    int row,col;

    for (int move = 1; move <= 9; move++) {
        cout << "Player " << currPlayer << ", enter row and column (e.g., 1 2): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout<<row<<" "<<col<<endl;
            cout << "Invalid move! Try again." << endl;
            move--;  // Retry the same move
            continue;
        }

        // Make the move
        board[row - 1][col - 1] = currPlayer;

        // Print the updated board
        printBoard();

        // Check if the current player has won
        if (checkWin(currPlayer)) {
            cout << "Player " << currPlayer << " wins! Congratulations!" << endl;
            break;
        }

        // Switch to the other player
        currPlayer = (currPlayer == 'X') ? 'O' : 'X';
    }

    // If no one has won after 9 moves, it's a draw
    if (checkWin('X') == false && checkWin('O') == false) {
        cout << "It's a draw! The game is over." << endl;
    }
}
