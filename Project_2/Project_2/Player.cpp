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
