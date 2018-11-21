//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Player CPP

#include "player.h"

	//constructors
class Player {
	Player() {
		name = "";
		intSideOfBoard = 0;
		stringSideOfBoard = "";
		active = false;
		rubyCount = 0;
	}

	Player(String _name, int _intSideOfBoard) {
		name = _name;
		intSideOfBoard = _intSideOfBoard
			if (_intSideOfBoard = 1) {
				stringSideOfBoard = "bottom";
			}
			else if (_intSideOfBoard = 2) {
				stringSideOfBoard = "left";
			}
			else if (_intSideOfBoard = 3) {
				stringSideOfBoard = "top";
			}
			else if (_intSideOfBoard = 4) {
				stringSideOfBoard = "right";
			}
			else {
				stringSideOfBoard = "invalid";
			}
	}

	//to do
	void addReward(const Reward&) {

	}

	//to do
	void setDisplayMode(bool endOfGame) {

	}
};