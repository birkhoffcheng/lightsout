#include "solver.hpp"

board_t press_button(board_t board, uint8_t bit_index, uint8_t width, uint8_t height) {
	board = board_flip(board, bit_index);
	uint8_t row = bit_index / width;
	uint8_t col = bit_index % width;
	if (row != 0)
		board = board_flip(board, bit_index - width);
	if (row != height - 1)
		board = board_flip(board, bit_index + width);
	if (col != 0)
		board = board_flip(board, bit_index - 1);
	if (col != width - 1)
		board = board_flip(board, bit_index + 1);
	return board;
}

bool brute_force_search(board_t board, uint8_t width, uint8_t height, board_t *sol) {
	#ifdef DEBUG
	assert(width * height <= BOARD_SIZE_LIMIT);
	#endif
	board_t board_copy = board;
	board_t solution;
	for (solution = 0; solution < 2 << (width * height); ++solution) {
		board = board_copy;
		for (int i = 0; i < width * height; ++i) {
			if (board_get_bit(solution, i)) {
				board = press_button(board, i, width, height);
			}
		}

		if (board == board_new()) {
			if (sol) {
				*sol = solution;
			}

			return true;
		}
	}

	return false;
}
