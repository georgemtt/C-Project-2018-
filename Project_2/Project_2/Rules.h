//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Rule header
#include <string>

using namespace std;

#include "Game.h"
#include "Player.h"

#ifndef rules_h
#define rules_h

class Rules {
	
	//class variables
private:

	bool normalMode = true;
	bool normalView = true;

	//constructor(s)
public:
	Rules();
	Rules(bool _normalMode);

	//method(s)
public:
	bool isValid(const Game& givenGame);
	bool gameOver(const Game& givenGame);
	bool roundOver(const Game& givenGame);
	const Player& getNextPlayer(const Game& givenGame);


};
#endif