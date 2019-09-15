#include "LinkedList.h"
#include <string>

using std::string;

class Player {
public:
    
    Player(string name, string studentId);
    ~Player();
    
    string name;
    string studentId;
    string email;
    LinkedList hand;
    
    string getName();
    string getStudentId();
    string getEmail();
    LinkedList getHand();
    
    void clear();
};
