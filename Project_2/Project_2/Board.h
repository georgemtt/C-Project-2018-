//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Player header
#include <map>
#include <string>
#include <iterator>
#include <iostream> 

using namespace std;

#include "Reward.h"
#include "Card.h"
#include "rewardDeck.h"
#include "cardDeck.h"

#ifndef board_h
#define board_h

class Board {
	friend ostream& operator<<(ostream &os, const Board& currentBoard);
public:
	enum Number { One, Two, Three, Four, Five };
	enum Letter { A, B, C, D, E};

	//class variables
private:
	std::string lookUpID;
	int mapCount, mapCountCol;
	RewardDeck *pointCards;
	CardDeck *playCards;
	bool normalView = true;
	std::string* normalPrintMap = new std::string[21];
	std::string* expertPrintMap = new std::string[4];
	std::map<std::string, Card*> mapOfCards;
	std::map<std::string, bool> mapOfCardFaceUp;
	//constructor(s)
public:
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

			normalPrintMap[0]  = "  zzz zzz zzz zzz zzz";
			normalPrintMap[1]  = "A zzz zzz zzz zzz zzz";
			normalPrintMap[2]  = "  zzz zzz zzz zzz zzz";
			normalPrintMap[3]  = "                     ";
			normalPrintMap[4]  = "  zzz zzz zzz zzz zzz";
			normalPrintMap[5]  = "B zzz zzz zzz zzz zzz";
			normalPrintMap[6]  = "  zzz zzz zzz zzz zzz";
			normalPrintMap[7]  = "                     ";
			normalPrintMap[8]  = "  zzz zzz     zzz zzz";
			normalPrintMap[9]  = "C zzz zzz     zzz zzz";
			normalPrintMap[10] = "  zzz zzz     zzz zzz";
			normalPrintMap[11] = "                     ";
			normalPrintMap[12] = "  zzz zzz zzz zzz zzz";
			normalPrintMap[13] = "D zzz zzz zzz zzz zzz";
			normalPrintMap[14] = "  zzz zzz zzz zzz zzz";
			normalPrintMap[15] = "                     ";
			normalPrintMap[16] = "  zzz zzz zzz zzz zzz";
			normalPrintMap[17] = "E zzz zzz zzz zzz zzz";
			normalPrintMap[18] = "  zzz zzz zzz zzz zzz";
			normalPrintMap[19] = "                     ";
			normalPrintMap[20] = "   1   2   3   4   5 ";

			expertPrintMap[0] = " ";
			expertPrintMap[1] = " ";
			expertPrintMap[2] = " ";
			expertPrintMap[3] = " ";

	}
	Board(bool _normalView) {
		normalView = _normalView;
		pointCards = new RewardDeck();
		playCards = new CardDeck();
		//playCards->make_CardDeck();		//Shuffle Decks
		//pointCards->make_RewardDeck();	//Shuffle Decks

		mapOfCards.insert(std::make_pair("A1", playCards->getNext()));
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

		normalPrintMap[0] = "  zzz zzz zzz zzz zzz";
		normalPrintMap[1] = "A zzz zzz zzz zzz zzz";
		normalPrintMap[2] = "  zzz zzz zzz zzz zzz";
		normalPrintMap[3] = "                     ";
		normalPrintMap[4] = "  zzz zzz zzz zzz zzz";
		normalPrintMap[5] = "B zzz zzz zzz zzz zzz";
		normalPrintMap[6] = "  zzz zzz zzz zzz zzz";
		normalPrintMap[7] = "                     ";
		normalPrintMap[8] = "  zzz zzz     zzz zzz";
		normalPrintMap[9] = "C zzz zzz     zzz zzz";
		normalPrintMap[10] = "  zzz zzz     zzz zzz";
		normalPrintMap[11] = "                     ";
		normalPrintMap[12] = "  zzz zzz zzz zzz zzz";
		normalPrintMap[13] = "D zzz zzz zzz zzz zzz";
		normalPrintMap[14] = "  zzz zzz zzz zzz zzz";
		normalPrintMap[15] = "                     ";
		normalPrintMap[16] = "  zzz zzz zzz zzz zzz";
		normalPrintMap[17] = "E zzz zzz zzz zzz zzz";
		normalPrintMap[18] = "  zzz zzz zzz zzz zzz";
		normalPrintMap[19] = "                     ";
		normalPrintMap[20] = "   1   2   3   4   5 ";

		expertPrintMap[0] = " ";
		expertPrintMap[1] = " ";
		expertPrintMap[2] = " ";
		expertPrintMap[3] = " ";
	}

	
public:
	//method(s)
	bool isFaceUp(const Letter& letterVal, const Number& numberVal);
	bool turnFaceUp(const Letter& letterVal, const Number& numberVal);
	bool turnFaceDown(const Letter& letterVal, const Number& numberVal);
	Card* getCard(const Letter& letterVal, const Number& numberVal);
	void setCard(const Letter& letterVal, const Number& numberVal, Card* cardGiven);
	void reset();
	Reward* getNextReward() { return pointCards->getNext(); }
};
#endif