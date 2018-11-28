//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Game header
#include <map>
#include <string>
#include <iterator>
#include <iostream> 

using namespace std;

#include "Board.h"
#include "Card.h"
#include "Player.h"

#ifndef game_h
#define game_h

class Game {
	friend ostream& operator<<(ostream &os, const Game& currentGame);
	//class variables
private:
	int roundCount;
	int playerCount;
	Card *currentCard;
	Card *previousCard;
	Board *currentBoard;
	Player * currentPlayer;
	Player ** playerList = new Player*[4];

	//constructor(s)
public:
	Game();
	Game(bool _normalView);

public:
	//method(s)
	int getRound() const { return roundCount; }
	int nextRound() {
		++roundCount;
		currentBoard->reset();
	}
	void addPlayer(const Player &playerGiven);
	Player& getPlayer(Player::Side givenSide);
	Player* getPlayerList(int givenListID) const { return playerList[givenListID]; }
	const Card* getPreviousCard() const { return previousCard; }
	const Card* getCurrentCard() const { return currentCard; }
	void setCurrentCard(const Card*);
	Card* getCard(const Board::Letter&, const Board::Number&);
	void setCard(const Board::Letter&, const Board::Number&, Card*);
	Board * getBoard() const { return currentBoard; }
	int getPlayerCount() const { return playerCount; }
	Player* getCurrentPlayer() const { return currentPlayer; }
};
#endif
