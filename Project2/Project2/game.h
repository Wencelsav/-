#pragma once
#include "board.h"
#include "InputOutput.h"
enum class Player { NONE, BLACK, WHITE };
class game
{
	board mBoard;
	InputOutput	mIO;
	size_t mBlackScore;
	size_t mWhiteScore;
	Player mLastplayer;
	movePos MakeIO();
	void SwitchPlayer();
	void UpdateScore();
	bool GetDirection()const;
	bool bIsSurrounded;
public:
	game();
	~game();
	Player GetWinner();
	void Start();
};

