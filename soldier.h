#pragma once
#include <iostream>
#include "board.h"

class Board;

enum Color
{
	black = 0, white
};


class Soldier
{
public:
	Soldier() { _player = Color::black; };
	Soldier(Color color) { _player = color;	};
	virtual bool move(Board* board, std::string src, std::string dst) = 0;
	virtual char to_string() const = 0;
	Color _player;
};