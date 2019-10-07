#ifndef FILEIO_H
#define FILEIO_H
#include "LinkedList.h"
#include "Player.h"
#include "Board.h"
#include "BoardPosition.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

    Player* load(std::vector<Player *> & players, Board* board, PosVec & boardPositions, LinkedList* bag, Player* current);
    void loadPlayers(std::vector<Player *> & players);
    void loadBoard(Board* board, PosVec & boardPositions);
    void loadBag(LinkedList* bag);
    Player* loadCurrentPlayer(std::vector<Player *> & players, Player* current);
    
    bool checkFile();
    void closeFile();
    
private:
    ifstream inputFile;
    ofstream outputFile;
};

#endif
