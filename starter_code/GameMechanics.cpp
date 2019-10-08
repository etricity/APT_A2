#include "GameMechanics.h"
#include <stdexcept>

#define     COORD_SIZE   2
#define     COORD_POST   1
#define     COORD_NEG    -1
#define     QWIRKLE      6
#define     BOARD_R_MAX  26-1
#define     BOARD_C_MAX  26-1

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
    if(numberOfQwirkles(newTile, newPos, list) > 0){
        response = true;
    }
    return response;
}

int GameMechanics::getPoints(Tile newTile, PosPtr newPos, PosVec list){
    int points = 0;

    if(checkPosition(newTile, newPos, list)){
        for(PosPtr checkPos : list){
            if(areTilesNeighbours(newPos, checkPos)
               && !isTileTheSame(newTile, checkPos->getTile())) {

                PosVec tempList = getTilesInRow(newPos, checkPos, list);
                //The +1 is to account for the tile being placed
                points += tempList.size()+1;
            }
        }
    }
    //Counts the number of possible Qwikles and multiplies by 6

    points += numberOfQwirkles(newTile, newPos, list) * QWIRKLE;

    return points;
}

PosPtr GameMechanics::getHint(LinkedList* playerBag, PosVec board) {
    PosPtr bestPosition = nullptr;
    PosPtr checkPos = nullptr;
    //Points of current bestPosition
    int points = 0;
    //Setup for checking all surrounding positions of a given BoardPosition
    int posDif[COORD_SIZE] = {COORD_POST,COORD_NEG};

    Node* currHead = playerBag->getHead();

    while(currHead != nullptr){
        Tile* currTile = currHead->tile;
        bool legalMove = false;

        //Iterates through all placed BoardPositions that have been previously authenticated
        for(PosPtr pos: board){
            //Check over all permutations that would surround the given BoardPosition
            for(int i : posDif){
                for(int k : posDif){
                    //checkPos is a possible position created from surrounding coordinates of current
                    //index of BoardPositions in the BoardPositions list -> board
                    checkPos = new BoardPosition(pos->getX()+i, pos->getY()+k);

                    //Check that the tile can not be placed in a line already established as 6
                    PosVec tempList = getTilesInRow(checkPos, pos, board);
                    if(tempList.size() < QWIRKLE){
                        legalMove = true;
                    }

                    //Validation to check that created position does not escape the bounds of the game board
                    if(legalMove && checkPos->getX() >= 0 && checkPos->getY() >= 0
                       && checkPosition(*currTile, checkPos, board)){

                        //Checks if previous possibility of placement is a better result in placement
                        if(getPoints(*currTile, checkPos, board) > points){

                            if(bestPosition == nullptr && isPoistionInBounds(checkPos)){
                                bestPosition = new BoardPosition(*checkPos);
                                points = getPoints(*currTile, checkPos, board);
                                bestPosition->setTile(currTile);
                            }
                            else if(bestPosition != nullptr && isPoistionInBounds(checkPos)){
                                bestPosition = new BoardPosition(*checkPos);
                                points = getPoints(*currTile, checkPos, board);
                                bestPosition->setTile(currTile);
                            }
                        }
                    }
                    delete checkPos;
                }
            }
        }
        currHead = currHead->next;
    }
    if(bestPosition == nullptr){
        throw CustomException("There are no available positions for your hand, please replace a tile");
    }
    return bestPosition;
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
//Looks for all tiles in a laid line
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
bool GameMechanics::isPoistionInBounds(PosPtr pos){
    bool response = true;
    if(pos->getX() > BOARD_R_MAX || pos->getX() < 0
        || pos->getY() > BOARD_C_MAX || pos->getY() < 0){
        response = false;
    }
    return response;
}

//Get the total amount of tiles in a legal laid down row
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

//Check the possible row for any repeats of the same tile
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
int GameMechanics::numberOfQwirkles(Tile newTile, PosPtr newPos, PosVec list){
    int count = 0;
    bool canBePlaced = false;

    if(checkPosition(newTile, newPos, list)) {
        canBePlaced = true;
    }
    for(PosPtr checkPos : list){
        if(areTilesNeighbours(newPos, checkPos)
           && !isTileTheSame(newTile, checkPos->getTile()) ) {

            PosVec tempList = getTilesInRow(newPos, checkPos, list);

            if (canBePlaced && tempList.size() == QWIRKLE-1) {
                count++;
            }
            tempList.clear();
        }
    }
    return count;
}
