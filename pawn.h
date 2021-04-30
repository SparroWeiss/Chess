#pragma once
#include "soldier.h"

class Pawn : public Soldier
{
public:
	Pawn(Color color) : Soldier(color) {};
	virtual bool move(Board* board, std::string src, std::string dst);
	virtual char to_string() const;
};