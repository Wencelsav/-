#pragma once
#include <utility>
#include "Cell.h"
#include <map>

using movePos = std::pair <pos, pos>;
using map = std::map<pos, Cell>;

class InputOutput
{
	static  auto CastState(State state);
public:
	InputOutput();
	~InputOutput();
	static movePos GetMove();
	static void DrawBoard(const map& board);
};

