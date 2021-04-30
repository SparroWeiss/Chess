#pragma once
#include "soldier.h"
#include "board.h"


class Empty : public Soldier
{
public:
	Empty() { _player = Color::black; };
	virtual bool move(Board* board, std::string src, std::string dst);
	virtual char to_string() const;
};