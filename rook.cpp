#include "rook.h"

/// <summary>
/// This function checks if the rook piece can move from a source to a destination.
/// </summary>
/// <param name="board">The current state of the board.</param>
/// <param name="src">The source piece placement.</param>
/// <param name="dst">The destination piece placment.</param>
/// <returns>If the move of the piece is valid or not.</returns>
bool Rook::move(Board* board, std::string src, std::string dst)
{
	/*
	* +---+---+---+---+---+
	* |   |   |dst|   |   |
	* +---+---+---+---+---+
	* |   |   |dst|   |   |
	* +---+---+---+---+---+
	* |dst|dst|src|dst|dst|
	* +---+---+---+---+---+
	* |   |   |dst|   |   |
	* +---+---+---+---+---+
	* |   |   |dst|   |   |
	* +---+---+---+---+---+
	*/
	if (abs(src[0] - dst[0]) != 0 && abs(src[1] - dst[1]) != 0)
		return false; // The piece moves only left, right, up or down.
	return clear_middle(board, src, dst);
}

/// <summary>
/// This function checks if the path of the piece is clear of other pieces.
/// </summary>
/// <param name="board">The current state of the board.</param>
/// <param name="src">The source piece placement.</param>
/// <param name="dst">The destination piece placment.</param>
/// <returns>If the path is clear of other pieces.</returns>
bool Rook::clear_middle(Board* board, std::string src, std::string dst)
{
	int column = floor((src[0] + dst[0]) / 2); // Round down
	int row = floor((src[1] + dst[1]) / 2); // Round down
	std::string middle = std::string() + char(column) + char(row);
	if (middle == src || middle == dst)
		return true; // The middle piece is equal to one of the src or dst pieces.
	Soldier* middle_piece = board->string_to_piece(middle);
	if (middle_piece->to_string() != 'e')
		return false; // The middle piece is not empty.
	return clear_middle(board, src, middle) && clear_middle(board, middle, dst); // Continue the recursion.
}

/// <summary>
/// This function returns the character of the piece by it's color.
/// </summary>
/// <returns>Upper letter 'R' for black, Lower letter 'r' for white.</returns>
char Rook::to_string() const
{
	return this->_player == Color::white ? 'r' : 'R';
}
