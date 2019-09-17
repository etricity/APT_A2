#include "LinkedList.h"
#include <string>

using std::string;

class Player {
public:
    
    Player(string name);
    ~Player();
    
    string name;
    int score;
    LinkedList * hand;
    
    string getName();
    int getScore();
    void addToScore(int points);
    LinkedList * getHand();
    
    void clear();
};
