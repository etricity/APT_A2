#include "fileIO.h"

fileIO::fileIO(string filename, bool save)
{
	if(save)
	{
		myFile.open(filename+".save");
	}
	else
	{
		file.open(filename);
	}	
}

fileIO::~fileIO()
{

}

string fileIO::save(std::vector<Player *> & players, std::vector< std::vector<string> > & board, LinkedList* bag, int current)
{
	savePlayers(players);
	saveBoard(board);
	saveBag(bag);
	saveCurrentPlayer(players, current);
	myFile.close();
	return "Game Successfully Saved";
}

void fileIO::savePlayers(const std::vector<Player *> & players)
{
	for(int i=0; i<players.size() ; i++)
	{
		myFile<<players[i]->getName()<<endl;
		myFile<<players[i]->getScore()<<endl;
		myFile<<players[i]->getHand()->toString()<<endl;
	}
	myFile<<endl;
}

void fileIO::saveBoard(const std::vector< std::vector<string> > & board)
{
	for (int i = 0; i < board.size(); i++) 
	{ 
        for (int j = 0; j < board[i].size(); j++) 
        {
            myFile<<board[i][j]; 
        }
        myFile<<endl; 
    } 
    myFile<<endl;
}

void fileIO::saveBag(LinkedList* bag)
{
	myFile<<bag->toString();
	myFile<<endl;
}

void fileIO::saveCurrentPlayer(const std::vector<Player *> & players, int current)
{
	myFile<<players[current]->getName();
}

// void fileIO::load(qwirkle* game)
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

// void fileIO::loadPlayers(qwirkle* game)
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

// void fileIO::loadBoard(qwirkle* game)
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

// void fileIO::loadBag(qwirkle* game)
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
// void fileIO::loadCurrentPlayer(qwirkle* game)
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