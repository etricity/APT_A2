
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
    this->tile = tile;
    this->next = next;
}

Node::Node(Node& other)
{
    this->tile = other.tile;
    this->next = nullptr;
}

Node::~Node() {
    clear();
}

void Node::clear() {
    tile = nullptr;
    //Attempting to either set next to nullptr or delete it causes a Seg Fault
    //Needs to be further looked at for memmory deallocation 
    delete tile;
}
