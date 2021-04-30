#include "game.h"

Game::Game()
{
	_board = new Board();
	_board->string_to_board(BOARD);
	_curr_player = Color::black;
}

Game::~Game()
{
	delete _board;
}

void Game::print_board() const
{
	std::string board = _board->board_to_string();
	char start = '8';
	std::cout << ROW_SEQ << ROW_SEPERATOR << " " << start << COLUMN_SEPERATOR;
	for (size_t i = 0; i < board.size(); i++)
	{
		if (i % ROWS == 0 && i != 0) 
		{
			std::cout << start << "\n" << ROW_SEPERATOR;
			start -= 1;
			std::cout << " " << start << COLUMN_SEPERATOR;
		}
		std::cout << board[i] << COLUMN_SEPERATOR;
	}
	std::cout << start << "\n" << ROW_SEPERATOR << ROW_SEQ;
}

void Game::move()
{
	system("CLS");
	print_board();
	std::cout << "Current player: " << (_curr_player == Color::black ? "Upper letters" : "Lower letters") << "\nEnter command: ";
	std::string command;
	while (true)
	{
		std::cin >> command;
		if (command.size() == 4)
		{
			if ((command[0] >= 'a' && command[0] <= 'h') &&
				(command[2] >= 'a' && command[2] <= 'h') &&
				(command[1] >= '1' && command[1] <= '8') &&
				(command[3] >= '1' && command[3] <= '8'))
			{ // Command in the valid range.
				try
				{
					_board->move(command, static_cast<int>(_curr_player));
				}
				catch (const std::exception& msg)
				{ // Problem with the command.
					std::cout << msg.what() << " try again: "; // Print problem.
					continue;
				}
				break;
			}
			else
			{
				std::cout << "Command out of range of the board or not in the format 'a1b2'.";
			}
		}
		else
		{
			std::cout << "Command must be 4 charecters long.";
		}
		std::cout << " try again: ";
	}
	// Switching players.
	_curr_player = _curr_player == Color::black ? Color::white : Color::black;
}
