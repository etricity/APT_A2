#ifndef QWIRKLE_H
#define QWIRKLE_H

#include "Board.h"
#include "LinkedList.h"
#include "Player.h"
#include "FileIO.h"
#include "GameMechanics.h"
#include "BoardPosition.h"

#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>


#define EXIT_SUCCESS    0

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


    void printMenu();

    void newGame();
    void loadGame();
    void saveGame();
    void showInfo();
    //void quit();

    void loadPlayers(FileIO* myFile);
    void loadBoard(FileIO* myFile);
    void loadBag(FileIO* myFile);
    void loadCurrentPlayer(FileIO* myFile);
<<<<<<< HEAD

    LinkedList* generateBag();
    void gamePlay();

    string userInput;

    vector<Player *> players;
    Player* currentPlayer;
    Board* board;
    LinkedList* bag;

//    GameMechanics gameMechanics; 
=======

    LinkedList* generateBag();
    void gamePlay();

    string userInput;

    vector<Player *> players;
    Player* currentPlayer;
    Board* board;
    LinkedList* bag;
>>>>>>> development


#endif //QWIRKLE_H
