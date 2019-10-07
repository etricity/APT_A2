#ifndef BOARDPOSITION_H
#define BOARDPOSITION_H

#include "Tile.h"
#include <vector>

/*
 * Position of tile that resides on the board
 * This the tile should only bet set once a placement is
 * said to be deemed legal from GameMechanics
 *
 * Please look below for convenient typedefs when passing BoardPositions
 * into GameMechanics
 */

class BoardPosition {
public:
    
    // x-co-ordinate
    int getX();
    
    // y-co-ordinate
    int getY();
    
    // Tile
    Tile getTile();
    
    BoardPosition(int x, int y);
    
    BoardPosition(BoardPosition& other);
    
    ~BoardPosition();
    
    void setTile(Tile* tile);
    
    
private:
    int* x;
    int* y;
    Tile* tile;
};

//Pointer to a Board-Position
typedef BoardPosition* PosPtr;
// Vector of pointers to a Board-Position
typedef  std::vector<PosPtr> PosVec;

#endif //BOARDPOSITION_H
