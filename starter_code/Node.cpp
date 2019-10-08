
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
    delete tile;
}
