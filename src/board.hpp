#include <cstdint>
#include <cstdlib>
#include <cassert>
#ifndef BOARD_H
#define BOARD_H

typedef uint64_t board_t;
constexpr uint8_t BOARD_SIZE_LIMIT = 64;

board_t board_new();

bool board_get_bit(board_t board, uint8_t index);

bool board_equal(board_t a, board_t b);

board_t board_flip(board_t board, uint8_t index);

#endif
