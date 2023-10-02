#include "tic_tac_toe.cpp"
using namespace std;

int main()
{
    Board b;    // object creating of class board
    Player ob(b,'X');   // object creation of class player
    Player ob2 = ob; //  deep copy constructor
    ob.Play(b); // calls the play method that takes user input and starts the game
    ob.checkMatchOver();    // displays the use of this pointer
    return 0;  
}
