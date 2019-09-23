#ifndef NODE_H
#define NODE_H

#include "Tile.h"

class Node {
public:

   Node(Tile* tile, Node* next);
   Node(Node& other);
    ~Node();
    void clear();

   Tile*    tile;
   Node*    next;
};

#endif 
