#ifndef ASSIGNMENT02_GAMEMECHANICS_H
#define ASSIGNMENT02_GAMEMECHANICS_H

#include "Tile.h"
#include "BoardPosition.h"
#include "LinkedList.h"
#include "CustomException.h"
#include <vector>
#include <stdexcept>

/*
 * GameMechanics has three main components
 * 1) Check that move is legal if not the class will return a bool false
 * 2) Checks if given move is a Qwirkle, will return a boolean
 * 3) Checks for all possible points made from move, will return as an int
 *
 * Requirements
 */

class GameMechanics {

public:
    bool checkPosition(Tile newTile, PosPtr newPos, PosVec list);
    bool isQwirkle(Tile newTile, PosPtr newPos, PosVec list);
    int getPoints(Tile newTile, PosPtr newPos, PosVec list);
    /* Andrew Ellis - First Enhancement - Hints
     *
     * Given the player's current tile bag and current board positions
     * the method returns the PosPtr that points to the Tile/ Board position
     * that will get the player the highest possible score.
     */
    PosPtr getHint(LinkedList* playerBag, PosVec board);

private:
    bool areTilesNeighbours(PosPtr newPos, PosPtr checkPos);
    bool doTilesMatchColour(Tile newTile, Tile oldTile);
    bool doTilesMatchShape(Tile newTile, Tile checkTile);
    bool isTileTheSame(Tile newTile, Tile checkTile);
    bool doesTileExistInLine(Tile checkTile, PosPtr newPos, PosVec list);
    bool isPoistionInBounds(PosPtr pos);

    PosVec getTilesInRow(PosPtr newPos, PosPtr checkPos, PosVec list);

    bool canTileBePlaced(Tile newTile, PosPtr newPos, PosVec list);

    int numberOfQwirkles(Tile newTile, PosPtr newPos, PosVec list);
};

#endif //ASSIGN2_GAMEMECHANICS_H
