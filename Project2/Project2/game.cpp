#include "game.h"
#include <iostream>
using namespace std;


movePos game::MakeIO()
{
	//print board
	system("cls");
	auto map = mBoard.GetMap();
	mIO.DrawBoard(map);

	//ask move
	auto newmove = mIO.GetMove();
	return move(newmove);
}

void game::SwitchPlayer()
{ 
	if (mLastplayer == Player::WHITE) {
		mLastplayer = Player::BLACK;
	}
	else
	{
		mLastplayer = Player::WHITE;
	}
}

void game::UpdateScore()
{
	if (mLastplayer == Player::BLACK) {
		mBlackScore++;
	}
	else if (mLastplayer == Player::WHITE)
	{
		mWhiteScore++;
	}
}

bool game::GetDirection() const
{
	bool direction;
	switch (mLastplayer) {
	case Player::WHITE:
		direction = false;
		break;
	case Player::BLACK:
		direction = true;
		break;

	}
	return move(direction);
}

game::game():mLastplayer(Player::NONE),mWhiteScore(0),mBlackScore(0),bIsSurrounded(false)
{
}


game::~game()
{
}

Player game::GetWinner()
{
	Player winner(Player::NONE);
	if (bIsSurrounded) {
		if (mLastplayer == Player::WHITE) {
			winner = Player::BLACK;
		}
		else
		{
			winner = Player::WHITE;
		}

	}
	else {

		if (mWhiteScore == 12) {
			winner = Player::WHITE;
		}
		else
			if (mBlackScore == 12) {
				winner = Player::BLACK;
			}
	}
	return winner;
}

void game::Start()
{
	mBoard.ResetMap();
	//check is game is over

	while (GetWinner() == Player::NONE) 
	{
		board::MoveResult moveResult(board::MoveResult::PROHIBITED);
		while (moveResult == board::MoveResult::PROHIBITED) {
			// IOStuff
			auto newmove = MakeIO();
			bool direction = GetDirection();
			moveResult = mBoard.MakeMove(newmove.first, newmove.second, direction);
		}
		//parse move result
		if (moveResult==board::MoveResult::SECCESSFUL_MOVE) {
			UpdateScore();
		}
		SwitchPlayer();
		//make move
	}
}
