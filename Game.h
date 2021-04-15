#ifndef _GAME_
#define _GAME_
#include <string>
#include "Map.h"
#include "Player.h"
#include "AI_Player.h"

class Game {
public:
	Map xoxMap;
	Player user;
	AI_Player ai;
	bool is_Started;
	bool is_Finished;
	std::string winner;
public:
	Game();
	~Game();
	void Iterate();
	void Results();
	void Explain();
	void arrangeSymbols(std::string user_input);
	void playSymbolX();
	void playSymbolO();
	bool getFinish();
	bool checkFinish();
	bool checkUserFinish();
	bool checkAIFinish();
	bool isTie();
};

#endif