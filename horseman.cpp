#include "horseman.h"

/// <summary>
/// This function checks if the horseman piece can move from a source to a destination.
/// </summary>
/// <param name="board">The current state of the board.</param>
/// <param name="src">The source piece placement.</param>
/// <param name="dst">The destination piece placment.</param>
/// <returns>If the move of the piece is valid or not.</returns>
bool Horseman::move(Board* board, std::string src, std::string dst)
{
	/*
	* +---+---+---+---+---+
	* |   |dst|   |dst|   |
	* +---+---+---+---+---+
	* |dst|   |   |   |dst|
	* +---+---+---+---+---+
	* |   |   |src|   |   |
	* +---+---+---+---+---+
	* |dst|   |   |   |dst|
	* +---+---+---+---+---+
	* |   |dst|   |dst|   |
	* +---+---+---+---+---+
	*/
	return ((abs(src[0] - dst[0]) == 1 && abs(src[1] - dst[1]) == 2) ||
		(abs(src[0] - dst[0]) == 2 && abs(src[1] - dst[1]) == 1));
}

/// <summary>
/// This function returns the character of the piece by it's color.
/// </summary>
/// <returns>Upper letter 'H' for black, Lower letter 'h' for white.</returns>
char Horseman::to_string() const
{
	return this->_player == Color::white ? 'h' : 'H';
}
