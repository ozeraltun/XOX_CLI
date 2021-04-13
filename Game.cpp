#include "Game.h"
#include <string>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "AI_Player.h"

Map xoxMap;
Player user;
AI_Player ai;
bool is_Started;
bool is_Finished;
std::string winner;

Game::Game() {
	is_Started = false;
	is_Finished = false;
	winner = "nobody";
}

Game::~Game() {
}

bool Game::checkFinish() {
	return is_Finished;
}

void Game::Iterate() {
	std::string answer = "";
	if (is_Started) {
		bool error = ai.MakeRandomMove(xoxMap);
		is_Finished = xoxMap.checkFin();
		if (is_Finished == true) {
			winner = "ai";
			xoxMap.Show();
			return;
		}
		else {
			if (error) {
				//Finish the game since no available moves!
				is_Finished = true;
				is_Started = false;
				return;
			}
		}
		/*
		* if user dont have available moves
		*/
		if (!xoxMap.hasEmpty()) {
			is_Finished = true;
			xoxMap.Show();
			return;
		}
		user.Play(xoxMap);
	}
	else {
		is_Started = true;
		answer = user.askInitialQ();
		if (answer == "y") {
			user.setSymbol(Symbol::symbol_X);
			ai.setSymbol(Symbol::symbol_O);
			std::cout << std::endl;
			user.Play(xoxMap);
		}
		else if (answer == "n") {
			user.setSymbol(Symbol::symbol_O);
			ai.setSymbol(Symbol::symbol_X);
		}
		else { std::cout << "ERROR at initial Question"; }
	}
	
	is_Finished = xoxMap.checkFin();
	if (is_Finished == true) {
		winner = "user";
		xoxMap.Show();
	}

	std::cout << " " << std::endl;
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

