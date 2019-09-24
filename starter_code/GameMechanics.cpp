#include "GameMechanics.h"
#include <stdexcept>

#define     COORD_SIZE   2
#define     COORD_POST   1
#define     COORD_NEG    -1
#define     QWIRKLE      6

/*
 Check if the position is available for placement,
 Check if the given tile matches neighbour tiles,
 Check if the tile does not already exist in a full line
 */
bool GameMechanics::checkPosition(Tile newTile, PosPtr newPos, PosVec list){
    bool response = false;
    bool posAvail = true;
    //Checks to see if the position is available
    for(PosPtr i : list){
        if(newPos->getX() == i->getX() &&
           newPos->getY() == i->getY()) {
            posAvail = false;
        }
    }
    if(posAvail && canTileBePlaced(newTile, newPos, list)){
        response = true;
    }
    return response;
}

bool GameMechanics::isQwirkle(Tile newTile, PosPtr newPos, PosVec list){
    bool response = false;
    bool canBePlaced = false;

    if(checkPosition(newTile, newPos, list)) {
        canBePlaced = true;
    }

    for(PosPtr checkPos : list){
        if(areTilesNeighbours(newPos, checkPos)
           && !isTileTheSame(newTile, checkPos->getTile()) ) {

            PosVec tempList = getTilesInRow(newPos, checkPos, list);

            if (canBePlaced && tempList.size() == QWIRKLE-1 && !doesTileExistInLine(newTile, newPos, list)) {
                response = true;
            }
            tempList.clear();
        }
    }
    return response;
};
//int GameMechanics::getPoints(Tile newTile, PosPtr newPos, PosVec list);

bool GameMechanics::areTilesNeighbours(PosPtr newPos, PosPtr checkPos){
    if(newPos == nullptr || checkPos == nullptr){throw std::runtime_error("A tile is set to nullptr");}
    bool response = false;
    //posDif assists checking all permutations of possible neighbouring tiles
    int posDif[COORD_SIZE] = {COORD_POST,COORD_NEG};
    for(int i : posDif){
        for(int k : posDif){
            if(newPos->getX()+i == checkPos->getX()
               && newPos->getY()+k == checkPos->getY()){
                response = true;
            }
        }
    }
    return response;
}
bool GameMechanics::doTilesMatchColour(Tile newTile, Tile checkTile){
    bool response = false;
    if(newTile.getColour() == checkTile.getColour()){
        response = true;
    }
    return response;
}
bool GameMechanics::doTilesMatchShape(Tile newTile, Tile checkTile){
    bool response = false;
    if(newTile.getShape() == checkTile.getShape()){
        response = true;
    }
    return response;
}

bool GameMechanics::isTileTheSame(Tile newTile, Tile checkTile){
    bool response = false;
    if(doTilesMatchColour(newTile, checkTile)
     && doTilesMatchShape(newTile, checkTile)){
        response = true;
    }
    return response;
}
bool GameMechanics::doesTileExistInLine(Tile checkTile, PosPtr newPos, PosVec list){
    bool response = false;
    bool itExists = false;

    for(PosPtr pos: list){
        if(areTilesNeighbours(newPos, pos)
         && !isTileTheSame(checkTile, pos->getTile()) ){

            //Call a method that creates a list of all tiles in a single line
            PosVec tempList = getTilesInRow(newPos, pos, list);

            for(PosPtr temp : tempList){
                if(isTileTheSame(checkTile, temp->getTile())){
                    itExists = true;
                }
                if(!doTilesMatchColour(checkTile, temp->getTile())
                && !doTilesMatchShape(checkTile, temp->getTile())){
                    itExists = true;
                }
            }
            if(tempList.size() > 6){throw std::runtime_error("You can not have more than 6 tiles in a row");}
            tempList.clear();
        }
    }
    if(itExists){
        response = true;
    }
    return response;
    }

PosVec GameMechanics::getTilesInRow(PosPtr newPos, PosPtr checkPos, PosVec list){
    PosVec tempList;
    //Finds the linear regression of the connections
    int x = checkPos->getX() - newPos->getX();
    int y = checkPos->getY() - newPos->getY();
    tempList.push_back(checkPos);

    bool searchExhausted = false;
    do {
        searchExhausted = true;
        for (PosPtr row: list) {
            if (row->getX() == tempList.back()->getX() + x
                && row->getY() == tempList.back()->getY() + y) {
                tempList.push_back(row);
                searchExhausted = false;
            }
        }
    }while(!searchExhausted);
    return tempList;
}

bool GameMechanics::canTileBePlaced(Tile newTile, PosPtr newPos, PosVec list){
    bool response = false;
    bool sameNeighbour = false;
    //posDif assists checking all
    for(PosPtr pos : list){
        if(areTilesNeighbours(newPos, pos)
            && ( doTilesMatchColour(newTile, pos->getTile())
            ||   doTilesMatchShape(newTile, pos->getTile()) )){
            response = true;
        }
        //This variation checks that a tile can not be placed next to a tile of exact-type
        if(areTilesNeighbours(newPos, pos)
           && doTilesMatchColour(newTile, pos->getTile())
            && doTilesMatchShape(newTile, pos->getTile()) ){
            sameNeighbour = true;
        }
    }
    if(sameNeighbour || doesTileExistInLine(newTile, newPos, list)){
        response = false;
    }
    return response;
}
