#include "pawn.h"

/// <summary>
/// This function checks if the pawn piece can move from a source to a destination.
/// </summary>
/// <param name="board">The current state of the board.</param>
/// <param name="src">The source piece placement.</param>
/// <param name="dst">The destination piece placment.</param>
/// <returns>If the move of the piece is valid or not.</returns>
bool Pawn::move(Board* board, std::string src, std::string dst)
{
	Soldier* src_piece = board->_board[Board::string_to_index(src)];
	Soldier* dst_piece = board->_board[Board::string_to_index(dst)];
	if (src[0] == dst[0])
	{ /* Going in straight line */
		if (dst_piece->to_string() != 'e')
			return false; // The dst piece must be empty.
		if (abs(src[1] - dst[1]) == 2)
		{ /* Going two steps forward */
			if (!_first_move)
				return false; // Can move two step only on first move.
			std::string middle = std::string() + char(src[0]) + char((src[1] + dst[1]) / 2); // The middle piece of the path.
			Soldier* middle_piece = board->_board[Board::string_to_index(middle)];
			if (middle_piece->to_string() != 'e')
				return false; // The middle piece must be empty.
		}
		else if (abs(src[1] - dst[1]) > 2)
			return false; // Too many steps for a pawn.
	}
	else
	{ /* Not going in straight line */
		if (abs(src[1] - dst[1]) != 1)
			return false; // Can move sideway only one step.
		if (dst_piece->_player == *(board->_curr_player) || dst_piece->to_string() == 'e')
			return false; // Can move sideway only if dst piece is the enemy.
	}
	/* The path of the piece is valid, the only thing left is to check the direction by color */
	switch (src_piece->_player)
	{
	case Color::black:
		if (src[1] > dst[1])
			return false; // Black goes from smaller to bigger (a2a3 for example).
		break;
	case Color::white:
		if (src[1] < dst[1])
			return false; // White goes from bigger to smaller (a7a6 for example).
		break;
	default:
		break;
	}
	/* The move is valid */
	_first_move = false; // Made the first move.
	return true;
}

/// <summary>
/// This function returns the character of the piece by it's color.
/// </summary>
/// <returns>Upper letter 'P' for black, Lower letter 'p' for white.</returns>
char Pawn::to_string() const
{
	return this->_player == Color::white ? 'p' : 'P';
}