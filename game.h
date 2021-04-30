#pragma once
#include "board.h"

#define BOARD "rhbqkbhrppppppppeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeePPPPPPPPRHBQKBHR"
#define ROW_SEQ "     a   b   c   d   e   f   g   h\n"
#define ROW_SEPERATOR "   +---+---+---+---+---+---+---+---+\n"
#define COLUMN_SEPERATOR " | "


class Game
{
public:
	Game();
	~Game();
	void print_board() const;
	void move();
private:
	Board* _board;
	Color _curr_player;
};