#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "TileCodes.h"
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

class LinkedList {
public:

    LinkedList();
    ~LinkedList();
    
    int size();
    
    void add_back(Node* newNode);
    
    void remove_front();
    Node* getNode(char colour, int shape);
    Node* remove(char colour, int shape);
    Node* getHead();
    bool contains(char colour, int shape);
    
    void clear();
    //testing only
    string toString();

private:
    Node* head;
    Node* tail;
    int numNodes; 
};

#endif 
