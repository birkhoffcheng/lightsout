#include "board.hpp"

Board::Board() {
	board = 0;
	width = 5;
	height = 5;
}

Board::Board(uint64_t board_in, uint8_t width_in, uint8_t height_in) {
	board = board_in;
	width = width_in;
	height = height_in;
	assert(height < BOARD_SIZE_LIMIT / width);
}

bool Board::operator==(Board &rhs) {
	return board == rhs.board;
}

bool Board::get_bit(uint8_t index) {
	#ifdef DEBUG
	assert(index < BOARD_SIZE_LIMIT);
	#endif
	uint64_t board_copy = board;
	board_copy >>= index;
	return board_copy & 1 == 1;
}

void Board::flip(uint8_t index) {
	#ifdef DEBUG
	assert(index < BOARD_SIZE_LIMIT);
	#endif
	uint64_t mask = 1 << index;
	board ^= mask;
}

void Board::press_button(uint8_t bit_index) {
	flip(bit_index);
	uint8_t row = bit_index / width;
	uint8_t col = bit_index % width;
	if (row != 0)
		flip(bit_index - width);
	if (row != height - 1)
		flip(bit_index + width);
	if (col != 0)
		flip(bit_index - 1);
	if (col != width - 1)
		flip(bit_index + 1);
}

bool Board::solve() {
	uint64_t board_copy = board;
	for (solution = 0; solution < 2 << (width * height); ++solution) {
		board = board_copy;
		for (int i = 0; i < width * height; ++i) {
			if (get_bit(i)) {
				press_button(i);
			}
		}

		if (board == 0) {
			board = board_copy;
			return true;
		}
	}

	board = board_copy;
	return false;
}
