#pragma once
#include "soldier.h"

#define ROWS 8
#define COLUMNS 8

class Soldier;
enum Color;

class Board
{
public:
	Board() {};
	Board(Board *other);
	~Board();
	std::string board_to_string() const;
	void string_to_board(const std::string board);
	void move(const std::string command, const int player);
	static int string_to_index(const std::string str);
	Soldier* string_to_piece(const std::string str) const;
	Soldier* _board[ROWS * COLUMNS];
	Color* _curr_player;
private:
	int size() const;
};