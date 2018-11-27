//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Player header
#include <map>
#include <string>
#include <iterator>

#include "Reward.h"
#include "Card.h"
#include "rewardDeck.h"
#include "cardDeck.h"

#ifndef board_h
#define board_h

class Board {

	enum Number { One, Two, Three, Four, Five };
	enum Letter { A, B, C, D, E};


	//class variables
private:
	std::string loopUpID;
	RewardDeck *pointCards;
	CardDeck *playCards;

	std::map<std::string, Card*> mapOfCards;
	std::map<std::string, bool> mapOfCardFaceUp;
	//constructor(s)
private:
	Board() {
		pointCards = new RewardDeck();
		playCards = new CardDeck();
	//	(*pointCards).make_RewardDeck();	//Shuffle Decks
	//	(*playCards).make_CardDeck();		//Shuffle Decks
	
			mapOfCards.insert(std::make_pair("A1",playCards->getNext()));
			mapOfCards.insert(std::make_pair("A2", playCards->getNext()));
			mapOfCards.insert(std::make_pair("A3", playCards->getNext()));
			mapOfCards.insert(std::make_pair("A4", playCards->getNext()));
			mapOfCards.insert(std::make_pair("A5", playCards->getNext()));

			mapOfCards.insert(std::make_pair("B1", playCards->getNext()));
			mapOfCards.insert(std::make_pair("B2", playCards->getNext()));
			mapOfCards.insert(std::make_pair("B3", playCards->getNext()));
			mapOfCards.insert(std::make_pair("B4", playCards->getNext()));
			mapOfCards.insert(std::make_pair("B5", playCards->getNext()));

			mapOfCards.insert(std::make_pair("C1", playCards->getNext()));
			mapOfCards.insert(std::make_pair("C2", playCards->getNext()));
			mapOfCards.insert(std::make_pair("C4", playCards->getNext()));
			mapOfCards.insert(std::make_pair("C5", playCards->getNext()));

			mapOfCards.insert(std::make_pair("D1", playCards->getNext()));
			mapOfCards.insert(std::make_pair("D2", playCards->getNext()));
			mapOfCards.insert(std::make_pair("D3", playCards->getNext()));
			mapOfCards.insert(std::make_pair("D4", playCards->getNext()));
			mapOfCards.insert(std::make_pair("D5", playCards->getNext()));

			mapOfCards.insert(std::make_pair("E1", playCards->getNext()));
			mapOfCards.insert(std::make_pair("E2", playCards->getNext()));
			mapOfCards.insert(std::make_pair("E3", playCards->getNext()));
			mapOfCards.insert(std::make_pair("E4", playCards->getNext()));
			mapOfCards.insert(std::make_pair("E5", playCards->getNext()));

			mapOfCardFaceUp.insert(std::make_pair("A1", false));
			mapOfCardFaceUp.insert(std::make_pair("A2", false));
			mapOfCardFaceUp.insert(std::make_pair("A3", false));
			mapOfCardFaceUp.insert(std::make_pair("A4", false));
			mapOfCardFaceUp.insert(std::make_pair("A5", false));
				
			mapOfCardFaceUp.insert(std::make_pair("B1", false));
			mapOfCardFaceUp.insert(std::make_pair("B2", false));
			mapOfCardFaceUp.insert(std::make_pair("B3", false));
			mapOfCardFaceUp.insert(std::make_pair("B4", false));
			mapOfCardFaceUp.insert(std::make_pair("B5", false));

			mapOfCardFaceUp.insert(std::make_pair("C1", false));
			mapOfCardFaceUp.insert(std::make_pair("C2", false));
			mapOfCardFaceUp.insert(std::make_pair("C4", false));
			mapOfCardFaceUp.insert(std::make_pair("C5", false));

			mapOfCardFaceUp.insert(std::make_pair("D1", false));
			mapOfCardFaceUp.insert(std::make_pair("D2", false));
			mapOfCardFaceUp.insert(std::make_pair("D3", false));
			mapOfCardFaceUp.insert(std::make_pair("D4", false));
			mapOfCardFaceUp.insert(std::make_pair("D5", false));

			mapOfCardFaceUp.insert(std::make_pair("E1", false));
			mapOfCardFaceUp.insert(std::make_pair("E2", false));
			mapOfCardFaceUp.insert(std::make_pair("E3", false));
			mapOfCardFaceUp.insert(std::make_pair("E4", false));
			mapOfCardFaceUp.insert(std::make_pair("E5", false));

	}

	


public:
	//method(s)
	bool isFaceUp(const Letter& letterVal, const Number& numberVal) {
		loopUpID = "";
		if (letterVal == A) { loopUpID = "A"; }
		else if (letterVal == B) { loopUpID = "B"; }
		else if (letterVal == C) { loopUpID = "C"; }
		else if (letterVal == D) { loopUpID = "D"; }
		else if (letterVal == E) { loopUpID = "E"; }

	
	
	}
	bool turnFaceUp(const Letter&, const Number&);
	bool turnFaceDown(const Letter&, const Number&);
	Card* getCard(const Letter&, const Number&);
	void setCard(const Letter&, const Number&, Card*);
	void reset();


};
#endif