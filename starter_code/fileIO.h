#include "LinkedList.h"
#include "Player.h"
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;

class fileIO {
public: 
	fileIO(string filename, bool save);
	~fileIO();
	string save(std::vector<Player *> & players, std::vector< std::vector<string> > & board, LinkedList* bag, int current);
	void savePlayers(const std::vector<Player *> & players);
	void saveBoard(const std::vector< std::vector<string> > & board);
	void saveBag(LinkedList* bag);
	void saveCurrentPlayer(const std::vector<Player *> & players, int current);
	// std::vector<Player *> loadPlayers();
	// std::vector< std:vector<string> > loadBoard();   
	// LinkedList* loadBag();
	// int loadCurrentPlayer();
	bool checkFile();
	void closeFile();

private:
	ifstream file;
	ofstream myFile;
};

