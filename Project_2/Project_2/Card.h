//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//card header
#include <string>

#ifndef card_h
#define card_h



class Card {
public:
	enum FaceAnimal { crab, penguin, octupus, turtle, walrus };

	enum FaceBackground { red, green, purple, blue, yellow };


	//class variables
private:
	std::string animal;
	std::string background;
	std::string *row = new std::string[3];


	//constructor(s)
public:
	Card(FaceAnimal fAnimal, FaceBackground fBackground) {
		if (fAnimal == crab) { animal = "C"; }
		else if (fAnimal == penguin) { animal = "P"; }
		else if (fAnimal == octupus) { animal = "O"; }
		else if (fAnimal == turtle) { animal = "T"; }
		else if (fAnimal == walrus) { animal = "W"; }

		if (fBackground == red) { background = "r"; }
		else if (fBackground == green) { background = "g"; }
		else if (fBackground == purple) { background = "p"; }
		else if (fBackground == blue) { background = "b"; }
		else if (fBackground == yellow) { background = "y"; }

		row[0] = background + background + background;
		row[1] = background + animal + background;
		row[2] = background + background + background;

	}

public:
	//method(s)
	std::string getAnimal() const { return animal; }
	std::string getBackground() const { return background; }
	std::string getRowN(int n)  { return row[n-1]; }




};
#endif
