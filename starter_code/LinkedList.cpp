
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    numNodes = 0;
}

LinkedList::~LinkedList() {
    clear();
}

//Returns number of nodes (and therefore tiles)
int LinkedList::size(){
    return numNodes;
}

//Adds a node to the end of the list
void LinkedList::add_back(Node* node){
    
    if(head == nullptr)
    {
        head = node;
        tail = head;
    } else {
        tail->next = node;
        tail = node;
    }
    //FIX THIS --> tail->next must be nullptr
    numNodes++;
}

//Removes the head from the list
void LinkedList::remove_front(){
    
    if(head != nullptr){
        delete head;
        head = head->next;
        numNodes--;
    }
}

/*
 *   Removes a node from the list given the tile it holds
 *   If duplicate nodes exist, will remove the first found node
 */
Node* LinkedList::remove(char colour, int shape){
    
    Node* current = head;
    Node* previous = nullptr;
    if(head->next == nullptr){
        head = nullptr;
    } else {
        //Finds the first tile in hand that is to be removed
        while(colour != current->tile->getColour() || shape != current->tile->getShape()){
            previous = current;
            current = current->next;
        }
        //Removes tile from hand
        previous->next = current->next;
    }
    numNodes--;
    return current;
}

Node* LinkedList::getHead() {
    return head;
}

//Deallocated all memmory for all nodes in the list
void LinkedList::clear(){
    Node* current = head;
    Node* next = nullptr;
    
    for(int i = 0; i < numNodes; i++)
    {
        next = current->next;
        delete current;
        current = next;
    }
    delete current;
}

bool LinkedList::contains(char colour, int shape) {
    bool found = false;
    
    Node * temp = head;
    int i = 0;
    while(!found && i < size()) {
        if(colour == temp->tile->getColour() && shape == temp->tile->getShape()) {
            found = true;
        }
        temp = temp->next;
        i++;
    }
    return found;
    
}

Node* LinkedList::getNode(char colour, int shape){
    
    Node* current = head;
    //Finds the first tile in hand that is to be removed
    while(colour != current->tile->getColour() || shape != current->tile->getShape()){
        current = current->next;
    }
    return current;
}


//Test purposes only (delete for final submission)
string LinkedList::toString(){
    std::ostringstream oss;
    
    Node* temp = head;
    for(int i = 0; i < numNodes; i++){
        oss << temp->tile->getColour() << temp->tile->getShape();

        if(temp->next != nullptr) {
            oss << ", ";
        }
        temp = temp->next;
    }
    oss << endl;
    string listString = oss.str();
    return listString;
}
