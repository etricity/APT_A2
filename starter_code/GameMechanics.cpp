//
// Created by Andrew Ellis on 2019-09-21.
//

#include "GameMechanics.h"

#define     COORD_SIZE   2
#define     COORD_POST   1
#define     COORD_NEG    -1

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
    PosVec tempList;

    for(PosPtr pos: list){
        if(areTilesNeighbours(newPos, pos)
         && !isTileTheSame(checkTile, pos->getTile()) ){
            //Finds the linear regression of the connections
            int x = pos->getX() - newPos->getX();
            int y = pos->getY() - newPos->getY();
            tempList.push_back(pos);

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

bool GameMechanics::canTileBePlaced(Tile newTile, PosPtr newPos, PosVec list){
    bool response = false;
    bool sameNeighbour = false;
    //posDif assists checking all
    int posDif[COORD_SIZE] = {COORD_POST,COORD_NEG};
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
