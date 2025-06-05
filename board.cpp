/*
    Contains Board Functions and Wrapper Classes
    X-> 1
    O -> 0
    Board is a 3*3 integer matrix
*/

#include "board_middleware.h"
#include <bits/stdc++.h>
using namespace std;

Board::Board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = -10;
        }
    }
}

int Board::evaluate_board()
{
    // 0-> no result/draw
    //  10-> Win for 1
    //  -10-> win for 0

    // Possible wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != -10)
    {
        if (board[0][0] == 1)
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != -10)
    {
        if (board[0][2] == 1)
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] != -10)
    {
        if (board[0][0] == 1)
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] != -10)
    {
        if (board[1][0] == 1)
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != -10)
    {
        if (board[2][0] == 1)
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] != -10)
    {
        if (board[0][0] == 1)
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] != -10)
    {
        if (board[0][1] == 1)
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] != -10)
    {
        if (board[0][2] == 1)
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else
    {
        return 0;
    }
}

// Make move implementation - coordinates must be 0 indexed
void Board::make_move(int player_code, pair<int, int> coordinates)
{
    board[coordinates.first][coordinates.second] = player_code;
}
bool Board::is_valid_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0 || board[i][j] == 1 || board[i][j] == -10)
            {
                continue;
            }
            else
                return false;
        }
    }
    return true;
}
bool Board::is_terminal_state()
{
    int current_score = evaluate_board();
    if (abs(current_score) == 10)
    {
        return true;
    }
    else
    {
        int count = 0;
        bool is_full;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 0 || board[i][j] == 1)
                {
                    count++;
                }
            }
        }
        if (count == 9)
            is_full = true;
        else
            is_full = false;
        return is_full;
    }
}