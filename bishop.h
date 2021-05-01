#pragma once
#include "soldier.h"

class Bishop : public Soldier
{
public:
	Bishop(Color color) { _player = color; };
	virtual bool move(Board* board, std::string src, std::string dst);
	virtual char to_string() const;
private:
	bool clear_middle(Board* board, std::string src, std::string dst);
};