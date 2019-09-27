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
	void savePlayers(const std::vector<Player *> & players);
	void saveBoard(Board* board);
	void saveBag(LinkedList* bag);
	void saveCurrentPlayer(Player* current);

	// std::vector<Player *> loadPlayers();
	// std::vector< std:vector<string> > loadBoard();   
	// LinkedList* loadBag();
	// Player* loadCurrentPlayer();

	bool checkFile();
	void closeFile();

private:
	ifstream inputFile;
    ofstream outputFile;
};

#endif
