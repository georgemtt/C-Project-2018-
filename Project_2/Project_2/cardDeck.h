//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

// Concrete CardDeck CPP
#include "Deck.h"
#include "Card.h"
#include <algorithm>    // std::random_shuffle


class CardDeck : public Deck<Card> {

	friend class Card;

public:
	//constructor
	Card** cardList = new Card*[26];

	CardDeck() {
		//first Animal, all colours
		cardList[0] = new Card(Card::crab, Card::red);
		cardList[1] = new Card(Card::crab, Card::green);
		cardList[2] = new Card(Card::crab, Card::purple);
		cardList[3] = new Card(Card::crab, Card::blue);
		cardList[4] = new Card(Card::crab, Card::yellow);
		//second Animal, all colours
		cardList[5] = new Card(Card::penguin, Card::red);
		cardList[6] = new Card(Card::penguin, Card::green);
		cardList[7] = new Card(Card::penguin, Card::purple);
		cardList[8] = new Card(Card::penguin, Card::blue);
		cardList[9] = new Card(Card::penguin, Card::yellow);
		//third Animal, all colours
		cardList[10] = new Card(Card::octupus, Card::red);
		cardList[11] = new Card(Card::octupus, Card::green);
		cardList[12] = new Card(Card::octupus, Card::purple);
		cardList[13] = new Card(Card::octupus, Card::blue);
		cardList[14] = new Card(Card::octupus, Card::yellow);
		//fourth Animal, all colours
		cardList[15] = new Card(Card::turtle, Card::red);
		cardList[16] = new Card(Card::turtle, Card::green);
		cardList[17] = new Card(Card::turtle, Card::purple);
		cardList[18] = new Card(Card::turtle, Card::blue);
		cardList[19] = new Card(Card::turtle, Card::yellow);
		//fifth Animal, all colours
		cardList[20] = new Card(Card::walrus, Card::red);
		cardList[21] = new Card(Card::walrus, Card::green);
		cardList[22] = new Card(Card::walrus, Card::purple);
		cardList[23] = new Card(Card::walrus, Card::blue);
		cardList[24] = new Card(Card::walrus, Card::yellow);
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
		if (cardList[0] != nullptr) { return false; }
		else { return true; }
	}
};