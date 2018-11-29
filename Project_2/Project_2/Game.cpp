//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Game cpp

#include <map>
#include <string>
#include <iterator>
#include <iostream> 

using namespace std;

#include "Board.h"
#include "Card.h"
#include "Player.h"
#include "Game.h"

Game::Game() {
	roundCount = 0;
	playerCount = 0;
	currentCard = nullptr;
	previousCard = nullptr;
	currentBoard = new Board();
	currentBoard->reset();
	playerList[0] = nullptr;
	playerList[1] = nullptr;
	playerList[2] = nullptr;
	playerList[3] = nullptr;
}

Game::Game(bool _normalView) {
	roundCount = 0;
	playerCount = 0;
	currentCard = nullptr;
	previousCard = nullptr;
	currentBoard = new Board(_normalView);
	currentBoard->reset();
	playerList[0] = nullptr;
	playerList[1] = nullptr;
	playerList[2] = nullptr;
	playerList[3] = nullptr;
}

void Game::addPlayer( Player &playerGiven) {
	//no players added yet
	if (playerCount == 0) {
		*currentPlayer = playerGiven;
		++playerCount;
	}
	else {
		int x;
		bool exists = false;
		//check if player is already in game
		for (int i = 0; i < 4; ++i) {
			if (playerList[i] != nullptr) {
				if (playerList[i]->getName() == playerGiven.getName()) {
					exists = true;
					x = i;
				}
			}
		}
		if (exists) { //player exists, update player
			*playerList[x] = playerGiven;
		}
		else { //player doesnt exist, check if under 4
			if (playerCount<4) {
				*playerList[playerCount] = playerGiven;
				++playerCount;
			}
			else {
				cout << "too many players";
			}
		}
	}
}


Player& Game::getPlayer(Player::Side givenSide) {
	Player * temp = nullptr;
	for (int i = 0; i < 4; ++i) {
		if (playerList[i] != nullptr) {
			if (playerList[i]->getSide() == givenSide) {
				temp = playerList[i];
			}
		}
	}
	return *temp;
}


void Game::setCurrentCard( Card* givenCard) {
	previousCard = currentCard;
	*currentCard = *givenCard;
}

Card* Game::getCard( Board::Letter& givenLetter,  Board::Number& givenNumber) {
	return (currentBoard->getCard(givenLetter, givenNumber));
}

void Game::setCard( Board::Letter& givenLetter,  Board::Number& givenNumber, Card* givenCard) {
	currentBoard->setCard(givenLetter, givenNumber, givenCard);
}

ostream& operator<<(ostream &os, const Game& currentGame) {
	os << (currentGame.getBoard()) << "\n";
	for (int i = 0; i < currentGame.getPlayerCount(); ++i) {
		os << currentGame.getPlayerList(i) << "\n";
	}
}
