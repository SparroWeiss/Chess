#pragma once
#include "soldier.h"
#include "board.h"

class Board;

class Rook : public Soldier
{
public:
	Rook() { _player = Color::black; };
	Rook(Color color) { _player = color; };
	virtual bool move(Board* board, std::string src, std::string dst);
	virtual char to_string() const;
};