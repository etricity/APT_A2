
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
    this->tile = tile;
    this->next = next;
}

Node::Node(Node& other)
{
    this->tile = new Tile(*other.tile);
    this->next = nullptr;
}

Node::~Node() {
    clear();
}

void Node::clear() {
    //Do not delete next --> next is a pointer to another node. It will be deleted when the list is deleted.
    delete tile;
}
