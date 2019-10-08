#include "BoardPosition.h"

//You will never initialise a board position with a tile, must first be verified for legal move
BoardPosition::BoardPosition(int x, int y) {
    this->x = new int(x);
    this->y = new int(y);
    tile = nullptr;
}

BoardPosition::BoardPosition(BoardPosition& other) {
    this->x = new int(other.getX());
    this->y = new int(other.getY());
    tile = other.tile;
}

BoardPosition::~BoardPosition(){
    delete x;
    delete y;
    x = nullptr;
    y = nullptr;
    
    delete tile;
}

void BoardPosition::setTile(Tile* tile){
    this->tile = tile;
}

int BoardPosition::getX() {
    return *x;
}

int BoardPosition::getY() {
    return *y;
}

Tile BoardPosition::getTile() {
    return *tile ;
}
