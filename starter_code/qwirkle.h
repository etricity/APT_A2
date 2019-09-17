#include "LinkedList.h"
#include "Player.h"
#include "Types.h"
#include <iostream>

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

string userInput;

Player * player1;
Player * player2;
Board board;
