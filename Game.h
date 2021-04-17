#ifndef _GAME_
#define _GAME_
#include <string>
#include "Map.h"
#include "Player.h"
#include "AI_Player.h"

/// @brief This class is responsible for everything related to the XOX game
class Game {
public:
	Map xoxMap;
	Player user;
	AI_Player ai;
	bool is_Started;
	bool is_Finished;
	std::string winner;
public:
	/// @brief Constructor of Game object
	Game();

	/// @brief Destructor of Game object
	~Game();

	/// @brief This method iterates the game
	/// if game has not started, initializes the symbols according to the given user inputs that is a reply to the first questions asked.
	/// If game is started, X symbol plays, then it checks whether the finishing conditions have met, if not O symbol plays, then we check finishing condition again in single iteration
	void Iterate();
	
	/// @brief Prints the result of the game.
	void Results();
	
	/// @brief Prints the explanation(How the game is played) of the game.
	void Explain();
	
	/// @brief Arranges symbols according to user_input (which is a reply to first question).
	/// @param user_input must be string that has the value "y" or "n"
	void arrangeSymbols(std::string user_input);
	
	/// @brief The player who has the symbol X plays
	void playSymbolX();
	
	/// @brief The player who has the symbol O plays
	void playSymbolO();
	
	/// @brief Returns the flag whether the game has ended or not
	/// @return is_Finished which is the flag that stands for game has finished or not.
	bool getFinish();

	/// @brief Checks whether any of the finishing conditions have met or not.
	/// @return true; if one of the conditions have met, false otherwise. 
	bool checkFinish();

	/// @brief Checks whether last move of the user has finished the game by winning
	/// @return true, if user have finished the game, false otherwise.
	bool checkUserFinish();

	/// @brief Checks whether last move of the AI has finished the game by winning
	/// @return true, if AI have finished the game, false otherwise.
	bool checkAIFinish();

	/// @brief Checks whether is there a space to make a move, if there is not any available moves, game is finished as tie.
	/// @return true, if game is tie, false otherwise.  
	bool isTie();
};

#endif