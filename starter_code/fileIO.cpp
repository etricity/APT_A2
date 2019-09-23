#include "FileIO.h"

FileIO::FileIO(string filename, bool save)
{
    outputFile.open("saveData.txt");
}

FileIO::~FileIO()
{
    outputFile.close();
}

string FileIO::save(std::vector<Player *> & players, std::vector< std::vector<char> > & board, LinkedList* bag, int current)
{
	savePlayers(players, current);
	saveBoard(board);
	saveBag(bag);
	return "Game Successfully Saved";
}

void FileIO::savePlayers(const std::vector<Player *> & players, int current)
{
	for(int i=0; i<players.size() ; i++)
	{
        outputFile<<players[i]->getName() << ":" << players[i]->getScore()
        << ":" << players[i]->getHand()->toString();
	}
    outputFile<<players[current]->getName() << endl;
}

void FileIO::saveBoard(const std::vector< std::vector<char> > & board)
{
	for (int i = 0; i < board.size(); i++) 
	{ 
        for (int j = 0; j < board[i].size(); j++) 
        {
        outputFile <<board[i][j];
        }
        outputFile<<endl;
    }
    outputFile << "-----BAG TO BE SAVED HERE-----" << endl;
    outputFile<<endl;
}

void FileIO::saveBag(LinkedList* bag)
{
	outputFile<<bag->toString();
	outputFile<<endl;
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
