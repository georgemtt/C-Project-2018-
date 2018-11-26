//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//card header
#include <string>

#ifndef card_h
#define card_h



class Card {

	enum FaceAnimal { crab, penguin, octupus, turtle, walrus };

	enum FaceBackground { red, green, purple, blue, yellow };

	//class variables
private:
	std::string animal;
	std::string background;
	std::string row1;
	std::string row2;
	std::string row3;


	//constructor(s)
private:
	Card();
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

		row1 = background + background + background;
		row2 = background + animal + background;
		row3 = background + background + background;

	}

public:
	//method(s)
	std::string getAnimal() { return animal; }
	std::string getBackground() { return background; }


};
#endif
