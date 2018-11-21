//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//reward header
#ifndef reward_h
#define reward_h

class Reward {
	// Variables
	int reward;

	//constructor(s)
	Reward() { reward = 0; }
	Reward(int _reward) { reward = _reward; }

	std::ostream &operator<<(std::ostream &os, Reward const &m) {
		return os << m.reward;
	}
}
#endif