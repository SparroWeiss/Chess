#include "queen.h"
#include "rook.h"
#include "bishop.h"

/// <summary>
/// This function checks if the queen piece can move from a source to a destination.
/// </summary>
/// <param name="board">The current state of the board.</param>
/// <param name="src">The source piece placement.</param>
/// <param name="dst">The destination piece placment.</param>
/// <returns>If the move of the piece is valid or not.</returns>
bool Queen::move(Board* board, std::string src, std::string dst)
{
	/*
	* +---+---+---+---+---+
	* |dst|   |dst|   |dst|
	* +---+---+---+---+---+
	* |   |dst|dst|dst|   |
	* +---+---+---+---+---+
	* |dst|dst|src|dst|dst|
	* +---+---+---+---+---+
	* |   |dst|dst|dst|   |
	* +---+---+---+---+---+
	* |dst|   |dst|   |dst|
	* +---+---+---+---+---+
	*/
	Color player = board->string_to_piece(src)->_player;
	return Rook(player).move(board, src, dst) || Bishop(player).move(board, src, dst); // Queen moves like a Bishop or like a Rook.
}

/// <summary>
/// This function returns the character of the piece by it's color.
/// </summary>
/// <returns>Upper letter 'Q' for black, Lower letter 'q' for white.</returns>
char Queen::to_string() const
{
	return this->_player == Color::white ? 'q' : 'Q';
}
