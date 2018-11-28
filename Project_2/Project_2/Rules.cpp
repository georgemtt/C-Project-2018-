//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Rule cpp
#include <string>



#include "Game.h"
#include "Player.h"
#include "Rules.h"
#include "Card.h"


Rules::Rules() {
	normalMode = true;
}

Rules::Rules(bool _normalMode) {
	normalMode = _normalMode;
}

bool Rules::isValid(const Game& givenGame) {
	std::string oldAnimal = (givenGame.getPreviousCard())->getAnimal();
	std::string oldBackground = (givenGame.getPreviousCard())->getAnimal();
	std::string newAnimal = (givenGame.getCurrentCard())->getAnimal();
	std::string newBackground = (givenGame.getCurrentCard())->getAnimal();
	if ((oldAnimal==newAnimal)||(oldBackground==newBackground)) {
		return true;
	}
	else {
		return false;
	}
}

bool Rules::gameOver(const Game& givenGame) {
	if (givenGame.getRound()>6) {
		return true;
	}
	else {
		return false;
	}
}


bool Rules::roundOver(const Game& givenGame) {
	//find if more than one player is active
	int count = 0;

	for (int i = 0; i < 3; ++i) {
		if (givenGame.getPlayerList(i)->isActive()) {
			++count;
		}
	}
	if (count > 1) {
		return false;
	}
	else {
		return true;
	}
}

const Player& Rules::getNextPlayer(const Game& givenGame) {
	int current;
	int next;

	//Normal Rules
	if (normalMode) {
		for (int i = 0; i < 4; ++i) {
			if (givenGame.getPlayerList(i) == givenGame.getCurrentPlayer()) {
				current = i;
			}
		}
		if (current == 3) {
			next = 0;
		}
		else {
			next = current + 1;
		}
		return (*givenGame.getPlayerList(next));
	}

	//Expert Rules
	else {


	}
}

