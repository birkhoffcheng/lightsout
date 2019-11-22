#include "board.hpp"

board_t board_new() {
	return 0;
}

bool board_get_bit(board_t board, uint8_t index) {
	#ifdef DEBUG
	assert(index < BOARD_SIZE_LIMIT);
	#endif
	board >>= index;
	return board & 1 == 1;
}

bool board_equal(board_t a, board_t b) {
	return a == b;
}

board_t board_flip(board_t board, uint8_t index) {
	#ifdef DEBUG
	assert(index < BOARD_SIZE_LIMIT);
	#endif
	board_t mask = 1 << index;
	return board ^ mask;
}
