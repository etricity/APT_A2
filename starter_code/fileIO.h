#ifndef FILEIO_H
#define FILEIO_H
#include "LinkedList.h"
#include "Player.h"
#include "Board.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;

class FileIO {
public: 
	FileIO(string filename, bool save);
	~FileIO();
	string save(std::vector<Player *> & players, Board* board, LinkedList* bag, Player* current);
	void savePlayers(const std::vector<Player *> & players, Player* current);
	void saveBoard(Board* board);
	void saveBag(LinkedList* bag);

	// void load(qwirkle* game);
	// void loadPlayers(qwirkle* game);
	// void loadBoard(qwirkle* game);   
	// void loadBag(qwirkle* game);
	// void loadCurrentPlayer(qwirkle* game);

private:
	ifstream inputFile;
    ofstream outputFile;
};

#endif
