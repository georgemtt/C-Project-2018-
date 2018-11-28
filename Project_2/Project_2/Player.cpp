//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Player CPP

#include "Player.h"
#include "Reward.h"
#include <string>


	void Player::addReward(Reward newReward) {
		int temp = newReward.getReward();
		setNRubies(temp);
	}

	void Player::setDisplayMode(bool endOfGame) {
		std::string sideString;
		std::string activeStatus;
		std::string rubiesString;
		if (side == top) { sideString = "top"; }
		if (side == bottom) { sideString = "bottom"; }
		if (side == left) { sideString = "left"; }
		if (side == right) { sideString = "right"; }
		if (active) { activeStatus = "(active)"; }
		if (!active) { activeStatus = "(not active)"; }
		if (endOfGame) {
			rubiesString = to_string(rubyCount);
			printable = name + ": " + rubiesString + " rubies";
		}
		else {
			printable = name + ": " + sideString + " " + activeStatus;
		}
	}