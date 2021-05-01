#include "king.h"

/// <summary>
/// This function checks if the king piece can move from a source to a destination.
/// </summary>
/// <param name="board">The current state of the board.</param>
/// <param name="src">The source piece placement.</param>
/// <param name="dst">The destination piece placment.</param>
/// <returns>If the move of the piece is valid or not.</returns>
bool King::move(Board* board, std::string src, std::string dst)
{
	/*
	* +---+---+---+
	* |dst|dst|dst|
	* +---+---+---+
	* |dst|src|dst|
	* +---+---+---+
	* |dst|dst|dst|
	* +---+---+---+
	*/
	return ((abs(src[0]-dst[0]) == 1 || abs(src[0]-dst[0])==0) &&
		(abs(src[1] - dst[1]) == 1 || abs(src[1] - dst[1]) == 0));
}

/// <summary>
/// This function returns the character of the piece by it's color.
/// </summary>
/// <returns>Upper letter 'K' for black, Lower letter 'k' for white.</returns>
char King::to_string() const
{
	return this->_player == Color::white ? 'k' : 'K';
}
