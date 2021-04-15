#ifndef _MAP_
#define _MAP_
#include <vector>
#include <string>
#include "Symbol.h"

class Map {
public:
	Map();
	~Map();
	void Show();
	void setVal(int pos, Symbol s);
	std::string getVal(int pos);
	std::vector<int> CheckAvailableMoves();
	bool checkMove(std::string str);
	bool checkFin(Symbol s);
	bool hasEmpty();
private:
	Symbol map_Values[9];
};
#endif

