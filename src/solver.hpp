#include "board.hpp"

bool brute_force_search(board_t board, uint8_t width, uint8_t height, board_t *solution);

bool breadth_first_search(board_t board, uint8_t width, uint8_t height, board_t *solution);

bool depth_first_search(board_t board, uint8_t width, uint8_t height, board_t *solution);
