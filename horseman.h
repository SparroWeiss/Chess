#pragma once
#include "soldier.h"
#include "board.h"

class Horseman : public Soldier
{
public:
	Horseman() { _player = Color::black; };
	Horseman(Color color) { this->_player = color; };
	virtual bool move(Board* board, std::string src, std::string dst);
	virtual char to_string() const;
};