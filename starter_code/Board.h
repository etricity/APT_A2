#ifndef APT_A2_BOARD_H
#define APT_A2_BOARD_H

#endif //APT_A2_BOARD_H

#include "TileCodes.h"
#include "Tile.h"
#include <string>
#include <vector>
#include <iostream>

class Board{
public:
    //constructor
    Board(int xSize, int ySize);

    //destructor
    ~Board();

    void initBoard();
    void print();
    void addTile(int xCoord, int yCoord
    //        , Tile tile
            );

private:

    std::vector<std::vector<std::string> > board;

    int xSize;
    int ySize;


};
