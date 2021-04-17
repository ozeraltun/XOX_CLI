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

Game::Game() {
	is_Started = false;
	is_Finished = false;
	winner = "nobody";
}
Game::~Game() {
}
bool Game::getFinish() {
	return is_Finished;
}
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
bool Game::isTie() {
	if (!xoxMap.hasEmpty()) {
		is_Finished = true;
		is_Started = false;
		winner = "nobody";
		return true;
	}
	else { return false; }
}
bool Game::checkFinish() {
	if (checkAIFinish())
		return true;
	else if (checkUserFinish())
		return true;
	else if (isTie())
		return true;
	else { return false; }
}
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
bool Game::checkAIFinish() {
	is_Finished = xoxMap.checkFin(ai.getSymbol()); 
	if (is_Finished == true) {
		winner = "ai";
		xoxMap.Show();
		return true;
	}
	else { return false; }
}
bool Game::checkUserFinish() {
	is_Finished = xoxMap.checkFin(user.getSymbol()); 
	if (is_Finished == true) {
		winner = "user";
		xoxMap.Show();
		return true;
	}
	else { return false; }
}
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
void Game::Results() {
	if (winner == "user")
		std::cout << "You WON!" << std::endl;
	else if (winner == "ai")
		std::cout << "You LOST!" << std::endl;
	else
		std::cout << "It is a TIE!" << std::endl;
}
void Game::Explain() {
	std::cout << "This is a XOX game..." << std::endl;
	std::cout << "In order to reply questions enter y or n then press enter.." << std::endl;
	std::cout << "In order to select locations use the table below: " << std::endl;
	std::cout << "0|1|2" << std::endl;
	std::cout << "3|4|5" << std::endl;
	std::cout << "6|7|8" << std::endl << std::endl;
}

