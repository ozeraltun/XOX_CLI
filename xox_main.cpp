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
	* -Ask to Restart game, restart if given "y" 
	*/
	Game game;
	game.Explain();
	while (!game.getFinish()) {
		game.Iterate();
	}
	game.Results();
	std::cin.get();
	return 0;
}