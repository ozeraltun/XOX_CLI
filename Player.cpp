#include "Player.h"
#include <string>
#include <iostream>
#include "Symbol.h"
#include "Map.h"

Symbol playerSymbol;

void Player::setSymbol(Symbol s) {
	playerSymbol = s;
}

Symbol Player::getSymbol() {
	return playerSymbol;
}

std::string Player::askInitialQ() {
	std::string answer;
	std::cout << "Would you like to make first move(y/n)?" << std::endl;
	std::cin >> answer;
	return answer;
}

std::string Player::askplayingQ() {
	std::string answer;
	std::cout << "Enter a number between 0-8 to make your move:" << std::endl;
	std::cin >> answer;
	return answer;
}

std::string Player::askLastQ() {
	std::string answer;
	std::cout << "Would you like to play again?(y/n)" << std::endl;
	std::cin >> answer;
	return answer;
}

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

