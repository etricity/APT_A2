
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
void LinkedList::add_back(Node* newNode){
    
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    numNodes++;
}

//Removes the head from the list
void LinkedList::remove_front(){
    
    if(head != nullptr){
        head = head->next;
        numNodes--;
    }
}

/*
 *   Removes a node from the list given the tile it holds
 *   If duplicate nodes exist, will remove the first found node
 */
void LinkedList::remove(char colour, int shape){
    
    Node* current = head;
    Node* previous = nullptr;
    if(head->next == nullptr){
        head = nullptr;
    } else {
        //Finds the first tile in hand that is to be removed
        while(colour != current->tile->colour && shape != current->tile->shape){
            previous = current;
            current = current->next;
        }
        //Removes tile from hand
        previous->next = current->next;
    }
    numNodes--;
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

//Test purposes only (delete for final submission)
void LinkedList::printList(){
    
    Node* temp = head;
    cout << "Bag Size: " << size() << endl;
    for(int i = 0; i < numNodes; i++){
        cout << temp->tile->colour
                << temp->tile->shape <<endl;
        temp = temp->next;
    }
}
