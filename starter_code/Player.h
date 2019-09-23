#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include <string>

using std::string;

class Player {
public:
    
    Player(string name);
    ~Player();
    
    
    string getName();
    int getScore();
    void addToScore(int points);
    LinkedList * getHand();
    
private:
    string name;
    int score;
    LinkedList * hand;
    
    void clear();
};

#endif // ASSIGN2_PLAYER_H