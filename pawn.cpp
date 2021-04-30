#include "pawn.h"


bool Pawn::move(Board* board, std::string src, std::string dst)
{
	return false;
}

char Pawn::to_string() const
{
	return this->_player == Color::white ? 'p' : 'P';
}
