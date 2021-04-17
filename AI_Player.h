#ifndef _AIPLAYER_
#define _AIPLAYER_
#include "Symbol.h"
#include "Map.h"

/// @brief Artificial intelligence(it is not very intelligent) class that plays XOX.
/// 
/// This object plays XOX when symbol is set, and (xox)Map object is supplied.
class AI_Player {
public:
	/// @brief When Map object is supplied, randomly selects a move and changes map object accordingly. 
	/// @brief AI randomly selects from the valid spaces (not filled areas) of Map object
	/// 
	/// @param m is a Map object which is passed as a reference
	void MakeRandomMove(Map& m);
	
	/// /// @brief Set method for the symbol of AI Player
	/// 
	/// @param s is a Symbol class
	void setSymbol(Symbol s);

	/// @brief Get method for the symbol of AI Player
	/// @returns Symbol
	Symbol getSymbol();
public:
	Symbol ai_Symbol;
};
#endif

