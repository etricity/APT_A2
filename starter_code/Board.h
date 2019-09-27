#ifndef APT_A2_BOARD_H
#define APT_A2_BOARD_H



#include "TileCodes.h"
#include "Tile.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using std::string;
using std::vector;


class Board{
public:
    //constructor
    Board(int xSize, int ySize);

    //destructor
    ~Board();
    //initialise board
    void initBoard();
    //print board
    string toString();
    //add tile to board
    //tile parameter commented out until I  see the tile code and adapt this function appropriately
    //function implementation uses a dummy string for now
    void addTile(int xCoord, int yCoord, string tileString);

private:
    //board vector, holds vectors of strings
    std::vector<std::vector<std::string>> board;

    //board size
    int xSize;
    int ySize;


};

#endif //APT_A2_BOARD_H
