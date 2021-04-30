#pragma once
#include "soldier.h"

class Pawn : public Soldier
{
public:
	Pawn(Color color) : Soldier(color), _first_move(true) {};
	virtual bool move(Board* board, std::string src, std::string dst);
	virtual char to_string() const;
private:
	bool clear_way(Board* board, std::string src, std::string dst);
	bool right_direction(Board* board, std::string src, std::string dst);
	bool _first_move;
};