#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include "Symbol.h"
#include "Map.h"

class Player {
public:

	/// @brief First map has showed to the user,
	/// Until valid input is given (user cannot select already filled locations) we loop
	/// We ask same question, and reply will be written to the map
	/// @param m is the map object which will be modified 
	void Play(Map& m);

	/// @brief Sets the symbol of the Player object
	/// @param s 
	void setSymbol(Symbol s);

	/// @brief Initial question is asked and the reply from the user is returned as a string
	/// @return user input as string 
	std::string askInitialQ();

	/// @brief While game is on, this same question is asked again and again until finish, and the reply from the user is returned as a string
	/// @return user input as string 
	std::string askplayingQ();

	/// @brief THIS METHOD HAVE NOT BEEN USED
	/// @return user input as string
	std::string askLastQ();

	/// @brief gets the symbol of Player object
	/// @return Symbol 
	Symbol getSymbol();

public:
	Symbol playerSymbol;
};
#endif
