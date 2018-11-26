//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Player header
#include <string>
#include "Reward.h"

#ifndef player_h
#define player_h

class Player {
	
	enum Side { top, bottom, left, right};
	
	//class variables
private:
	std::string name;
	bool active;
	int rubyCount;
	Side side;


	//constructor(s)
private:
	Player() {
		name = "";
		active = false;
		rubyCount = 0;
	}

	Player(std::string _name) {
		name = _name;
		active = false;
		rubyCount = 0;
	}


public:
	//method(s)
	std::string getName() { return name; }
	void setActive(bool _active) { active = _active; }
	int getNRubies() { return rubyCount; }
	void setNRubies(int moreRubies) { rubyCount += moreRubies; }
	void addReward(Reward);
	void setDisplayMode(bool endOfGame);
	Side getSide(){ return side; }
	void setSide(Side _side){ side = _side; }
};
#endif
