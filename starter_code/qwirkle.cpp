#include "qwirkle.h"

int main(void) {
    
    cout << endl<< "Welcome to Qwirkle!" << endl;
    cout << "-------------------" << endl;
    
    //board and bag must be initlised here to be used if loadGame() is called
    board = new Board(26,26);
    bag = new LinkedList();
    
    //Continue to display menu & ask for input until a valid command is entered
    do {
        try {
            printMenu();
            promptUserInput();
            valid = validator.validateMenuInput(userInput);
            
            if(userInput == "1") {
                newGame();
                gamePlay();
            } else if(userInput == "2") {
                loadGame();
                gamePlay();
            } else if(userInput == "3") {
                showInfo();
                //allows user to go back to menu
                valid = false;
            } else if(userInput == "4") {
                quit();
            }
            
        } catch(CustomException e) {
            cout << e.getMessage() << endl;
            valid = false;
        }
    } while(!valid);
    
    return EXIT_SUCCESS;
}

void promptUserInput() {
    cout << "> ";
    cin >> userInput;
    cout << endl;
    
    if(cin.eof()) {
        quit();
    }
}


void promptUserInput_WholeLine() {
    cout << "> ";
    std::getline(cin, userInput);
    cout << endl;
    
    if(cin.eof()) {
        quit();
    }
}

void printMenu() {
    cout << endl << "Menu"<< endl;
    cout << "----"<< endl;
    
    cout << "1. New Game" << endl;
    cout << "2. Load Game"<< endl;
    cout << "3. Show student infomation" << endl;
    cout << "4. Quit" << endl << endl;
}

void newGame() {
    currentPlayer = nullptr;
    cout << "Starting a New Game" << endl << endl;
    
    
    cout << "Enter the number of players (Max Players: 4)" << endl;
    
    do {
        try {
            promptUserInput();
            valid = validator.validateNumPlayers(userInput);
        } catch(CustomException e) {
            cout << e.getMessage() << endl;
            valid = false;
        }
    } while(!valid);
    
    int numPlayers = std::stoi(userInput);
    for(int i = 0; i < numPlayers; i++) {
        cout << "Enter a name for player " << i + 1 << " (uppercase characters only)" << endl;
        promptUserInput();
        
        //Removes remaining '\n' in cin buffer
        cin.ignore(1, '\n');
        
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
        players.push_back(new Player(userInput));
    }
    
    cout << "Let's Play" << endl;
    
    //Create new qwirkle game
    //prevents memmory leak if loadGame was NOT called
    delete bag;
    //Create bag
    bag = generateBag();
    
    //Fill player hands from bag
    for(Player* p: players) {
        
        for(int i = 0; i < 6; i++) {
            p->getHand()->add_back(new Node(*bag->getHead()));
            bag->remove_front();
        }
    }
    
}

void saveGame()
{
    string filename = userInput.substr(userInput.find(" ") + 1);
    FileIO myFile(filename, true);
    cout<<myFile.save(players, board, bag, currentPlayer)<<endl;
}

void loadGame() 
{
    cout<<"Please enter a filename"<<endl;
    promptUserInput();
    FileIO myFile (userInput, false);
    if(myFile.checkFile())
    {
        cout << "Loading Game...." << endl;
        currentPlayer = myFile.load(players, board, boardPositions, bag, currentPlayer);
        myFile.closeFile();

        cout << "Game Succesfully Loaded" << endl << endl;
        cin.ignore(1);
    }
    else
    {
        throw CustomException("Sorry file does not exist.");
    }
}

void showInfo() {
    cout << "Showing student info...." << endl;
    
    //Print all students in group info
    cout << "Name: Isaiah Cuzzupe" << endl;
    cout << "Student ID: s3743803" << endl;
    cout << "Email: s3743803@student.rmit.edu.au" << endl << endl;
    
    cout << "Name: Jack Swallow" << endl;
    cout << "Student ID: s3541003" << endl;
    cout << "Email: s3541003@student.rmit.edu.au" << endl << endl;
    
    cout << "Name: Shrey Parekh" << endl;
    cout << "Student ID: s3710669" << endl;
    cout << "Email: s3710669@student.rmit.edu.au" << endl << endl;
    
    cout << "Name: Andrew Ellis" << endl;
    cout << "Student ID: s3747746" << endl;
    cout << "Email: s3747746@student.rmit.edu.au" << endl << endl;
}

LinkedList* generateBag() {
    
    //Valid colours & shapes for tiles
    Colour colours[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    Shape shapes[6] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};
    
    //Creating all the tiles into a vector<Tile>
    vector<Tile*> tilesInBag;
    Tile * newTile = nullptr;
    for(int i = 1; i <= 2; i++) {
        
        for(int j = 0; j < sizeof(colours)/sizeof(*colours); j++) {
            
            for(int x = 0; x < sizeof(shapes)/sizeof(*shapes); x++) {
                
                newTile = new Tile(colours[j], shapes[x]);
                tilesInBag.push_back(newTile);
            }
        }
    }
    
    //Shuffling up the vector<Tile>
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(tilesInBag.begin(), tilesInBag.end(), std::default_random_engine(seed));
    
    //Creating the bag
    LinkedList* bag = new LinkedList();
    
    //Adding the head to the Bag
    Node* newNode = new Node(tilesInBag.front(), nullptr);
    bag->add_back(newNode);
    
    //Adding the remaining tiles to the Bag (all times - firstTile)
    for(int i = 1; i < tilesInBag.size(); i++)
    {
        newNode = new Node(tilesInBag.at(i), nullptr);
        bag->add_back(newNode);
    }
    
    return bag;
}

//Loops which alternates through player turns until someone wins or gameplay is saved/quit
void gamePlay() {
    //If a currentPlayer has not been loaded in
    if(currentPlayer == nullptr) {
        currentPlayer = players[0];
    }
    
    bool endGame = false;
    while(!endGame) {
        
        
        //Always the gameplay to begin at the turn of the currentPlayer
        std::vector<Player*>::iterator it = std::find(players.begin(), players.end(), currentPlayer);
        int beginningTurn = std::distance(players.begin(), it);
        
        for(int i = beginningTurn; i < players.size(); i++) {
            currentPlayer = players[i];
            //Current player
            cout << endl << currentPlayer->getName() << "'s turn." << endl;
            //Printing scores of all players
            for(Player* p: players) {
                cout << p->getName() << " score: " << p->getScore() << endl;
            }
            //Printing board
            cout << board->toString() << endl;
            //Current player's hand
            cout << "Your hand is..." << endl;
            cout << currentPlayer->getHand()->toString();
            
            //Player takes an action
            
            //Getting userInput
            do {
                try {
                    promptUserInput_WholeLine();
                    valid = validator.validateCommand(userInput, currentPlayer, board, players, bag, boardPositions);
                    
                    
                    //1. Places a tile on the board
                    std::istringstream oss(userInput);
                    string action = "";
                    string tileString = "";
                    oss >> action;
                    
                    if(action == "place") {
                        
                        //Tile info to be placed (ie 'R6')
                        oss >> tileString;
                        //ignores word "at"
                        oss.ignore(256,'t');
                        //Co-ordinates for tile to be added to board
                        string position = "";
                        oss >> position;
                        
                        int yPos = alphToNum(position[0]);
                        int xPos = std::stoi(position.substr(1));
                        
                        
                        PosPtr newBP = new BoardPosition(xPos,yPos);
                        Tile* tileFromHand = currentPlayer->getHand()->getNode(tileString[0], tileString[1] - '0')->tile;
                        
                        if(boardPositions.size() > 0) {
                            if(gameMechanics.checkPosition(*tileFromHand, newBP, boardPositions)) {
                                
                                //Checking for a qwirkle
                                if(gameMechanics.isQwirkle(*tileFromHand, newBP, boardPositions)) {
                                    cout << endl << "QWIRKLE!!!" << endl;;
                                }
                                
                                
                                int points = gameMechanics.getPoints(*tileFromHand, newBP, boardPositions);
                                currentPlayer->addToScore(points);
                                newBP->setTile(tileFromHand);
                                boardPositions.push_back(newBP);
                                board->addTile(xPos, yPos, tileString);
                                
                                
                            } else {
                                throw CustomException("Invalid Tile placement.");
                            }
                        } else {
                            currentPlayer->addToScore(1);
                            newBP->setTile(tileFromHand);
                            boardPositions.push_back(newBP);
                            board->addTile(xPos, yPos, tileString);
                            
                        }
                        currentPlayer->getHand()->remove(tileString[0], tileString[1] - '0');
                        //Adds head of bag to back of hand
                        
                        if(bag->size() > 0) {
                            currentPlayer->getHand()->add_back(new Node(*bag->getHead()));
                            bag->remove_front();
                        }
                        
                    } else if (action == "replace") {
                        
                        //Tile info to be placed (ie 'R6')
                        oss >> tileString;
                        char colour = tileString[0];
                        int shape = std::stoi(tileString.substr(1,1));
                        
                        //Puts tile from Player hand to bag
                        Node* nodeToReplace = currentPlayer->getHand()->remove(colour, shape);
                        bag->add_back(new Node(*nodeToReplace));
                        delete nodeToReplace;
                        //Adds head of bag to back of hand
                        currentPlayer->getHand()->add_back(new Node(*bag->getHead()));
                        bag->remove_front();
                        
                    } else if (action == "save") {
                        saveGame();
                        i--;
                    } else if(action == "help") {
                        showCommands();
                        i--;
                    } else if (action == "quit") {
                        quit();
                    } else if (action == "hint") {
                        PosPtr hint = gameMechanics.getHint(currentPlayer->getHand(), boardPositions);
                        char row = 'A' + hint->getY();
                        cout << "Try placing a tile at: " << row << hint->getX() << endl;
                        i--;
                    } else if (action == "forfeit") {
                        players.erase(std::remove(players.begin(), players.end(), currentPlayer), players.end());
                        cout << currentPlayer->getName() << " removed from play." << endl;
                        delete currentPlayer;
                        i--;
                    } else if (action == "pass") {
                        cout << currentPlayer->getName() << " passed turn." << endl;
                    }
                } catch(CustomException e) {
                    cout << e.getMessage() << endl;
                    valid = false;
                } catch(std::invalid_argument e) {
                    cout << "Invalid Board Position" << endl;
                    valid = false;
                }
            } while(!valid);
        }
        
        currentPlayer = players[0];
        
        endGame = checkEndGameConditions();
    }
    
    displayEndGameInfo();
    
}

int alphToNum(char letter) {
    vector<char> alphabet;
    for(char c = 'A'; c <= 'Z'; ++c){
        alphabet.emplace_back(c);
    }
    
    int yCoordInt;
    for(int i = 0;i<alphabet.size();i++){
        if(alphabet[i] == letter){
            yCoordInt = i;
        }
    }
    return yCoordInt;
}

bool checkEndGameConditions() {
    
    bool emptyPlayerHand = false;
    bool emptyBag = false;
    
    bool endGame = false;
    
    if(bag->size() == 0) {
        emptyBag = true;
    }
    
    int i = 0;
    while(i < players.size() && !emptyPlayerHand) {
        
        if(players[i]->getHand()->size() == 0) {
            emptyPlayerHand = true;
        }
        
        i++;
    }
    
    if(emptyPlayerHand && emptyBag) {
        endGame = true;
    }
    return endGame;
    
}

void showCommands() {
    cout << "Player Actions:" << endl
    << "1. place <tile> at <position>" << endl
    << "2. replace <tile>" << endl
    << "3. pass" << endl
    << "4. save <filename>" << endl
    << "5. quit" << endl
    << "6. help" << endl << endl;
}

void displayEndGameInfo() {
    
    cout << endl << "Game over" << endl;
    
    for(Player* p : players) {
        cout << "Score for " << p->getName() << ": " << p->getScore() << endl;
    }
    
    cout << calculateWinner()->getName() << " won!" << endl;
    quit();
    
}

Player* calculateWinner() {
    
    Player* playerWithHighScore = players[0];
    
    for(int i = 1; i < players.size(); i++) {
        if(players[i]->getScore() > playerWithHighScore->getScore()) {
            playerWithHighScore = players[i];
        }
    }
    
    return playerWithHighScore;
    
}

void quit() {
    cout << "Goodbye!" << endl;
    clear();
    exit(0);
}

//Clean up all memmory
void clear() {
    delete bag;
    delete board;
    
    for(Player* p: players) {
        delete p;
    }
    
    for(PosPtr bp: boardPositions) {
        delete bp;
    }
}
