#pragma once
#include "soldier.h"

class King : public Soldier
{
public:
	King(Color color) : Soldier(color) {};
	virtual bool move(Board* board, std::string src, std::string dst);
	virtual char to_string() const;
};