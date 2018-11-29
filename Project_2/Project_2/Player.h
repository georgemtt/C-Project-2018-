//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Player header
#include <string>
#include "Reward.h"

#ifndef player_h
#define player_h

class Player {
	friend ostream& operator<<(ostream &os, const Player& currentPlayer);
public:
	enum Side { top, bottom, left, right};
	
	//class variables
private:
	std::string name;
	bool active;
	int rubyCount;
	Side side;
	std::string printable;


	//constructor(s)
public:
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
	std::string getName() const { return name; }
	void setActive(bool _active) { active = _active; }
	bool isActive() { return active; }
	int getNRubies() { return rubyCount; }
	void setNRubies(int moreRubies) { rubyCount += moreRubies; }
	void addReward(Reward);
	Side getSide(){ return side; }
	void setSide(Side _side){ side = _side; }
	void setDisplayMode(bool endOfGame);
	string getPrintable() const { return printable; }
};
#endif
