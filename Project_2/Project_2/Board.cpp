//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Board CPP

#include "Board.h"
#include "Card.h"
#include <map>
#include <string>
#include <iterator>
#include <iostream> 
using namespace std;







ostream& operator<<(ostream &os, const Board& currentBoard) {
	if (normalView) {
		for (int i = 0; i < 21; ++i) {
			os << normalPrintMap[i] + "\n";
		}
		return os;
	}

	if (!normalView) {
		for (int i = 0; i < 5; ++i) {
			os << expertPrintMap[i] + "\n";
		}
		return os;
	}
}

bool Board::isFaceUp(const Letter& letterVal, const Number& numberVal) {
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

bool Board::turnFaceUp(const Letter& letterVal, const Number& numberVal) {
	int mapCount;
	int mapCountCol;
	Card* tempCard = getCard(letterVal, numberVal);
	std::string row;
	lookUpID = "";
	if (letterVal == A) { 
		lookUpID = "A";
		mapCount = 0;
	}
	else if (letterVal == B) {
		lookUpID = "B"; 
		mapCount = 4;
	}
	else if (letterVal == C) { 
		lookUpID = "C"; 
		mapCount = 8;
	}
	else if (letterVal == D) { 
		lookUpID = "D"; 
		mapCount = 12;
	}
	else if (letterVal == E) { 
		lookUpID = "E"; 
		mapCount = 16;
	}
	if (numberVal == One) {
		lookUpID += "1"; 
		mapCountCol = 2;
	}
	else if (numberVal == Two) {
		lookUpID += "2"; 
		mapCountCol = 6;
	}
	else if (numberVal == Three) { 
		lookUpID += "3"; 
		mapCountCol - 10;
	}
	else if (numberVal == Four) { 
		lookUpID += "4"; 
		mapCountCol = 14;
	}
	else if (numberVal == Five) {
		lookUpID += "5"; 
		mapCountCol = 18;
	}
	bool temp = mapOfCardFaceUp[lookUpID];
	mapOfCardFaceUp[lookUpID] = true;
	if (normalView) {
		for (i = 0; i < 3; ++i) {
			row = tempCard->getRowN(i + 1);
			normalPrintMap[mapCount + i]->replace(mapCountCol, 3, row);
		}
	}
	if (!normalView) {
		//change expertPrintMap
	}
	
	if (temp == true) { return false; }
	else { return true; }
}

bool Board::turnFaceDown(const Letter& letterVal, const Number& numberVal) {
	lookUpID = "";
	if (letterVal == A) {
		lookUpID = "A";
		mapCount = 0;
	}
	else if (letterVal == B) {
		lookUpID = "B";
		mapCount = 4;
	}
	else if (letterVal == C) {
		lookUpID = "C";
		mapCount = 8;
	}
	else if (letterVal == D) {
		lookUpID = "D";
		mapCount = 12;
	}
	else if (letterVal == E) {
		lookUpID = "E";
		mapCount = 16;
	}
	if (numberVal == One) {
		lookUpID += "1";
		mapCountCol = 2;
	}
	else if (numberVal == Two) {
		lookUpID += "2";
		mapCountCol = 6;
	}
	else if (numberVal == Three) {
		lookUpID += "3";
		mapCountCol - 10;
	}
	else if (numberVal == Four) {
		lookUpID += "4";
		mapCountCol = 14;
	}
	else if (numberVal == Five) {
		lookUpID += "5";
		mapCountCol = 18;
	}
	bool temp = mapOfCardFaceUp[lookUpID];
	mapOfCardFaceUp[lookUpID] = true;

	if (normalView) {
		for (i = 0; i < 3; ++i) {
			normalPrintMap[mapCount + i]->replace(mapCountCol, 3, "zzz");
		}
	}

	if (!normalView) {
		//change expertPrintMap
	}
	if (temp == false) { return false; }
	else { return true; }

}

Card* Board::getCard(const Letter& letterVal, const Number& numberVal) {
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

void Board::setCard(const Letter& letterVal, const Number& numberVal, Card* cardGiven) {
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

void Board::reset() {
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

