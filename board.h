#pragma once
#include "soldier.h"

#define ROWS 8
#define COLUMNS 8

class Soldier;

class Board
{
public:
	Board() {};
	Board(Board *other);
	~Board();
	std::string board_to_string() const;
	void string_to_board(const std::string board);
	void move(const std::string command, const int player);
	Soldier* _board[ROWS * COLUMNS];
private:
	int size() const;
};