#ifndef _MAP_
#define _MAP_
#include <vector>
#include <string>
#include "Symbol.h"
/// @brief This class is responsible for the memory of 3x3 grids and its values 
class Map {
public:
	/// @brief Constructor of Map Object
	Map();

	/// @brief Destructor of Map Object
	~Map();

	/// @brief Prints 3x3 Map
	void Show();

	/// @brief Sets the single value in 3x3 map 
	/// @param pos position value
	/// @param s Symbol value
	void setVal(int pos, Symbol s);

	/// @brief Checks whether given position(given as string) is empty or not
	/// return true if that position is empty, false otherwise
	bool checkMove(std::string str);

	/// @brief Checks whether any finishing conditions have met with given parameter
	/// @param s is a Symbol
	bool checkFin(Symbol s);

	/// @brief Checks whether are there any empty space left
	/// @return true if there is empty space
	bool hasEmpty();

	/// @brief returns the string value of the given position
	/// @return the string value of that location 
	std::string getVal(int pos);

	/// @brief this method returns a vector which has the position values of empty spaces
	/// @return vector that has position values as integers
	std::vector<int> CheckAvailableMoves();
private:
	Symbol map_Values[9];
};
#endif

