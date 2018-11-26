//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809


#include <iostream> 
using namespace std;
//Reward header
#ifndef reward_h
#define reward_h

ostream& operator<<(ostream &os, const Reward& currentReward) {
	return (os << currentReward.getReward();
}
class Reward {
		
	//class variables
private:
	int reward;
	friend ostream& operator<<(ostream &os, const Reward& currentReward);

	//constructor(s)
private:
	//empty constructor
	Reward(){
		reward = 0;
	}
	//given value upon creation
	Reward(int _reward){
		reward = _reward;
	}


public:
	//method(s)
	//get private value of reward
	int getReward() { return reward; }

	//make reward printable by overriding the << operator
	ostream& operator<<(ostream &os, const Reward& currentReward) { 
    return (os << currentReward.reward;
	}
	//Defined Cast
	operator int() const { return reward; }
};
#endif
