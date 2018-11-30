//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Main CPP

#include "Game.h"
#include "Game.cpp"
#include "Rules.h"
#include "Rules.cpp"
#include "Player.h"
#include "Player.cpp"
#include "Board.h"
#include "Board.cpp"
#include "Card.h"

#include <iostream>
#include <string>
using namespace std;
    bool normalMode = true;
    bool normalView = true;
    bool acceptableInput = false;
    bool firstMove = true;
    int numPlayers=0;
    int counter;
    Player *tempPlayer;
    Card *tempCard;
    Player::Side tempSide;
    Board::Letter tempLetter;
    Board::Number tempNumber;
    Board::Number one= Board::One;
    Board::Number two = Board::Two;
    Board::Number three = Board::Three;
    Board::Number four = Board::Four;
    Board::Number five = Board::Five;
    Board::Letter aLetter = Board::A;
    Board::Letter bLetter = Board::B;
    Board::Letter cLetter = Board::C;
    Board::Letter dLetter = Board::D;
    Board::Letter eLetter = Board::E;
    string userInput;
    Game *currentGame;
    Rules *currentRules;
    Player ** winnerList = new Player*[4];

int main() {
	//Get Rule Mode
	cout << "Please enter Game Rule Mode: [Normal,Expert] "<<endl;
	while (!acceptableInput) {
		cin >> userInput;
		if ((userInput == "Normal") || (userInput == "normal") || (userInput == "N") || (userInput == "n")) {
			normalMode = true;
			acceptableInput = true;
		}
		else if ((userInput == "Expert") || (userInput == "expert") || (userInput == "E") || (userInput == "e")) {
			normalMode = false;
			acceptableInput = true;
		}
		else {
			acceptableInput = false;
			cout << "Invalid input, please enter Game Rule Mode again: [Normal,Expert]" << endl;
		}
	}
	currentRules = new Rules(normalMode);
	acceptableInput = false;

	//Get View Mode
	cout << "Please enter Game View Mode: [Normal,Expert] " << endl;
	while (!acceptableInput) {
		cin >> userInput;
		if ((userInput == "Normal") || (userInput == "normal") || (userInput == "N") || (userInput == "n")) {
			normalView = true;
			acceptableInput = true;
		}
		else if ((userInput == "Expert") || (userInput == "expert") || (userInput == "E") || (userInput == "e")) {
			normalView = false;
			acceptableInput = true;
		}
		else {
			acceptableInput = false;
			cout << "Invalid input, please enter Game View Mode again: [Normal,Expert]" << endl;
		}
	}
	currentGame = new Game(normalView);
	acceptableInput = false;

	//Get Player Count
	cout << "Please enter number of players: [2,3,4] " << endl;
	while (!acceptableInput) {
		cin >> userInput;
		if (userInput == "2") {
			numPlayers = 2;
			acceptableInput = true;
		}
		else if (userInput == "3") {
			numPlayers = 3;
			acceptableInput = true;
		}
		else if (userInput == "4") {
			numPlayers = 4;
			acceptableInput = true;
		}
		else {
			acceptableInput = false;
			cout << "Invalid input, please enter number of players again : [2,3,4]" << endl;
		}
	}

	//Get Player Names
	counter = 0;
	string nameInput;
	while(counter < numPlayers) {
        acceptableInput = false;
        cout << "Please enter name of Player[" << std::to_string(counter + 1) << "]: " << endl;
        while (!acceptableInput) {
			getline(cin,nameInput);

            cout << "User named Player[" << std::to_string(counter + 1) << "]: " << nameInput
                 << ", is this acceptable: [Y,N]" << endl;

            getline(cin,userInput); //change from cin >> userInput

            if (userInput == "Y") {
                tempPlayer = new Player(nameInput);
                if (counter == 0) { tempPlayer->setSide(Player::bottom); }
                else if (counter == 1) { tempPlayer->setSide(Player::left); }
                else if (counter == 2) { tempPlayer->setSide(Player::top); }
                else if (counter == 3) { tempPlayer->setSide(Player::right); }
                currentGame->addPlayer(*tempPlayer);
                acceptableInput = true;
                ++counter;
            } else {
                acceptableInput = false;
                cout << "Okay, then please enter name of Player[" << std::to_string(counter + 1) << "] again: " << endl;
            }
        }

    }

	
	cout << "Game is now ready to be played, enjoy!!!" << endl;
	cout << currentGame << endl;

	//start the game!!!
	while (!currentRules->gameOver(currentGame)) {
		//cards are reset upon cunstruction as well as each new round call

		//set all players active
		for (int i = 0; i < numPlayers; ++i) {
			currentGame->getPlayerList(i)->setActive(true);
		}
		
		//reveal cards briefly to players
		for (int i = 0; i < numPlayers; ++i) {
			tempPlayer = currentGame->getPlayerList(i);
			tempSide = tempPlayer->getSide();
			if (tempSide == Player::bottom) {
				currentGame->getBoard()->turnFaceUp(eLetter, two);
				currentGame->getBoard()->turnFaceUp(eLetter, three);
				currentGame->getBoard()->turnFaceUp(eLetter, four);
				cout << tempPlayer->getName() << ", please look at the three cards in front of you. Press enter when you are done." << endl;
				cin >> userInput;
				currentGame->getBoard()->reset();
			}
			else if (tempSide == Player::left) {
				currentGame->getBoard()->turnFaceUp(bLetter, one);
				currentGame->getBoard()->turnFaceUp(cLetter, one);
				currentGame->getBoard()->turnFaceUp(dLetter, one);
				cout << tempPlayer->getName() << ", please look at the three cards in front of you. Press enter when you are done." << endl;
				cin >> userInput;
				currentGame->getBoard()->reset();
			}
			else if (tempSide == Player::top) {
				currentGame->getBoard()->turnFaceUp(aLetter, two);
				currentGame->getBoard()->turnFaceUp(aLetter, three);
				currentGame->getBoard()->turnFaceUp(aLetter, four);
				cout << tempPlayer->getName() << ", please look at the three cards in front of you. Press enter when you are done." << endl;
				cin >> userInput;
				currentGame->getBoard()->reset();
			}
			else if (tempSide == Player::right) {
				currentGame->getBoard()->turnFaceUp(bLetter, five);
				currentGame->getBoard()->turnFaceUp(cLetter, five);
				currentGame->getBoard()->turnFaceUp(dLetter, five);
				cout << tempPlayer->getName() << ", please look at the three cards in front of you. Press enter when you are done." << endl;
				cin >> userInput;
				currentGame->getBoard()->reset();
			}
		}
		cout << (currentGame->getBoard()) << endl;
		//play through the round
		
		while (!currentRules->roundOver(currentGame)) {
			if (normalMode) {
				acceptableInput = false;
				cout << tempPlayer->getName() << ", please input your card choice: ";
					while (!acceptableInput) {
						cin >> userInput;
						//invalid length of input
						if (userInput.length() != 2) {
							cout << "Please input a a valid choice: ";
							acceptableInput = false;
						}
						//valid length input
						else{
							string letter = userInput.substr(0, 1);
							string number = userInput.substr(1, 1);
							bool invalidLetter = false;
							if ((letter == "A") || (letter == "a")) { tempLetter = aLetter; }
							else if ((letter == "B") || (letter == "b")) { tempLetter = bLetter; }
							else if ((letter == "C") || (letter == "c")) { tempLetter = cLetter; }
							else if ((letter == "D") || (letter == "d")) { tempLetter = dLetter; }
							else if ((letter == "E") || (letter == "e")) { tempLetter = eLetter; }
							else { invalidLetter = true; }
							bool invalidNumber = false;
							if (number == "1") { tempNumber = one; }
							else if (number == "2") { tempNumber = two; }
							else if (number == "3") { tempNumber = three; }
							else if (number == "4") { tempNumber = four; }
							else if (number == "5") { tempNumber = five; }
							else { invalidNumber = true; }
							
							//not acceptable coordinate (or center card)
							if ((invalidLetter)||(invalidNumber)||((tempLetter==cLetter)&&(tempNumber==three))) {
								cout << "Invalid coordinate selected, please try again: ";
								acceptableInput = false;
							}
							else {
								//card is already face up
								if (currentGame->getBoard()->isFaceUp(tempLetter,tempNumber)) {
									cout << "The card at this location is already face up, please try again: ";
									acceptableInput = false;
								}
								else {//card is face down
									acceptableInput = true;
								}
							}
						}
					}
				//acceptable user input, now do work with it

				//guaranteed to be valid
				if (firstMove) {
					firstMove = false;
					tempCard = currentGame->getCard(tempLetter, tempNumber);
					currentGame->setCurrentCard(tempCard);
					currentGame->setCurrentCard(tempCard);
					currentRules->getNextPlayer(currentGame);
				}
				else {
					tempCard = currentGame->getCard(tempLetter, tempNumber);
					currentGame->setCurrentCard(tempCard);
					if (!currentRules->isValid(currentGame)) { currentGame->getCurrentPlayer()->setActive(false); }
					currentRules->getNextPlayer(currentGame);
				}
			cout << (currentGame->getBoard()) << endl;
			}
			//Expert Mode Rules
			else {
			}
		}
		//last player of the round
		for (int i = 0; i < numPlayers; ++i) {
			if (currentGame->getPlayerList(i)->isActive()) {
				tempPlayer = currentGame->getPlayerList(i);
			}
		}
		tempPlayer->addReward(*(currentGame->getBoard()->getNextReward()));
		cout << tempPlayer->getName() << "won this round, congratulations!" << endl;
		currentGame->nextRound();
	}
	//all game rounds are done
	int highestPoints = 0;
	for (int i = 0; i < numPlayers; ++i) {
		if (currentGame->getPlayerList(i)->getNRubies()> highestPoints) {
			winnerList[0] = currentGame->getPlayerList(i);
			winnerList[0]->setDisplayMode(true);
		}
	}
	highestPoints = 0;
	for (int i = 0; i < numPlayers; ++i) {
		if ((currentGame->getPlayerList(i)!= winnerList[0])&&(currentGame->getPlayerList(i)->getNRubies() > highestPoints)) {
			winnerList[1] = currentGame->getPlayerList(i);
			winnerList[1]->setDisplayMode(true);
		}
	}
	if (numPlayers > 2) {
		highestPoints = 0;
		for (int i = 0; i < numPlayers; ++i) {
			if ((currentGame->getPlayerList(i) != winnerList[1])&&(currentGame->getPlayerList(i) != winnerList[0]) && (currentGame->getPlayerList(i)->getNRubies() > highestPoints)) {
				winnerList[2] = currentGame->getPlayerList(i);
				winnerList[2]->setDisplayMode(true);
			}
		}
	}
	if (numPlayers > 3) {
		highestPoints = 0;
		for (int i = 0; i < numPlayers; ++i) {
			if ((currentGame->getPlayerList(i) != winnerList[2]) && (currentGame->getPlayerList(i) != winnerList[1]) && (currentGame->getPlayerList(i) != winnerList[0]) && (currentGame->getPlayerList(i)->getNRubies() > highestPoints)) {
				winnerList[3] = currentGame->getPlayerList(i);
				winnerList[3]->setDisplayMode(true);
			}
		}
	}
	cout << "First place goes to: " << winnerList[0] << endl;
	cout << "Second place goes to: " << winnerList[1] << endl;
	if (numPlayers > 2) {
	cout << "Third place goes to: " << winnerList[2] << endl;
	}
	if (numPlayers > 3) {
		cout << "Fourth place goes to: " << winnerList[3] << endl;
	}
	cout << "Hope you enjoyed the game!" << endl;

	//just to make terminal stay open till user hits enter after print statements

	cin >> userInput;

}