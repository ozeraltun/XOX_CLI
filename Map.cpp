#include "Map.h"
#include <iostream>
#include <string>
#include "Symbol.h"

Symbol map_Values[9] = {    Symbol::empty,Symbol::empty,Symbol::empty,
							Symbol::empty,Symbol::empty,Symbol::empty,
							Symbol::empty,Symbol::empty,Symbol::empty };

/// <summary>
/// Initialization of Map object:
/// 3x3 is filled with empty symbols
/// </summary>
Map::Map() {
	Symbol* iterate = map_Values;
	for (int i = 0; i < 9; i++) {
		(*iterate) = Symbol::empty;
		iterate++;
	}
}
/// <summary>
/// heap memory did not used
/// </summary>
Map::~Map() {
}
/// <summary>
/// Prints 3x3 map
/// </summary>
void Map::Show() {
	//std::cout << "Here is the map" << std::endl;
	std::cout << getVal(0) << "|" << getVal(1) << "|" << getVal(2) << std::endl;
	std::cout << getVal(3) << "|" << getVal(4) << "|" << getVal(5) << std::endl;
	std::cout << getVal(6) << "|" << getVal(7) << "|" << getVal(8) << std::endl;
}
/// <summary>
/// returns the string value of the given position
/// </summary>
/// <param name="pos"></param>
/// <returns></returns>
std::string Map::getVal(int pos) {
	std::string str;
	if (map_Values[pos] == Symbol::empty) {
		str = " ";
	}
	else if (map_Values[pos] == Symbol::symbol_X) {
		str = "X";
	}
	else if (map_Values[pos] == Symbol::symbol_O) {
		str = "O";
	}
	else {
		str = "ERROR";
	}
	return str;
}
/// <summary>
/// Fills the given position with given symbol
/// </summary>
/// <param name="pos"></param>
/// <param name="s"></param>
void Map::setVal(int pos, Symbol s) {
	map_Values[pos] = s;
}
/// <summary>
/// Checks whether given position(string) is empty or not
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
bool Map::checkMove(std::string str) {
	int pos = std::stoi(str);
	if (map_Values[pos] == Symbol::empty) { 
		return true;
	}
	else { return false; }
}
/// <summary>
/// this method returns a vector which has the position values of empty spaces
/// </summary>
/// <returns></returns>
std::vector<int> Map::CheckAvailableMoves() {
	std::vector<int> allocate;
	for (int i = 0; i < 9; i++) {
		if (map_Values[i] == Symbol::empty) {
			allocate.push_back(i);
		}
	}
	return allocate;
}
/// <summary>
/// checks 3x3 map has at least one empty symbol
/// </summary>
/// <returns></returns>
bool Map::hasEmpty() {
	for (int i = 0; i < 9; i++) {
		if (map_Values[i] == Symbol::empty) {
			return true;
		}
	}
	return false;
}
/// <summary>
/// checks whether XOX game has finished with given symbol
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool Map::checkFin(Symbol s) {
	if ((((map_Values[0] == map_Values[1]) && (map_Values[1] == map_Values[2])) && (map_Values[0] == s))
		|| (((map_Values[3] == map_Values[4]) && (map_Values[4] == map_Values[5])) && (map_Values[3] == s))
		|| (((map_Values[6] == map_Values[7]) && (map_Values[7] == map_Values[8])) && (map_Values[6] == s))) {
		//std::cout << "Game finished row wise" << std::endl;
		return true;
	}
	else if ((((map_Values[0] == map_Values[3]) && (map_Values[3] == map_Values[6])) && (map_Values[0] == s))
		|| (((map_Values[1] == map_Values[4]) && (map_Values[4] == map_Values[7])) && (map_Values[1] == s))
		|| (((map_Values[2] == map_Values[5]) && (map_Values[5] == map_Values[8])) && (map_Values[2] == s))) {
		//std::cout << "Game finished column wise" << std::endl;
		return true;
	}
	else if ((((map_Values[0] == map_Values[4]) && (map_Values[4] == map_Values[8])) && (map_Values[0] == s))
		|| (((map_Values[2] == map_Values[4]) && (map_Values[4] == map_Values[6])) && (map_Values[2] == s))) {
		//std::cout << "Game finished cross wise" << std::endl;
		return true;
	}
	else {
		//std::cout << "Game have not finished!" << std::endl;
		return false;
	}
}

