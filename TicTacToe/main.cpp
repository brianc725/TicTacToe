//
//  main.cpp
//  TicTacToe
//
//  Created by Brian Chan on 8/23/17.
//  Copyright © 2017 Brian Chan. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

const int MAXROWS = 3;
const int MAXCOLS = 3;

void initializeBoard(char (&board) [MAXROWS][MAXCOLS]);
void printBoard(char (&board) [MAXROWS][MAXCOLS]);
int checkWinner(char (&board) [MAXROWS][MAXCOLS]);
bool gameOver(char (&board) [MAXROWS][MAXCOLS]);
bool makeMove (char (&board) [MAXROWS][MAXCOLS], int choice, int player);

int main(int argc, const char * argv[]) {
    string player1;
    string player2;
    char board [MAXROWS][MAXCOLS];
    
    cout << "Welcome to Tic-Tac-Toe." << endl;
    cout << "Enter Player 1's Name: " << endl;
    getline(cin, player1);
    cout << "Enter Player 2's Name: " << endl;
    getline(cin, player2);
    
    initializeBoard(board);
    while(!gameOver(board)) //while there are spaces to still be placed
    {
        int p1Choice;
        int p2Choice;
        cout << endl;
        printBoard(board);
        cout << "Player 1's Turn (X). Enter your space." << endl;
        cin >> p1Choice;
        while (!makeMove(board, p1Choice, 1))
        {
            cout << "Invalid choice. Enter again." << endl;
            cin >> p1Choice;
        }
        
        if (checkWinner(board) == 1)
        {
            cout << endl;
            printBoard(board);
            cout << player1 + " won!" << endl;
            exit(0);
        }
        else if (checkWinner(board) == 2)
        {
            cout << endl;
            printBoard(board);
            cout << player2 + " won!" << endl;
            exit(0);
        }
        
        if (gameOver(board)) //check for a tie if game is over
        {
            if (checkWinner(board) == -1)
            {
                cout << endl;
                printBoard(board);
                cout << "It's a tie!" << endl;
                exit(0);
            }
        }
        
        cout << endl;
        printBoard(board);
        
        cout << "Player 2's Turn (O). Enter your space." << endl;
        cin >> p2Choice;
        while (!makeMove(board, p2Choice, 2))
        {
            cout << "Invalid choice. Enter again." << endl;
            cin >> p2Choice;
        }
        
        if (checkWinner(board) == 1)
        {
            cout << endl;
            printBoard(board);
            cout << player1 + " won!" << endl;
            exit(0);
        }
        else if (checkWinner(board) == 2)
        {
            cout << endl;
            printBoard(board);
            cout << player2 + " won!" << endl;
            exit(0);
        }

    }
    
    printBoard(board);
    if (checkWinner(board) == 1)
    {
        cout << player1 + " won!" << endl;
    }
    else if (checkWinner(board) == 2)
    {
        cout << player2 + " won!" << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }

}

void initializeBoard(char (&board) [MAXROWS][MAXCOLS])
{
    int counter = 1;
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            board[i][j] = counter+'0'; //need to add '0' to get the character number instead of int
            counter++;
        }
    }
}

void printBoard(char (&board) [MAXROWS][MAXCOLS])
{
    for (int i = 0; i < MAXROWS-1; i++)
    {
        for (int j = 0; j < MAXCOLS-1; j++)
        {
            cout << board[i][j] << "|";
        }
        cout << board[i][MAXCOLS-1]; //the last digit doesnt need |
        cout << endl << "-+-+-" << endl;
    }
    for (int i = MAXROWS-1; i < MAXROWS; i++)    //last row doesnt need the underline box
    {
        for (int j = 0; j < MAXCOLS-1; j++)
        {
            cout << board[i][j] << "|";
        }
        cout << board[i][MAXCOLS-1] << endl; //the last digit doesnt need |
    }
}

int checkWinner(char (&board) [MAXROWS][MAXCOLS])
{
    if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
    {
        return 1; //all the possiblities for player 1 winning
    }
    else if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') || (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
    {
        return 2; //all the possibilities for player 2 winning
    }
    else
    {
        return -1; //-1 if no winner
    }
}

bool gameOver(char (&board) [MAXROWS][MAXCOLS])
{
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            if (isnumber(board[i][j]))
            {
                return false;  //if there are any numbers left, board does not end
            }
        }
    }
    
    return true; //no numbers left so return game over
}

bool makeMove (char (&board) [MAXROWS][MAXCOLS], int choice, int player)
{
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            if (board[i][j] == (choice+'0'))
            {
                if (player == 1)
                {
                    board[i][j] = 'X';
                }
                else {
                    board[i][j] = 'O';
                }
                return true;  //if there are any numbers left, board does not end
            }
        }
    }
    return false;
}
