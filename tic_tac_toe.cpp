#include <iostream>
#include <vector>
#include "tic_tac.hpp"

using namespace std;


Tic_Tac_Toe::Tic_Tac_Toe()
{   
    size = 3;   // initializes the size to be 3
    currPlayer = 'X';   // player X starts the game

    board = new char*[size];    // dynamically creating new array ( rows )

    for(int i=0;i<size;i++)
        board[i] = new char[size];   // dynamically creating new array ( columns )

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            board[i][j] = ' ';  // initializing the array cells with space
        }
    }
}


Tic_Tac_Toe::~Tic_Tac_Toe()
{
    delete board;   // deleting the dynamically created pointer to prevent memory leak
}

// Function to print the Tic Tac Toe board
void Tic_Tac_Toe::printBoard() {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j];    // prints the value of the cell of board matrix
            if (j < 2) cout << " | ";   // adding a vertical bar after every array value
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

void Tic_Tac_Toe::dispCoords()
{
    cout<<"\n";
    cout<<"Coordinates of each cell \n";
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "("<<i+1<<","<<j+1<<")";
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "----------------------" << endl;
    }
    cout<<"\n";
}

// Function to check if a player has won
bool Tic_Tac_Toe::checkWin(char player) {

    for (int i = 0; i < 3; i++) {

        // checks the possibilities of victory for players and returns true or false based on it

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

    for (int move = 1; move <= 9; move++) {

        dispCoords();   // displaying the rows and column number for the board cell
        printBoard();   // displaying the updated board
        
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
        board[row - 1][col - 1] = currPlayer;   // assigning the symbol of the user to grid to the chosen cell

        // Print the updated board
        printBoard();  

        // Check if the current player has won
        if (checkWin(currPlayer)) {
            cout << "Player " << currPlayer << " wins! Congratulations!" << endl;
            break;
        }

        // Switch to the other player
        currPlayer = (currPlayer == 'X') ? 'O' : 'X';   // switches player every round
    }

    // If no one has won after 9 moves, it's a draw
    if (checkWin('X') == false && checkWin('O') == false) {
        cout << "It's a draw! The game is over." << endl;
    }
}
