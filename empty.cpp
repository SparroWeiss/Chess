#include "empty.h"

bool Empty::move(Board* board, std::string src, std::string dst)
{
	return false;
}

char Empty::to_string() const
{
	return 'e';
}
