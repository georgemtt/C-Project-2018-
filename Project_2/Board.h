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
	std::string lookUpID;
	RewardDeck *pointCards;
	CardDeck *playCards;

	std::map<std::string, Card*> mapOfCards;
	std::map<std::string, bool> mapOfCardFaceUp;
	//constructor(s)
private:
	Board() {
		pointCards = new RewardDeck();
		playCards = new CardDeck();
		//playCards->make_CardDeck();		//Shuffle Decks
		//pointCards->make_RewardDeck();	//Shuffle Decks
	
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
		lookUpID = "";
		if (letterVal == A) { lookUpID = "A"; }
		else if (letterVal == B) { lookUpID = "B"; }
		else if (letterVal == C) { lookUpID = "C"; }
		else if (letterVal == D) { lookUpID = "D"; }
		else if (letterVal == E) { lookUpID = "E"; }
		if (numberVal == One) { lookUpID += "1"; }
		else if (numberVal == Two) { lookUpID += "2"; }
		else if (numberVal == Three) { lookUpID += "3"; }
		else if (numberVal == Four) { lookUpID += "4"; }
		else if (numberVal == Five) { lookUpID += "5"; }
		bool faceUp = mapOfCardFaceUp[lookUpID];
		return faceUp;
	
	}

	bool turnFaceUp(const Letter& letterVal, const Number& numberVal) {
		lookUpID = "";
		if (letterVal == A) { lookUpID = "A"; }
		else if (letterVal == B) { lookUpID = "B"; }
		else if (letterVal == C) { lookUpID = "C"; }
		else if (letterVal == D) { lookUpID = "D"; }
		else if (letterVal == E) { lookUpID = "E"; }
		if (numberVal == One) { lookUpID += "1"; }
		else if (numberVal == Two) { lookUpID += "2"; }
		else if (numberVal == Three) { lookUpID += "3"; }
		else if (numberVal == Four) { lookUpID += "4"; }
		else if (numberVal == Five) { lookUpID += "5"; }
		bool temp = mapOfCardFaceUp[lookUpID];
		mapOfCardFaceUp[lookUpID] = true;
		if (temp == true) { return false; }
		else { return true; }
	}

	bool turnFaceDown(const Letter& letterVal, const Number& numberVal) {
		lookUpID = "";
		if (letterVal == A) { lookUpID = "A"; }
		else if (letterVal == B) { lookUpID = "B"; }
		else if (letterVal == C) { lookUpID = "C"; }
		else if (letterVal == D) { lookUpID = "D"; }
		else if (letterVal == E) { lookUpID = "E"; }
		if (numberVal == One) { lookUpID += "1"; }
		else if (numberVal == Two) { lookUpID += "2"; }
		else if (numberVal == Three) { lookUpID += "3"; }
		else if (numberVal == Four) { lookUpID += "4"; }
		else if (numberVal == Five) { lookUpID += "5"; }
		bool temp = mapOfCardFaceUp[lookUpID];
		mapOfCardFaceUp[lookUpID] = false;
		if (temp == false) { return false; }
		else { return true; }
	
	}

	Card* getCard(const Letter& letterVal, const Number& numberVal) {
		lookUpID = "";
		if (letterVal == A) { lookUpID = "A"; }
		else if (letterVal == B) { lookUpID = "B"; }
		else if (letterVal == C) { lookUpID = "C"; }
		else if (letterVal == D) { lookUpID = "D"; }
		else if (letterVal == E) { lookUpID = "E"; }
		if (numberVal == One) { lookUpID += "1"; }
		else if (numberVal == Two) { lookUpID += "2"; }
		else if (numberVal == Three) { lookUpID += "3"; }
		else if (numberVal == Four) { lookUpID += "4"; }
		else if (numberVal == Five) { lookUpID += "5"; }
		Card *wantedCard = mapOfCards[lookUpID];
		return wantedCard;
	}

	void setCard(const Letter& letterVal, const Number& numberVal, Card* cardGiven) {
		lookUpID = "";
		if (letterVal == A) { lookUpID = "A"; }
		else if (letterVal == B) { lookUpID = "B"; }
		else if (letterVal == C) { lookUpID = "C"; }
		else if (letterVal == D) { lookUpID = "D"; }
		else if (letterVal == E) { lookUpID = "E"; }
		if (numberVal == One) { lookUpID += "1"; }
		else if (numberVal == Two) { lookUpID += "2"; }
		else if (numberVal == Three) { lookUpID += "3"; }
		else if (numberVal == Four) { lookUpID += "4"; }
		else if (numberVal == Five) { lookUpID += "5"; }
		mapOfCards[lookUpID] = cardGiven;
	}

	void reset() {
		lookUpID = "";
		for (int i = 1; i < 6; ++i) {
			lookUpID = "A" + i;
			mapOfCardFaceUp[lookUpID] = false;
		}
		for (int i = 1; i < 6; ++i) {
			lookUpID = "B" + i;
			mapOfCardFaceUp[lookUpID] = false;
		}
		mapOfCardFaceUp["C1"] = false;
		mapOfCardFaceUp["C2"] = false;
		mapOfCardFaceUp["C4"] = false;
		mapOfCardFaceUp["C5"] = false;
		for (int i = 1; i < 6; ++i) {
			lookUpID = "D" + i;
			mapOfCardFaceUp[lookUpID] = false;
		}
		for (int i = 1; i < 6; ++i) {
			lookUpID = "A" + i;
			mapOfCardFaceUp[lookUpID] = false;
		}
	}


};
#endif