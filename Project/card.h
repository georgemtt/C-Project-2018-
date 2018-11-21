//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//card header
#ifndef card_h
#define card_h



class Card{

	enum FaceAnimal { crab, penguin, octupus, turtle, walrus };

	enum FaceBackground { red, green, purple, blue, yellow };

	//class variables
	private:
	String animal;
	String background;
	String row;
	int rows =3;
	int cols =3;

		
	//constructor(s)
	private:
	Card();
	Card (FaceAnimal fAnimal, FaceBackground fBackground){
		if		(fAnimal == crab)	 { animal = "C"; }
		else if (fAnimal == penguin) { animal = "P"; }
		else if (fAnimal == octupus) { animal = "O"; }
		else if (fAnimal == turtle)	 { animal = "T"; }
		else if (fAnimal == walrus)	 { animal = "W"; }

		if		(fBackground == red)	 { animal = "r"; }
		else if (fBackground == green)	 { animal = "g"; }
		else if (fBackground == purple)	 { animal = "p"; }
		else if (fBackground == blue)	 { animal = "b"; }
		else if (fBackground == yellow)	 { animal = "y"; }
	}

	public:
	//method(s)

}
#endif