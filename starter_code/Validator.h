#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "CustomException.h"
#include <vector>
#include <sstream>
#include "Player.h"
#include "Board.h"
#include "GameMechanics.h"

#include <stdio.h>
#include <ctype.h>

using std::vector; 

class Validator {
public:
    bool validateMenuInput(string userInput);
    bool validateNumPlayers(string userInput);
    
    /*
     Parameters are all objects neccessary to validate any command the user may attempt to use.
     Passing all parameters at once allows for less validation methods
     */
    bool validateCommand(string userInput, Player* currentPlayer, Board* board, LinkedList* bag, vector<PosPtr> boardPositions);
    bool validateHandTile(string tileString, Player* currentPlayer);
    bool validationPosition(string positionString, Board* board);
    bool validateSave(string userInput);
    
    bool valid;
};
#endif
