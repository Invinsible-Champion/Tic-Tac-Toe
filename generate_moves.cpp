#include <bits/stdc++.h>

#include "board_middleware.h"
using namespace std;

int minimax(Board &board_, int player_code)
{
    if (board_.is_terminal_state())
    {
        return board_.evaluate_board();
    }
    int best_score = (player_code == 1) ? (-100) : 100;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board_.board[i][j] != 0 && board_.board[i][j] != 1)
            {
                board_.board[i][j] = player_code;

                int current_score = minimax(board_, (player_code == 1) ? (0) : 1);
                if (player_code == 1)
                {
                    if (current_score > best_score)
                    {
                        best_score = current_score;
                    }
                }
                else
                {
                    if (current_score < best_score)
                    {
                        best_score = current_score;
                    }
                }

                board_.board[i][j] = -10;
            }
        }
    }
    return best_score;
}

pair<int, int> get_best_move(Board &board_, int player_code)
{
    pair<int, int> best_move{-1, -1};
    int best_score = (player_code == 1) ? (-100) : 100;
    if (!board_.is_terminal_state())
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board_.board[i][j] != 0 && board_.board[i][j] != 1)
                {
                    board_.board[i][j] = player_code;

                    int current_score = minimax(board_, (player_code == 1) ? (0) : 1);
                    if (player_code == 1)
                    {
                        if (current_score > best_score)
                        {
                            best_move = {i, j};
                            best_score = current_score;
                        }
                    }
                    else
                    {
                        if (current_score < best_score)
                        {
                            best_move = {i, j};
                            best_score = current_score;
                        }
                    }

                    board_.board[i][j] = -10;
                }
            }
        }
    }

    return best_move;
}