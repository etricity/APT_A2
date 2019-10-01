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

    FileIO myFile("test02", false);
  	bool check =  myFile.checkFile();

    myFile.loadPlayers(players);
    for(int i =0; i<players.size(); i++)
    {
        cout<<players[i]->getName()<<endl<<players[i]->getScore()<<endl<<players[i]->getHand()->toString()<<endl;
    }
    myFile.loadBoard(board, boardPositions);
    myFile.loadBag(bag);

    currentPlayer = myFile.loadCurrentPlayer(players, currentPlayer);

    cout<<board->toString();

    for(int i =0; i<boardPositions.size(); i++)
    {
        cout<<boardPositions[i]->getX()<<boardPositions[i]->getY()<<endl;
    }

    cout<<bag->toString()<<endl;

    cout<<currentPlayer->getName()<<endl;

 
    

    return EXIT_SUCCESS;
}


