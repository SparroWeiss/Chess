#include "king.h"

bool King::move(Board* board, std::string src, std::string dst)
{
	return false;
}

char King::to_string() const
{
	return this->_player == Color::white ? 'k' : 'K';
}
