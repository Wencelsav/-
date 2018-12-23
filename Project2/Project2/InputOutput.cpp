#include "InputOutput.h"
#include <iostream>
#include "board.h"
#include <windows.h>
#include <cmath>
#include <string>




auto InputOutput::CastState(State state)
{
	std::string result;
	switch (state)
	{
	case State::BLACK:
		result = "B";
		break;
	case State::WHITE:
		result = "W";
		break;
	default:
		result = " ";
		break;
	}
	return std::move( result);

}

InputOutput::InputOutput()
{
}

InputOutput::~InputOutput()
{
}

movePos InputOutput::GetMove() {
	//22 33
	movePos position;
	size_t p1, p2;

	std::cin >> p1;
	std::cin >> p2;

	position.first.first = p1 / 10;
	position.first.second = p1 - 10 * position.first.first;

	position.second.first = p2 / 10;
	position.second.second = p2 - 10 * position.second.first;

	return move(position);
}

void InputOutput::DrawBoard(const map&  board)
{
	
	auto boardSize = sqrt(board.size());
	for (size_t i = 0; i < boardSize; i++)
	{
		for (size_t j = 0; j < boardSize; j++)
		{
			 std::cout << CastState(board.at(pos(i, j)).GetState());
			 std::cout << "|";
		}
		std::cout << std::endl;
	}
	

}
