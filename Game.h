#ifndef _GAME_
#define _GAME_

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
	bool checkFinish();
	void Iterate();
	void Results();
};

#endif