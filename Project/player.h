//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Player header
#ifndef player_h
#define player_h

class Player {
	//class variables
private:
	String name;
	int intSideOfBoard;
	String stringSideOfBoard;
	bool active;
	int rubyCount;


	//constructor(s)
private:
	Player();
	Player(String _name, int _intSideOfBoard);


public:
	//method(s)
	String getName() { return name; }
	void setActive(bool _active) { active = _active; }
	int getNRubies() { return rubyCount; }
	void addReward(const Reward&);
	void setDisplayMode(bool endOfGame);

}
#endif