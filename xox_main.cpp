#include <iostream>
#include <string>
#include <vector>
#include <random>

enum Symbol {
	empty, symbol_X, symbol_O
};
class Map {
public:
	Symbol map_Values[9] = { Symbol::empty,Symbol::empty,Symbol::empty,
							 Symbol::empty,Symbol::empty,Symbol::empty,
							 Symbol::empty,Symbol::empty,Symbol::empty };

	Map() {
		Symbol* iterate = map_Values;
		for (int i = 0; i < 9; i++) {
			(*iterate) = Symbol::empty;
			iterate++;
		}
	}
	~Map() {
	}
	void Show() {
		//std::cout << "Here is the map" << std::endl;
		std::cout << getVal(0) << "|" << getVal(1) << "|" << getVal(2) << std::endl;
		std::cout << getVal(3) << "|" << getVal(4) << "|" << getVal(5) << std::endl;
		std::cout << getVal(6) << "|" << getVal(7) << "|" << getVal(8) << std::endl;
	}
	std::string getVal(int pos) {
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
	void setVal(int pos, Symbol s) {
		map_Values[pos] = s;
	}
	bool checkMove(std::string str) {
		int pos = std::stoi(str);

		if (map_Values[pos] == Symbol::empty) { // pos must be in range
			return true;
		}
		else { return false; }
	}
	std::vector<int> CheckAvailableMoves() {
		std::vector<int> allocate;
		for (int i = 0; i < 9; i++) {
			if (map_Values[i] == Symbol::empty) {
				allocate.push_back(i);
			}
		}
		return allocate;
	}
	bool checkFin() {
		if ((((map_Values[0] == map_Values[1]) && (map_Values[1] == map_Values[2])) && (map_Values[0] != Symbol::empty))
			|| (((map_Values[3] == map_Values[4]) && (map_Values[4] == map_Values[5])) && (map_Values[3] != Symbol::empty))
			|| (((map_Values[6] == map_Values[7]) && (map_Values[7] == map_Values[8])) && (map_Values[6] != Symbol::empty))) {
			//std::cout << "Game finished row wise" << std::endl;
			return true;
		}
		else if ((((map_Values[0] == map_Values[3]) && (map_Values[3] == map_Values[6])) && (map_Values[0] != Symbol::empty))
			|| (((map_Values[1] == map_Values[4]) && (map_Values[4] == map_Values[7])) && (map_Values[1] != Symbol::empty))
			|| (((map_Values[2] == map_Values[5]) && (map_Values[5] == map_Values[8])) && (map_Values[2] != Symbol::empty))) {
			//std::cout << "Game finished column wise" << std::endl;
			return true;
		}
		else if ((((map_Values[0] == map_Values[4]) && (map_Values[4] == map_Values[8])) && (map_Values[0] != Symbol::empty))
			|| (((map_Values[2] == map_Values[4]) && (map_Values[4] == map_Values[6])) && (map_Values[2] != Symbol::empty))) {
			//std::cout << "Game finished cross wise" << std::endl;
			return true;
		}
		else {
			//std::cout << "Game have not finished!" << std::endl;
			return false;
		}
	}
};

class Player {
public:
	Symbol playerSymbol;
	void setSymbol(Symbol s) {
		playerSymbol = s;
	}
	Symbol getSymbol() {
		return playerSymbol;
	}
	std::string askInitialQ() {
		std::string answer;
		std::cout << "Would you like to make first move(y/n)?" << std::endl;
		std::cin >> answer;
		return answer;
	}
	std::string askplayingQ() {
		std::string answer;
		std::cout << "Enter a number between 0-8 to make your move:" << std::endl;
		std::cin >> answer;
		return answer;
	}
	std::string askLastQ() {
		std::string answer;
		std::cout << "Would you like to play again?(y/n)" << std::endl;
		std::cin >> answer;
		return answer;
	}
	void Play(Map& m) {
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

};

class AI_Player {
public:
	Symbol playerSymbol;
	bool MakeRandomMove(Map& m) { //if returns 0->OK, if returns 1->NOT AVAILABLE ERROR
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
			m.setVal(movelist[ai_pick], playerSymbol);
			return false;
		}
	}
	void setSymbol(Symbol s) {
		playerSymbol = s;
	}
	Symbol getSymbol() {
		return playerSymbol;
	}
};

class Game {
public:
	Map xoxMap;
	Player user;
	AI_Player ai;
	bool is_Started;
	bool is_Finished;
	std::string winner;

	Game() {
		is_Started = false;
		is_Finished = false;
		winner = "nobody";
	}
	~Game() {
	}
	bool checkFinish() {
		return is_Finished;
	}
	void Iterate() {
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
			user.Play(xoxMap);
		}
		else {
			is_Started = true;
			answer = user.askInitialQ();
			if (answer == "y") {
				user.setSymbol(Symbol::symbol_X);
				ai.setSymbol(Symbol::symbol_O);

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
		}

		std::cout << " " << std::endl;
	}
	void Results() {
		if (winner == "user")
			std::cout << "You WON!" << std::endl;
		else if (winner == "ai")
			std::cout << "You LOST!" << std::endl;
		else
			std::cout << "It is a TIE!" << std::endl;
	}
};


int main()
{
	/*
	* TODO:
	* -TIE problem
	* -Code Clean Up
	* -Improve AI
	*/
	Game game;
	while (!game.checkFinish()) {
		game.Iterate();
	}
	game.Results();
	std::cin.get();
	return 0;
}