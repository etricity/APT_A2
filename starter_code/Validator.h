#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "CustomException.h"
#include <vector>
#include <sstream>
#include "Player.h"
#include "Board.h"

#include <stdio.h>
#include <ctype.h>

using std::vector; 

class Validator {
public:
    void validToFalse();
    bool validateMenuInput(string userInput);
    bool validateNumPlayers(string userInput);
    bool validateCommand(string userInput, Player* currentPlayer, Board* board, int numPlayers, LinkedList* bag);
    bool validateHandTile(string tileString, Player* currentPlayer);
    bool validationPosition(string positionString, Board* board);
    bool validateSave(string userInput);
    bool validateForfeit(int numPlayers);
    
    bool valid;
};
#endif

/* Structure of the validator blocks for user input
 
 do {
        try {
1.            promptUserInput();
2.            valid = validator.validateNumPlayers(userInput);
        } catch(CustomException e) {
3.            cout << e.getMessage() << endl;
4.            valid = false;
            }
        } while(!valid);
 
 
 1. Prompts the user for userInput (will accept any input)
 2. valids userInput via using a method in validator (specific for user action)
 3. prints the exception message if an exception has been thrown
 4. sets valid to false if exception has been thrown to continue asking for user input
 
 **NOTE** valid will only ever be 'true' when an exception is not thrown
 
*/

/*
 Validator methods
    - Should return true if the input is valid for that specific method
    - Should throw an exception with a custom message if the input is invalid
 */
