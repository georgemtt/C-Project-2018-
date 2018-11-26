//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//card header
#ifndef card_h
#define card_h



class Card {

	enum FaceAnimal { crab, penguin, octupus, turtle, walrus };

	enum FaceBackground { red, green, purple, blue, yellow };

	//class variables
private:
	String animal;
	String background;
	String row1;
	String row2;
	String row3;


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
	string getAnimal() { return animal; }
	string getBackground() { return background; }


}
#endif
