#include "horseman.h"

bool Horseman::move(Board* board, std::string src, std::string dst)
{
	return false;
}

char Horseman::to_string() const
{
	return this->_player == Color::white ? 'h' : 'H';
}
