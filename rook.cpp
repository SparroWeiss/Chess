#include "rook.h"

bool Rook::move(Board* board, std::string src, std::string dst)
{
	return false;
}

char Rook::to_string() const
{
	return this->_player == Color::white ? 'r' : 'R';
}
