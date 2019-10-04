#include "FileIO.h"

FileIO::FileIO(string filename, bool save)
{
    if(save)
    {
        outputFile.open(filename+".save");
    }
    else
    {
       inputFile.open(filename+".save");
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
    return "Game Successfully Saved\n";
}

void FileIO::savePlayers(const std::vector<Player *> & players)
{
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
    outputFile << board->toString();
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


void FileIO::loadPlayers(std::vector<Player *> & players)
{
    cout << "Loading Players..." << endl;
    bool exit = false;
    int noPlayers = 0;
    string lineContents = "";
    while(!exit && !inputFile.eof())
    {
        int i = 0;
        while(!exit && i<3)
        {
            std::getline(inputFile, lineContents);
            if(lineContents.empty())
            {
                exit=true;
            }
            else
            {
                if(i==0)
                {
                    std::transform(lineContents.begin(), lineContents.end(), lineContents.begin(), ::toupper);
                       players.push_back(new Player(lineContents));
                }
                else if(i==1)
                {
                    players[noPlayers]->addToScore(std::stoi(lineContents));
                }
                else
                {
                    int stringLength = lineContents.size();
                    int x=0;
                    int j=1;
                    char colour;
                    int shape = 0;
                    while(x<stringLength)
                    {
                        colour = lineContents[x];
                        shape = std::stoi(lineContents.substr(j,1));
                        players[noPlayers]->getHand()->add_back(new Node(new Tile(colour, shape), nullptr));
                        x=x+4;
                        j=j+4;
                    }
                    noPlayers++;
                }
                i++;
                if(i>2)
                {
                    i=0;
                }
            }
        }
    }
}


void FileIO::loadBoard(Board* board, PosVec & boardPositions)
{
    cout << "Loading Board..." << endl;
    bool exit = false;
    string lineContents = "";
    for(int i=0; i<2; i++)
    {
        std::getline(inputFile, lineContents);
    }
    while(!exit && !inputFile.eof())
    {
        std::getline(inputFile, lineContents);
        if(lineContents[2]=='-')
        {
            std::getline(inputFile, lineContents);
        }
        if(lineContents.empty())
        {
            exit=true;
        }
        else
        {
            board->readRow(lineContents);
            int yCoord = lineContents[0] - 'A' + 1;
            int xCoord = 0;
            int index = 1;
            int shape = 0;
            while(index<lineContents.size())
            {
                string temp = lineContents.substr(index, 3);
                char letter = temp[1];
                   if(letter>='A' && letter<='Z')
                   {
                       shape = std::stoi(temp.substr(2,1));
                       PosPtr position = new BoardPosition(xCoord,yCoord - 1);
                       position->setTile(new Tile(letter,shape));
                       boardPositions.push_back(position);
                   }
                   xCoord++;
                   index = index + 3;
               }
        }
    }
}

void FileIO::loadBag(LinkedList* bag)
{
    cout << "Loading bag..." << endl;
    bool exit = false;
    string lineContents = "";
    while(!exit && !inputFile.eof())
    {
        std::getline(inputFile, lineContents);
        if(lineContents.empty())
        {
            exit=true;
        }
        else
        {
            int stringLength = lineContents.size();
            int x=0;
            int j=1;
            char colour;
            int shape = 0;
            while(x<stringLength)
            {
                colour = lineContents[x];
                shape = std::stoi(lineContents.substr(j,1));
                bag->add_back(new Node(new Tile(colour, shape), nullptr));
                x=x+4;
                j=j+4;
            }
        }
    }
}

Player* FileIO::loadCurrentPlayer(std::vector<Player *> & players, Player* currentPlayer)
{
    cout << "Loading current player..." << endl;
    bool exit = false;
    string lineContents = "";
    while(!exit && !inputFile.eof())
    {
        std::getline(inputFile, lineContents);
        std::transform(lineContents.begin(), lineContents.end(), lineContents.begin(), ::toupper);
        if(lineContents.empty())
        {
            exit=true;
        }
        else
        {
            for(int i=0; i<players.size(); i++)
            {
                if(players[i]->getName()==lineContents)
                {
                    currentPlayer = players[i];
                }
            }
        }
    }
    return currentPlayer;
}
