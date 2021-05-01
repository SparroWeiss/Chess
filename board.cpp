#include "board.h"
#include "bishop.h"
#include "empty.h"
#include "horseman.h"
#include "king.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"


std::string Board::board_to_string() const
{
	std::string board;
	for (int i = 0; i < size(); i++)
	{
		board += _board[i]->to_string();
	}
	return board;
}

void Board::string_to_board(const std::string board)
{
	if (board.size() != ROWS * COLUMNS)
	{
		throw std::exception("Board size must be 64 letters long.");
	}
	for (size_t i = 0; i < board.size(); i++)
	{
		char soldier = tolower(board[i]); // Lowerring the letter for the switch-case.  
		Color color = soldier == board[i] ? Color::white : Color::black; // Small letters: white, Big letters: black.
		switch (soldier)
		{
		case 'k':
			_board[i] = new King(color);
			break;
		case 'q':
			_board[i] = new Queen(color);
			break;
		case 'r':
			_board[i] = new Rook(color);
			break;
		case 'h':
			_board[i] = new Horseman(color);
			break;
		case 'b':
			_board[i] = new Bishop(color);
			break;
		case 'p':
			_board[i] = new Pawn(color);
			break;
		case 'e':
			_board[i] = new Empty();
			break;
		default:
			throw std::exception("The letters in the board must be one of these: 'k', 'q', 'r', 'h', 'b', 'p', 'e'.");
		}
	}
}

void Board::move(const std::string command, const int player)
{
	Soldier* src_piece = string_to_piece(command.substr(0, 2));
	Soldier* dst_piece = string_to_piece(command.substr(2, 2));
	if (src_piece->_player != player || src_piece->to_string() == 'e')
		// Source piece is not owned by the player.
		throw std::exception("You can't move this piece.");
	if (src_piece == dst_piece)
		// Same piece.
		throw std::exception("The source is the same as the destination.");
	if (dst_piece->_player == player && dst_piece->to_string() != 'e')
		// Destination piece is owned by the same player.
		throw std::exception("You can't move to this destination.");
	if (!src_piece->move(new Board(this), command.substr(0, 2), command.substr(2, 2)))
		// The specific piece can't move in this way.
		throw std::exception("Invalid move of the chosen piece.");

	// Success. Moving the pieces.
	delete dst_piece;
	_board[string_to_index(command.substr(2, 2))] = src_piece;
	_board[string_to_index(command.substr(0, 2))] = new Empty();
}

int Board::string_to_index(const std::string str)
{
	return (str[0] - 'a')/* place in row */ + ROWS * (COLUMNS - (str[1] - '0'))/* row */;
}

Soldier* Board::string_to_piece(const std::string str) const
{
	return _board[string_to_index(str)];
}

int Board::size() const
{
	int i = 0;
	while (true)
	{
		if (i == ROWS * COLUMNS) { break; }
		if (_board[i] == NULL) { break; }
		i++;
	}
	return i;
}

Board::Board(Board* other)
{
	this->string_to_board(other->board_to_string());
	_curr_player = other->_curr_player;
}

Board::~Board()
{
	for (size_t i = 0; i < size(); i++)
	{
		delete _board[i];
	}
}
