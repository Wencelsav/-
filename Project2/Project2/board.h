#pragma once
#include "Cell.h"
#include <map>
using map = std::map<pos, Cell>;

class board
{
	const size_t mBoardSize = 8;
	map mCells;
public:
	enum class MoveResult { SECCESSFUL_MOVE, SECCESSFUL_COMBAT, PROHIBITED };
	board();
	~board();
	void ResetMap();
	MoveResult CheckMove(const pos &startPos, const pos &endPos, bool direction);
	MoveResult MakeMove(const pos &startPos, const pos &endPos, bool direction);
	const map& GetMap() const { return mCells; }
};
