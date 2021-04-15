#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include "Symbol.h"
#include "Map.h"

class Player {
public:
	void Play(Map& m);
	void setSymbol(Symbol s);
	std::string askInitialQ();
	std::string askplayingQ();
	std::string askLastQ();
	Symbol getSymbol();
public:
	Symbol playerSymbol;
};
#endif
