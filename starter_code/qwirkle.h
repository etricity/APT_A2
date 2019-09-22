#include "LinkedList.h"
#include "Player.h"
#include "Types.h"
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
void showInfo();
//void quit();
void setPlayer(string line);
void setBoard(string line);
void setBag(string line);
void setCurrentPlayer(string line);

LinkedList* generateBag();
void gamePlay();

string userInput;

vector<Player *> players;
Board board;
LinkedList* bag; 
