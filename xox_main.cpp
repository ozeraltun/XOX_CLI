#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "Player.h"
#include "AI_Player.h"
#include "Symbol.h"
#include "Game.h"

int main()
{
	/*
	* TODO:
	* -Improve AI
	*/
	Game game;
	while (!game.checkFinish()) {
		game.Iterate();
	}
	game.Results();
	std::cin.get();
	return 0;
}