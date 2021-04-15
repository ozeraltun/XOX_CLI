#include "Game.h"
#include <string>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "AI_Player.h"

bool is_Started;
bool is_Finished;
std::string winner;
Map xoxMap;
Player user;
AI_Player ai;

/// <summary>
/// Game object initialization
/// Game has not started 
/// Game has not finished 
/// and nobody has won
/// </summary>
Game::Game() {
	is_Started = false;
	is_Finished = false;
	winner = "nobody";
}
/// <summary>
/// Destruction is empty since heap memory have not used
/// </summary>
Game::~Game() {
}
/// <summary>
/// Returns the flag whether the game has ended or not
/// </summary>
/// <returns></returns>
bool Game::getFinish() {
	return is_Finished;
}
/// <summary>
/// This method iterates the game
/// if game have not started, initializes the symbols according to the given reply to the initial question
/// If game is started, X symbol plays, then it checks whether the finishing conditions have met, if not O symbol plays, then we check finishing condition again in single iteration
/// </summary>
void Game::Iterate() {
	std::string user_input = "";
	if (!is_Started) {
		is_Started = true;
		user_input = user.askInitialQ();
		arrangeSymbols(user_input);
	}
	else {
		playSymbolX();
		if (checkFinish()) { return; }
		playSymbolO();
		if (checkFinish()) { return; }
		std::cout << " " << std::endl;
	}
}	
/// <summary>
/// returns true if it is a tie.
/// </summary>
/// <returns></returns>
bool Game::isTie() {
	if (!xoxMap.hasEmpty()) {
		is_Finished = true;
		is_Started = false;
		winner = "nobody";
		return true;
	}
	else { return false; }
}
/// <summary>
/// This method checks every finishing condition
/// </summary>
/// <returns></returns>
bool Game::checkFinish() {
	if (checkAIFinish())
		return true;
	else if (checkUserFinish())
		return true;
	else if (isTie())
		return true;
	else { return false; }
}
/// <summary>
/// The player who has the symbol O plays in this method
/// </summary>
void Game::playSymbolO() {
	if (user.getSymbol() == Symbol::symbol_O) {
		//user plays O
		user.Play(xoxMap);
	}
	else {
		//ai plays O
		ai.MakeRandomMove(xoxMap);
	}
}
/// <summary>
/// The player who has the symbol X plays in this method
/// </summary>
void Game::playSymbolX() {
	if (user.getSymbol() == Symbol::symbol_X) {
		//user plays X
		user.Play(xoxMap);
	}
	else {
		//ai plays X
		ai.MakeRandomMove(xoxMap);
	}
}
/// <summary>
/// Checks whether last move of the AI has finished the game
/// </summary>
bool Game::checkAIFinish() {
	is_Finished = xoxMap.checkFin(ai.getSymbol()); 
	if (is_Finished == true) {
		winner = "ai";
		xoxMap.Show();
		return true;
	}
	else { return false; }
}
/// <summary>
/// Checks whether last move of the user has finished the game
/// </summary>
bool Game::checkUserFinish() {
	is_Finished = xoxMap.checkFin(user.getSymbol()); 
	if (is_Finished == true) {
		winner = "user";
		xoxMap.Show();
		return true;
	}
	else { return false; }
}
/// <summary>
/// Arranges symbols according to given user_input to the first question.
/// </summary>
/// <param name="user_input"></param>
void Game::arrangeSymbols(std::string user_input) {
	if (user_input == "y") {
		user.setSymbol(Symbol::symbol_X);
		ai.setSymbol(Symbol::symbol_O);
		std::cout << std::endl;
	}
	else if(user_input == "n"){
		user.setSymbol(Symbol::symbol_O);
		ai.setSymbol(Symbol::symbol_X);
	}
	else { std::cout << "ERROR at initial Question"; }
}
/// <summary>
/// Prints the results of the game.
/// </summary>
void Game::Results() {
	if (winner == "user")
		std::cout << "You WON!" << std::endl;
	else if (winner == "ai")
		std::cout << "You LOST!" << std::endl;
	else
		std::cout << "It is a TIE!" << std::endl;
}
/// <summary>
/// Prints the explanation of the game.
/// </summary>
void Game::Explain() {
	std::cout << "This is a XOX game..." << std::endl;
	std::cout << "In order to reply questions enter y or n then press enter.." << std::endl;
	std::cout << "In order to select locations use the table below: " << std::endl;
	std::cout << "0|1|2" << std::endl;
	std::cout << "3|4|5" << std::endl;
	std::cout << "6|7|8" << std::endl << std::endl;
}

