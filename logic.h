#ifndef LOGIC
#define LOGIC

#include <utility>
#include "board_middleware.h"

int minimax(Board &board_, int player_code);

std::pair<int, int> get_best_move(Board &board_, int player_code);

#endif