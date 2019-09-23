#include "LinkedList.h"
#include "Player.h"
#include "Types.h"
#include "fileIO.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>  
#include <string>

#define EXIT_SUCCESS    0

using std::cout;
using std::cin;
using std::endl;
using std::string;

void printMenu();

void newGame();
void loadGame();
void saveGame();
void showInfo();
//void quit();
void loadPlayers(fileIO* myFile);
void loadBoard(fileIO* myFile);
void loadBag(fileIO* myFile);
void loadCurrentPlayer(fileIO* myFile);

LinkedList* generateBag();
void gamePlay();

string userInput;

vector<Player *> players;
Board board;
LinkedList* bag; 
int current;
