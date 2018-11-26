//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

// Concrete CardDeck CPP
#include "Deck.h"
#include "Card.h"
#include <algorithm>    // std::random_shuffle


class CardDeck : public Deck<Card> {
public:
	//constructor
	Card** cardList = new Card*[26];

	CardDeck() {
		//first Animal, all colours
		cardList[0] = new Card(FaceAnimal::crab, FaceBackground::red);
		cardList[1] = new Card(FaceAnimal::crab, FaceBackground::green);
		cardList[2] = new Card(FaceAnimal::crab, FaceBackground::purple);
		cardList[3] = new Card(FaceAnimal::crab, FaceBackground::blue);
		cardList[4] = new Card(FaceAnimal::crab, FaceBackground::yellow);
		//second Animal, all colours
		cardList[5] = new Card(FaceAnimal::penguin, FaceBackground::red);
		cardList[6] = new Card(FaceAnimal::penguin, FaceBackground::green);
		cardList[7] = new Card(FaceAnimal::penguin, FaceBackground::purple);
		cardList[8] = new Card(FaceAnimal::penguin, FaceBackground::blue);
		cardList[9] = new Card(FaceAnimal::penguin, FaceBackground::yellow);
		//third Animal, all colours
		cardList[10] = new Card(FaceAnimal::octupus, FaceBackground::red);
		cardList[11] = new Card(FaceAnimal::octupus, FaceBackground::green);
		cardList[12] = new Card(FaceAnimal::octupus, FaceBackground::purple);
		cardList[13] = new Card(FaceAnimal::octupus, FaceBackground::blue);
		cardList[14] = new Card(FaceAnimal::octupus, FaceBackground::yellow);
		//fourth Animal, all colours
		cardList[15] = new Card(FaceAnimal::turtle, FaceBackground::red);
		cardList[16] = new Card(FaceAnimal::turtle, FaceBackground::green);
		cardList[17] = new Card(FaceAnimal::turtle, FaceBackground::purple);
		cardList[18] = new Card(FaceAnimal::turtle, FaceBackground::blue);
		cardList[19] = new Card(FaceAnimal::turtle, FaceBackground::yellow);
		//fifth Animal, all colours
		cardList[20] = new Card(FaceAnimal::walrus, FaceBackground::red);
		cardList[21] = new Card(FaceAnimal::walrus, FaceBackground::green);
		cardList[22] = new Card(FaceAnimal::walrus, FaceBackground::purple);
		cardList[23] = new Card(FaceAnimal::walrus, FaceBackground::blue);
		cardList[24] = new Card(FaceAnimal::walrus, FaceBackground::yellow);
		//Final null pointer
		cardList[25] = nullptr;
		//make_CardDeck();

	}

	//methods

	//Figure out how to do this method???????
	//
	CardDeck& make_CardDeck() {
		shuffle();
		return *this;
	}

	void shuffle() {
		std::random_suffle(cardList[0], cardList[24]);
	}

	Card* getNext() {
		Card *temp = cardList[0];
		for (int i = 0; i < 25; ++i) {
			cardList[i] = cardList[i + 1];
		}
		cardList[25] = temp;
		return cardList[0];
	}

	bool isEmpty() {
		if (cardList[0] != nullptr) { return true; }
		else { return false; }
	}
};