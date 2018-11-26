//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Reward header
#ifndef reward_h
#define reward_h

class Reward {
		
	//class variables
private:
	int reward;


	//constructor(s)
private:
	Reward(){
		reward = 0;
	}
	Reward(int _reward){
		reward = _reward;
	}


public:
	//method(s)
	int getReward() { return reward; }
	std::ostream &operator<<(std::ostream &os, const Reward& currentReward) { 
    return (os << currentReward.reward;
	}
	//Defined Cast
	operator int() const { return reward; }
}
#endif
