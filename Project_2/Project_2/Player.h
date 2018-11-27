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
	std::string printable;


	//constructor(s)
private:
	Player() {
		name = "";
		active = false;
		rubyCount = 0;
		printable = "";
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
	bool isActive() { return active; }
	int getNRubies() { return rubyCount; }
	void setNRubies(int moreRubies) { rubyCount += moreRubies; }
	void addReward(Reward);
	Side getSide(){ return side; }
	void setSide(Side _side){ side = _side; }

	//to do
	void setDisplayMode(bool endOfGame) {
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
};
#endif
