//Student Names :: Student Numbers
//Daniel Puritt :: 7275218
//George Agadah : 7405809

//Main CPP

#include "Game.h"
#include "Rules.h"
#include "Player.h"
#include "Board.h"

#include <iostream>
#include <string>
using namespace std;
bool normalMode = true;
bool normalView = true;
bool acceptableInput = false;
int numPlayers=0;
int counter;
Board::Number tempNumber;
Board::Letter tempLetter;
string userInput;
Game *currentGame;
Rules *currentRules;

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
	Player *temp;
	string name;
	while(counter<numPlayers)
	acceptableInput = false;
	cout << "Please enter name of Player["<<std::to_string(counter+1)<<"]: " << endl;
	while (!acceptableInput) {
		cin >> name;
		
		cout<<"User named Player[" << std::to_string(counter + 1) << "]: "<<name <<", is this acceptable: [Y,N]" << endl;
	 if (userInput == "Y") {
		 temp = new Player(name);
		 if (counter == 0) { temp->setSide(Player::bottom); }
		 else if (counter == 1){ temp->setSide(Player::left); }
		 else if (counter == 2) { temp->setSide(Player::top); }
		 else if (counter == 3) { temp->setSide(Player::right); }
		 currentGame->addPlayer(temp);
	acceptableInput = true;
		}
	else {
	acceptableInput = false;
	cout << "Okay, then please enter name of Player[" << std::to_string(counter + 1) << "] again: " << endl;
		}
	}
	
	cout << "Game is now ready to be played, enjoy!!!" << endl;
	cout << currentGame << endl;

	//start the game!!!
	while (!currentRules->gameOver()) {
		//cards are reset upon cunstruction as well as each new round call

		//set all players active
		for (int i = 0; i < numPlayers; ++i) {
			currentGame->getPlayerList(i)->setActive();
		}
		
		//reveal cards briefly to players





	
	}
}