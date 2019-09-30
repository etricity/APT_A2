#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono> 
#include "Player.h"
#include "LinkedList.h"
#include "FileIO.h"
#include "Board.h"
#include "BoardPosition.h"

#define EXIT_SUCCESS 0

using std::cout;
using std::cin;
using std::endl;
using std::string;

LinkedList* generateBag();

int main(void)
{
	Board *board = new Board(26,26);

    LinkedList* bag = new LinkedList();

    std::vector<Player *> players;

    Player* currentPlayer = nullptr;

    PosVec boardPositions;

    FileIO myFile("test01", false);

    myFile.loadPlayers(players);
    myFile.loadBoard(board, boardPositions);
    myFile.loadBag(bag);
    myFile.loadCurrentPlayer(players, currentPlayer);

    for(int i =0; i<players.size(); i++)
    {
        cout<<players[i]->getName()<<endl<<players[i]->getScore()<<endl<<players[i]->getHand()->toString()<<endl;
    }

    cout<<board->toString()<<endl;

    cout<<currentPlayer->getName()<<endl;

    for(int i =0; i<boardPositions.size(); i++)
    {
        cout<<boardPositions[i]->getX()<<endl<<boardPositions[i]->getY()<<endl;
    }
    

    return EXIT_SUCCESS;
}


