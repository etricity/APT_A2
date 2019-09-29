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

