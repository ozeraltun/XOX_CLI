#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include "Symbol.h"
#include "Map.h"

class Player {
public:
	void Play(Map& m);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="s"></param>
	void setSymbol(Symbol s);
	Symbol getSymbol();
	std::string askInitialQ();
	std::string askplayingQ();
	std::string askLastQ();
public:
	Symbol playerSymbol;
};
#endif
