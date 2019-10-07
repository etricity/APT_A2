
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

    Node* next = head->next;
    delete head;
    if(next != nullptr) {
        head = next;
        //List is now empty
    } else {
        head = nullptr;
    }
    numNodes--;
}

/*
 *   Removes a node from the list given the tile it holds
 *   If duplicate nodes exist, will remove the first found node
 */
Node* LinkedList::remove(char colour, int shape){
    
    Node* current = head;
    Node* previous = nullptr;
    
    //IF head is to be removed
    if(colour == current->tile->getColour() && shape == current->tile->getShape()){
        remove_front();
    } else {
        
        while(current != nullptr && (colour != current->tile->getColour() || shape != current->tile->getShape())) {
            previous = current;
            current = current->next;
        }
        
        //IF node is found
        if(current != nullptr) {
            
            //IF node to remove is tail
            if(current == tail) {
                previous->next = current->next;
                tail = previous;
                //IF node to remove is not head or tail
            } else {
                previous->next = current->next;
            }
            numNodes--;
        }
        
    }
    
    return current;
}

Node* LinkedList::getHead() {
    return head;
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

//Deallocated all memmory for all nodes in the list
void LinkedList::clear(){
    Node* current = head;
    Node* next = nullptr;
    int i = 0;
    while(current != nullptr) {
        next = current->next;
        delete current;
        current = next;
        i++;
        
    }
    cout << i << endl;
}
