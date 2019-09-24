#ifndef APT_A2_BOARD_H
#define APT_A2_BOARD_H

#endif //APT_A2_BOARD_H

#include "TileCodes.h"
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

private:

 //   std::vector<std::vector<std::string> > vec;

    int xSize;
    int ySize;


};
