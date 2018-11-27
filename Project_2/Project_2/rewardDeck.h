//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

// Concrete RewardDeck Header

#include "Deck.h"
#include "Reward.h"
#include <algorithm>    // std::random_shuffle

class RewardDeck : public Deck<Reward> {
	friend Reward;
public:
	//constructor
	Reward* rewardList;
	rewardList = new Reward[8];
	
	RewardDeck() {
		//all rewards : (3@1pt, 2@2pt, 1@3pt, 1@4pt)
		
		rewardList[0] = new Reward(1);
		rewardList[1] = new Reward(1);
		rewardList[2] = new Reward(1);
		rewardList[3] = new Reward(2);
		rewardList[4] = new Reward(2);
		rewardList[5] = new Reward(3);
		rewardList[6] = new Reward(4);
		//Final null pointer
		cardList[7] = nullptr;

	}

	//methods


	//
	static RewardDeck& make_RewardDeck() {
		//all rewards : (3@1pt, 2@2pt, 1@3pt, 1@4pt)

		shuffle();

		return this; //
	}

	void shuffle() {
		std::random_suffle(rewardList[0], rewardList[6]);
	}

	Reward* getNext() {
		Reward *temp = rewardList[0];
		for (int i = 0; i < 7; ++i) {
			rewardList[i] = rewardList[i + 1];
		}
		rewardList[7] = temp;
		return rewardList[0];
	}

	bool isEmpty() {
		if (rewardList[0] != nullptr) { return false; }
		else { return true; }
	}
};