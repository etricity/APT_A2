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
    
    //initialise board
    void initBoard();
    
    //toString board
    string toString();
    
    //add tile to board
    //tile parameter commented out until I  see the tile code and adapt this function appropriately
    //function implementation uses a dummy string for now
    void addTile(int xCoord, int yCoord, string tileString);
    
    //set row on existing board (for file I/O)
    void readRow(string row);
    
    //check if a board position is valid, that is, it does not contain a wall or an existing tile
    bool isBoardPositionValid(char yCoord, int xCoord);
    
    //accept Y Coordinate string and return integer of the same value (ie, A-->0, B-->1,...,Z-->25)
    int yCoordToInt(string yCoordString);
    
private:
    //board vector, holds vectors of strings
    vector<vector<string> > board;
    
    //board size
    int xSize;
    int ySize;
    
    //alphabet vector for tiles and y axis labels
    vector<string> alphabet;
    
};

#endif //APT_A2_BOARD_H
