#pragma once
#include "soldier.h"

class Queen : public Soldier
{
public:
	Queen(Color color) : Soldier(color) {};
	virtual bool move(Board* board, std::string src, std::string dst);
	virtual char to_string() const;
};