#ifndef BOARD_MIDDLEWARE
#define BOARD_MIDDLEWARE
#include <utility>

class Board
{
public:
    int board[3][3];
    Board();
    int evaluate_board();
    void make_move(int player_code, std::pair<int, int> coordinates);
    bool is_terminal_state();
    bool is_valid_board();
};
#endif