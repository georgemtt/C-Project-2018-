//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Player header
#ifndef player_h
#define player_h

class Player {
	
	enum Side { top, bottom, left, right};
	
	//class variables
private:
	String name;
	bool active;
	int rubyCount;
	Side side;


	//constructor(s)
private:
	Player();
	Player(String _name);


public:
	//method(s)
	String getName() { return name; }
	void setActive(bool _active) { active = _active; }
	int getNRubies() { return rubyCount; }
	void addReward(const Reward&);
	void setDisplayMode(bool endOfGame);
	Side getSide(){ return side; }
	void setSide(_side){ side = _side; }
}
#endif
