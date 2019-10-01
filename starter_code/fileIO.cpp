#include "fileIO.h"

FileIO::FileIO(string filename, bool save)
{
    if(save)
    {
        outputFile.open(filename+".save");
    }
    else
    {
        inputFile.open(filename);
    }   
}

FileIO::~FileIO()
{
   
}

bool FileIO::checkFile()
{
    if(inputFile.is_open())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void FileIO::closeFile()
{
    inputFile.close();
}

string FileIO::save(std::vector<Player *> & players, Board* board, LinkedList* bag, Player* current)
{
	savePlayers(players);
	saveBoard(board);
	saveBag(bag);
    saveCurrentPlayer(current);
    outputFile.close();
	return "Game Successfully Saved";
}

void FileIO::savePlayers(const std::vector<Player *> & players)
{
    //Number of players
    outputFile << players.size() << endl;
    //Player info
	for(int i=0; i<players.size() ; i++)
	{
        outputFile<<players[i]->getName() << endl << players[i]->getScore()
        << endl << players[i]->getHand()->toString();
	}
    outputFile<< endl;
}

//This will need to be refactored to use Board Class, not a vector<vector<string>>
void FileIO::saveBoard(Board* board)
{
    outputFile << board->print();
    outputFile<<endl;
}

void FileIO::saveBag(LinkedList* bag)
{
	outputFile<<bag->toString();
    outputFile<<endl;
}

void FileIO::saveCurrentPlayer(Player* current)
{
    //current player
    outputFile<<current->getName();
}

// void FileIO::load(qwirkle* game)
// {
// 	if(file.is_open())
// 	{
// 		loadPlayers();
// 		loadBoard();
// 		loadBag();
// 		loadCurrentPlayer();
// 	}
// 	else
// 	{
// 		throw std::runtime_error("Sorry file does not exist, please try again.");
// 	}
// 	file.close();
// }

// void FileIO::loadPlayers(qwirkle* game)
// {
// 	bool exit = false;
// 	while(!exit && !file.eof())
// 	{
// 		int i = 0;
// 		while(!exit && i<3)
// 		{

// 		}
// 		string lineContents = "";
// 		std::getline(file, lineContents);
// 		std::istringstream iss(lineContents);
// 		char* cArray = new char [lineContents.size()+1];
// 		strcpy(cArray, lineContents.c_str());
// 		if(cArray[0]==" ")
// 		{
// 			exit=true;
// 		}

// 	}
// }

// void FileIO::loadBoard(qwirkle* game)
// {
// 	bool exit = false;
// 	string lineContents = "";
// 	while(!exit && !file.eof())
// 	{
// 		std::getline(file, lineContents);
// 		if(lineContents.empty())
// 		{
// 			exit=true;
// 		}
// 		else
// 		{
// 			game->setBoard(lineContents);
// 		}
// 	}
// }

// void FileIO::loadBag(qwirkle* game)
// {
// 	bool exit = false;
// 	string lineContents = "";
// 	while(!exit && !file.eof())
// 	{
// 		std::getline(file, lineContents);
// 		if(lineContents.empty())
// 		{
// 			exit=true;
// 		}
// 		else 
// 		{
// 			game->setBag(lineContents);
// 		}
// 	}

// }
// void FileIO::loadCurrentPlayer(qwirkle* game)
// {
// 	bool exit = false;
// 	string lineContents = "";
// 	while(!exit && !file.eof())
// 	{
// 		std::getline(file, lineContents);
// 		if(lineContents.empty())
// 		{
// 			exit=true;
// 		}
// 		else
// 		{
// 			game->setCurrentPlayer(lineContents);
// 		}
// 	}
// }
