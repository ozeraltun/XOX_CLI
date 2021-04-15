#include "Player.h"
#include <string>
#include <iostream>
#include "Symbol.h"
#include "Map.h"

Symbol playerSymbol;

/// <summary>
/// Sets the symbol of the player
/// </summary>
/// <param name="s"></param>
void Player::setSymbol(Symbol s) {
	playerSymbol = s;
}
/// <summary>
/// returns the symbol of the player
/// </summary>
/// <returns></returns>
Symbol Player::getSymbol() {
	return playerSymbol;
}

/// <summary>
/// Initial question is asked and the reply from the user is returned as a string
/// </summary>
/// <returns></returns>
std::string Player::askInitialQ() {
	std::string answer;
	std::cout << "Would you like to make first move(y/n)?" << std::endl;
	std::cin >> answer;
	return answer;
}
/// <summary>
/// While game is on , this same question is asked again and again until finish, and the reply from the user is returned as a string
/// </summary>
/// <returns></returns>
std::string Player::askplayingQ() {
	std::string answer;
	std::cout << "Enter a number between 0-8 to make your move:" << std::endl;
	std::cin >> answer;
	return answer;
}

/// <summary>
/// THIS METHOD HAVE NOT BEEN USED
/// </summary>
/// <param name="m"></param>
std::string Player::askLastQ() {
	std::string answer;
	std::cout << "Would you like to play again?(y/n)" << std::endl;
	std::cin >> answer;
	return answer;
}
/// <summary>
/// First map has showed to the user
/// Until valid input is given (user cannot select already filled locations) we loop
/// We ask same question, and reply will be written to the map
/// </summary>
/// <returns></returns>
void Player::Play(Map& m) {
	m.Show();
	bool available_answer = false;
	std::string answer;
	while (!available_answer) { 
		answer = askplayingQ();
		available_answer = m.checkMove(answer);
	}
	int picked = std::stoi(answer);
	m.setVal(picked, playerSymbol);
}

