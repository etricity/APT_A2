#ifndef QWIRKLE_H
#define QWIRKLE_H

#include "Board.h"
#include "LinkedList.h"
#include "Player.h"
#include "FileIO.h"
#include "GameMechanics.h"
#include "BoardPosition.h"
#include "Validator.h"


#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>


#define EXIT_SUCCESS    0

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//Qwirkle Methods

/*
 * User input methods allow EOF input to exit program immediately
 */
//gets input from the user
void promptUserInput();
//gets input from user (including white spaces)
void promtUserInput_WholeLine();


//opening menu of the program
void printMenu();

//Menu methods (actions)
void newGame();
void loadGame();
void gamePlay();
void saveGame();
void showInfo();
void quit();

//Additional gameplay methods
void showCommands();
void displayEndGameInfo();
bool checkEndGameConditions();
LinkedList* generateBag();
Player* calculateWinner();

//utility function to convert a character into its integer counterpart
int alphToNum(char letter);

void clear();

//load functions
void loadPlayers(FileIO* myFile);
void loadBoard(FileIO* myFile);
void loadBag(FileIO* myFile);
void loadCurrentPlayer(FileIO* myFile);

//Qwirkle Fields
Validator validator;
string userInput;
bool valid;

vector<Player *> players;
Player* currentPlayer;
Board* board;
LinkedList* bag;

GameMechanics gameMechanics;
PosVec boardPositions;

#endif //QWIRKLE_H
