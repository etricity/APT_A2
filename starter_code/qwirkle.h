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

//gets input from the user
void promptUserInput();
//gets input from user (including white spaces)
void promtUserInput_WholeLine();

void printMenu();

void newGame();
void loadGame();
void gamePlay();
void saveGame();
void showInfo();
void showCommands();
void quit();
void displayEndGameInfo();

LinkedList* generateBag();
bool checkEndGameConditions();
Player* calculateWinner();

void clear();

//utility function to convert a character into its integer counterpart
int alphToNum(char letter);

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
