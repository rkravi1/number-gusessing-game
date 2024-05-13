#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;

vector<vector<char>> board(SIZE, vector<char>(SIZE, '-'));

void displayBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void updateBoard(int row, int col, char player)
{
    board[row][col] = player;
}

bool checkForWin(char player)
{
    // Check rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }
    return false;
}

bool checkForDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char currentPlayer = 'X';
    int row, col;

    while (true)
    {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (board[row][col] != '-')
        {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        updateBoard(row, col, currentPlayer);

        if (checkForWin(currentPlayer))
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkForDraw())
        {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Play again? (y/n): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'y')
    {
        main();
    }

    return 0;
}