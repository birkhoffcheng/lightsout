#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cassert>
#ifndef BOARD_H
#define BOARD_H

constexpr uint8_t BOARD_SIZE_LIMIT = 64;

class Board {
public:
	uint64_t board;
	uint64_t solution;
	uint8_t width;
	uint8_t height;

	Board();
	Board(uint64_t board_in, uint8_t width_in, uint8_t height_in);
	bool operator==(Board &rhs);
	bool get_bit(uint8_t index);
	void flip(uint8_t index);
	void press_button(uint8_t bit_index);
	bool solve();
	void reset();
};

#endif
