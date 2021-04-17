#include "AI_Player.h"
#include <vector>
#include <iostream>
#include <random>
#include "Symbol.h"
#include "Map.h"


Symbol ai_Symbol;

void AI_Player::MakeRandomMove(Map& m) { 
	std::vector<int> movelist = m.CheckAvailableMoves(); 
	//Picking Randomly
	std::default_random_engine generator{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> distribution(0, movelist.size() - 1);
	int ai_pick = distribution(generator);
	m.setVal(movelist[ai_pick], ai_Symbol);
}

void AI_Player::setSymbol (Symbol s) {
	ai_Symbol = s;
}

Symbol AI_Player::getSymbol() {
	return ai_Symbol;
}
