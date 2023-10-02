#include <iostream>
#include "tic_tac.hpp"

using namespace std;

Board::Board():size(3)  // initializes the size to be 3 using initializer list
{
    board = new char*[size];    // dynamically creating new array ( rows )

    for(int i=0;i<size;i++)
        board[i] = new char[size];   // dynamically creating new array ( columns )
}

Board::~Board()
{
    delete []board;     // deletion of dynamically created array
}

Player::Player(Board &b,char player)
{   
    currPlayer = player;   // player X starts the game

    for(int i=0;i<b.size;i++)
    {
        for(int j=0;j<b.size;j++)
        {
            b.board[i][j] = ' ';  // initializing the array cells with space
        }
    }
}

Player::Player(Player &p)
{
    currPlayer = p.currPlayer;
}

// Overloaded Operator to print the Tic Tac Toe board
ostream& operator<<(ostream &os, const Board &b)
{
    // TODO: insert return statement here
    for (int i = 0; i < b.size; i++) {
        for (int j = 0; j < b.size; j++) {
            os << b.board[i][j];    // prints the value of the cell of board matrix
            if (j < 2) os << " | ";   // adding a vertical bar after every array value
        }
        os << endl;
        if (i < 2) os << "---------" << endl;
    }
    return os;
}

void Player::dispCoords(Board &b)
{
    cout<<"\n";
    cout<<"Coordinates of each cell \n";
    
    for (int i = 0; i < b.size; i++) {
        for (int j = 0; j < b.size; j++) {
            cout << "("<<i+1<<","<<j+1<<")";
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "----------------------" << endl;
    }
    cout<<"\n";
}

void Player::dispCoords()
{
    cout<<"Number of moves made in this match: "<<num_steps<<"\n";
}

// Function to check if a player has won
bool Player::checkWin(char player,Board &b) {

    for (int i = 0; i < 3; i++) {

        // checks the possibilities of victory for players and returns true or false based on it

        if (b.board[i][0] == player && b.board[i][1] == player && b.board[i][2] == player) return true;
        if (b.board[0][i] == player && b.board[1][i] == player && b.board[2][i] == player) return true;
    }

    if (b.board[0][0] == player && b.board[1][1] == player && b.board[2][2] == player) return true;
    if (b.board[0][2] == player && b.board[1][1] == player && b.board[2][0] == player) return true;
    
    return false;
}

void Player::Play(Board &b)
{
    cout << "Welcome to Tic Tac Toe!\n";

    for (int move = 1; move <= 9; move++) {

        dispCoords(b);   // displaying the rows and column number for the board cell
        cout<<b;   // displaying the updated board
        
        cout << "Player " << currPlayer << ", enter row and column (e.g., 1 2): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || b.board[row - 1][col - 1] != ' ') {
            cout<<row<<" "<<col<<endl;
            cout << "Invalid move! Try again." << endl;
            move--;  // Retry the same move
            continue;
        }

        // Make the move
        b.board[row - 1][col - 1] = currPlayer;   // assigning the symbol of the user to grid to the chosen cell

        // Print the updated board
        cout<<b;  

        num_steps++;

        // Check if the current player has won
        if (checkWin(currPlayer,b)) {
            cout << "Player " << currPlayer << " wins! Congratulations!" << endl;
            // function overloading 
            dispCoords();   //displays number of steps made in the game to find a winner
            break;
        }

        // Switch to the other player
        currPlayer = (currPlayer == 'X') ? 'O' : 'X';   // switches player every round
    }

    // If no one has won after 9 moves, it's a draw
    if (checkWin('X',b) == false && checkWin('O',b) == false) {
        cout << "It's a draw! The game is over." << endl;
    }
}

void Player::reset_num_steps()
{
    num_steps = 0;
}

Player::~Player()
{
    reset_num_steps();  // displays use of explicit inline functions
}

Player& Player::checkMatchOver()
{
    if(num_steps < 9)
    {
        cout<<"Match over and we got a winner!\n";
    }
    else
    {
        cout<<"Match over but we didn't get a winner!\n";
    }
    return *this;
}
int Player::num_steps;