
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include "TileCodes.h"
#include <iostream>

using std::cout;
using std::endl;

class LinkedList {
public:

    LinkedList();
    ~LinkedList();
    
    int size();
    
    void add_back(Node* newNode);
    
    void remove_front();
    void remove(char colour, int shape);
    //containTile
    
    void clear();
    //testing only
    void printList();

private:
    Node* head;
    Node* tail;
    int numNodes; 
};

#endif // ASSIGN2_LINKEDLIST_H
