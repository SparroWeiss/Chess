#include <iostream>
#include "game.h"

/****
* Initial UML:
* -----------
*                                              +-------------------------+
*                                              |                         |
* +----------------+          +------------+   |     +-------------+     |
* |______Game______|          |____Board___|   |     |____Player___|     |
* | - Board        | <--------| - array    |<--+ +---| - black     |     |
* | - curr_player  | <-+      | + move()   |     |   +-------------+     |
* | + move()       |   |      +------------+     |                       |
* +----------------+   +-------------------------+                    +-----------+
*                                                                     |__Soldier__|
*                                                                     | - player  |
*                                                                     | + move()  |
*                                                                     +-----------+
* 
****/


void main()
{
	Game game = Game();
	try
	{
		while (true)
		{
			game.move();
		}
	}
	catch (const std::exception& msg)
	{
		std::cout << msg.what();
	}
}