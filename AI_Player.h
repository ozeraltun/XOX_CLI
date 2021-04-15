#ifndef _AIPLAYER_
#define _AIPLAYER_
#include "Symbol.h"
#include "Map.h"

class AI_Player {
public:
	void MakeRandomMove(Map& m);
	void setSymbol(Symbol s);
	Symbol getSymbol();
public:
	Symbol ai_Symbol;
};
#endif

