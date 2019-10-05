#include "Validator.h"

void Validator::validToFalse() {
    valid = false;
}

bool Validator::validateMenuInput(string userInput) {
    validToFalse();
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
    
    return valid;
}

bool Validator::validateNumPlayers(string userInput) {
    validToFalse();
    vector<string> validInputs = {"1","2","3","4"};
    
    int i = 0;
    while(!valid && i != validInputs.size()) {
        if(userInput == validInputs[i]) {
            valid = true;
        }
        i++;
    }
    
    if(!valid) {
        throw CustomException("You must have 1-4 players.");
    }
    
    return valid;
}

bool Validator::validateCommand(string userInput, Player* currentPlayer, Board* board, int numPlayers) {
    
    std::istringstream oss(userInput);
    string arg = "";
    
    //Validate action
    vector<string> validActions = {"place","replace","save","quit", "help", "hint", "forfeit"};
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
        
    } else if(arg == "save") {
        arg = "";
        oss >> arg;
        validateSave(arg);
        
    } else if(arg == "quit") {
        
    } else if(arg == "help"){
        
    } else if (arg == "hint") {
        
    } else if (arg == "forfeit") {
        validateForfeit(numPlayers);
        
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

bool Validator::validateForfeit(int numPlayers) {
    
    if(numPlayers <= 1) {
        throw CustomException("You cannot forfeit. You are the only remaining player. Try 'quit'.");
    }
    return true;
}
