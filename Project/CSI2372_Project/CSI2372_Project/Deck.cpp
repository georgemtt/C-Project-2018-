//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

// Abstract Deck CPP
#include "Deck.h"
#include <algorithm>    // std::random_shuffle


Deck* Deck::createDeck(Card_Decks typeOfDeck) {
	if (typeOfDeck == Deck::CardDeck) {
		return new CardDeck();
	}
	else if (typeOfDeck == Deck::RewardDeck) {
		return new RewardDeck();
	}
}
