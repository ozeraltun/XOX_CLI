#include "AI_Player.h"
#include <vector>
#include <iostream>
#include <random>
#include "Symbol.h"
#include "Map.h"


Symbol ai_Symbol;

bool AI_Player::MakeRandomMove(Map& m) { //if returns 0->OK, if returns 1->NOT AVAILABLE ERROR
	std::vector<int> movelist = m.CheckAvailableMoves(); //will return a list
	if (movelist.size() == 0) {
		std::cout << "NO AVAILABLE MOVE" << std::endl;
		return true;
	}
	else {
		//Randomly picked
		std::default_random_engine generator{ static_cast<long unsigned int>(time(0)) };
		std::uniform_int_distribution<int> distribution(0, movelist.size() - 1);
		int ai_pick = distribution(generator);
		m.setVal(movelist[ai_pick], ai_Symbol);
		return false;
	}
}

void AI_Player::setSymbol (Symbol s) {
	ai_Symbol = s;
}

Symbol AI_Player::getSymbol() {
	return ai_Symbol;
}
