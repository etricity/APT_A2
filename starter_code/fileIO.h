#include "LinkedList.h"
#include "Player.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

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
	// void load(qwirkle* game);
	// void loadPlayers(qwirkle* game);
	// void loadBoard(qwirkle* game);   
	// void loadBag(qwirkle* game);
	// void loadCurrentPlayer(qwirkle* game);

private:
	ifstream file;
	ofstream myFile;
};

