#include "queen.h"

bool Queen::move(Board* board, std::string src, std::string dst)
{
	return false;
}

char Queen::to_string() const
{
	return this->_player == Color::white ? 'q' : 'Q';
}
