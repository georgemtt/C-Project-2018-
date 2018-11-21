//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Abstract Deck Header
#include <algorithm>    // std::random_shuffle

#ifndef deck_h
#define deck_h
class Deck {
public:
	enum Card_Decks {
		CardDeck,
		RewardDeck
	};

	virtual void shuffle() = 0;
	virtual Deck* getNext() = 0;
	virtual bool isEmpty() = 0;

	static Deck* createDeck(Card_Decks typeOfDeck);
};
#endif