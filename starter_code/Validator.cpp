#include "Validator.h"

bool Validator::validateMenuInput(string userInput) {
    valid = false;
    vector<string> validInputs = {"1","2","3","4"};
    
    int i = 0;
    while(!valid && i != validInputs.size()) {
        if(userInput == validInputs[i]) {
            valid = true;
        }
        i++;
    }
    
    if(!valid) {
        throw CustomException("Invalid Input.");
    }
    
    return true;
}

bool Validator::validateNumPlayers(string userInput) {
    valid = false;
    vector<string> validInputs = {"2","3","4"};
    
    int i = 0;
    while(!valid && i != validInputs.size()) {
        if(userInput == validInputs[i]) {
            valid = true;
        }
        i++;
    }
    
    if(!valid) {
        throw CustomException("You must have 2-4 players.");
    }
    
    return true;
}

bool Validator::validateCommand(string userInput, Player* currentPlayer, Board* board, LinkedList* bag, vector<PosPtr> boardPositions) {
    
    std::istringstream oss(userInput);
    string arg = "";
    oss >> arg;
    
    if(arg == "place") {
        
        oss >> arg;
        validateHandTile(arg, currentPlayer);
        
        oss >> arg;
        if(arg != "at") {
            throw CustomException("Unknown command structure. \nStrucutre: place <tile> at <position>");
        }
        
        oss >> arg;
        validationPosition(arg, board);
        
    } else if(arg == "replace") {
        oss >> arg;
        validateHandTile(arg, currentPlayer);
        
        if(bag->size() < 1) {
            throw CustomException("There are no tiles left in the bag");
        }
        
    } else if(arg == "save") {
        arg = "";
        oss >> arg;
        validateSave(arg);
        
    } else if(arg == "quit") {
        //no validation required (if statment validates the command)
    } else if(arg == "hint") {
        //no validation required (dont in qwirkle)
        if(boardPositions.size() <= 1){
            throw CustomException("You must have more than one tile placed to enable hints");
        }
        
    } else if(arg == "help"){
        
    } else if (arg == "forfeit") {
        
    } else if (arg == "pass") {
        
    }else {
        throw CustomException("Invalid Command.");
    }
    
    return true;
    
}

bool Validator::validateHandTile(string tileString, Player* currentPlayer) {
    
    // tileString strucutre
    if(!std::isalpha(tileString[0]) || !std::isdigit(tileString[1]) || tileString.length() > 2) {
        throw CustomException("Invalid Tile.");
    }
    
    if(!currentPlayer->getHand()->contains(tileString[0], tileString[1] - '0')) {
        throw CustomException("That tile does not exist in your hand.");
    }
    return true;
}

bool Validator::validationPosition(string positionString, Board* board) {
    
    char yCo = positionString[0];
    int xCo = stoi(positionString.substr(1));
    
    if(!board->isBoardPositionValid(yCo, xCo)) {
        throw CustomException("Invalid Board Position.");
    }
    
    return true;
}

bool Validator::validateSave(string filename) {
    
    if(filename.size() < 1) {
        throw CustomException("Not a valid filename.");
    }
    
    for(int i = 0; i < filename.size(); i++) {
        if(std::isspace(filename[i])) {
            throw CustomException("Not a valid filename.");
        }
    }
    
    return true;
}

