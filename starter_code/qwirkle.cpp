#include "qwirkle.h"

int main(void) {
    
    //TODO Menu Interface
    cout << endl<< "Welcome to Qwirkle!" << endl;
    cout << "-------------------" << endl;
    
    do {
        try {
            printMenu();
            promptUserInput();
            valid = validator.validateMenuInput(userInput);
            
            if(userInput == "1") {
                newGame();
            } else if(userInput == "2") {
                loadGame();
            } else if(userInput == "3") {
                showInfo();
                //allows user to go back to menu
                valid = false;
            } else if(userInput == "4") {
                cout << "Goodbye!" << endl << endl;
                exit(0);
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
    
    if(cin.eof()) {
        cout << "Goodbye!" << endl;
        exit(0);
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
    
    //Allow user to create new players
    
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
    cout << endl;
    
    int numPlayers = std::stoi(userInput);
    for(int i = 0; i < numPlayers; i++) {
        cout << "Enter a name for player " << i + 1 << " (uppercase characters only)" << endl;
        cout << "> ";
        cin >> userInput;
        //Removes remaining '\n' in cin buffer
        cin.ignore(1, '\n');
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
        players.push_back(new Player(userInput));
    }
    
    cout << endl << "Let's Play" << endl;
    
//Create new qwirkle game
    //Create bag
    bag = generateBag();

    cout << endl;
    
    //Fill player hands from bag
    for(Player* p: players) {
        
        for(int i = 0; i < 6; i++) {
            p->getHand()->add_back(new Node(*bag->getHead()));
            bag->remove_front();
        }
    }
    
    
    //Generate board
    board = new Board(26,26);
    
    //Initilise GameMechanics Object
//    gameMechanics = new GameMechanics();
    
    //Player turns- gameplay
    gamePlay();
        /*Show all details
            - names of players
            - scores of players
            - board
            - current player hand
            - user prompt
         */
    
    //Proceed to gameplay
}

void saveGame()
{
    string filename = ""; 
    cout<<"Please enter a filename"<<endl;
    cin>>filename;
    FileIO myFile(filename, true);
    cout<<myFile.save(players, board, bag, currentPlayer)<<endl;
}

void loadGame() 
{
    string filename = ""; 
    cout<<"Please enter a filename"<<endl;
    cin>>filename;
    FileIO *myFile = new FileIO(filename, false);
    if(myFile->checkFile())
    {
        cout << "Loading Game...." << endl;
        loadPlayers(myFile);
        loadBoard(myFile);
        loadBag(myFile);
        loadCurrentPlayer(myFile);
        myFile->closeFile();
        cout << "Game Succesfully Loaded" << endl;
    }
    else
    {
        cout<<"Sorry the file does not exist"<<endl;
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
    //Clean-up
    newTile = nullptr;
    newNode = nullptr;
    delete newTile;
    delete newNode;
    
    return bag;
}

//Loops which alternates through player turns until someone wins or gameplay is saved/quit
void gamePlay() {
    
    //If a currentPlayer has not been loaded in
    if(currentPlayer == nullptr) {
        currentPlayer = players[0];
    }
    
    //Always the gameplay to begin at the turn of the currentPlayer
    std::vector<Player*>::iterator it = std::find(players.begin(), players.end(), currentPlayer);
    int beginningTurn = std::distance(players.begin(), it);
    
    for(int i = beginningTurn; i < players.size(); i++) {
        currentPlayer = players[i];
        //Current player
        cout << currentPlayer->getName() << "'s turn." << endl;
        //Printing scores of all players
        for(Player* p: players) {
            cout << p->getName() << " score: " << p->getScore() << endl;
        }
        //Printing board
        cout << board->toString() << endl;
        //Current player's hand
        cout << "Your hand is..." << endl;
        cout << "Bag Size: " << currentPlayer->getHand()->size() << endl;
        cout << currentPlayer->getHand()->toString();
        //Waiting for player input
        cout << "> ";
        
        //Player takes an action
        
        //Getting userInput
        std::getline(cin, userInput);
        
        
        //1. Places a tile on the board
        std::istringstream oss(userInput);
        string action = "";
        string tileString = "";
        oss >> action;
        
        cout << action << endl;
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

            //IF player's hand contains tile matching tileString
            
            if(currentPlayer->getHand()->contains(tileString[0], tileString[1] - '0')) {
                
                //Add tile to board
                    //  EG. addTile(5, D, G3) --> add tile G3 to position D5
                board->addTile(xPos, yPos, tileString);
                
                //Add new BoardPosition to PosVec (maintains a vector of all tiles current on Board)
                Node* node = currentPlayer->getHand()->getNode(tileString[0], tileString[1] - '0');
                
                PosPtr newBP = new BoardPosition(xPos, yPos);
                newBP->setTile(node->tile);
                
                boardPositions.push_back(newBP);
            }
        
            
        } else if (action == "replace") {
            
            //Tile info to be placed (ie 'R6')
            oss >> tileString;
            char colour = tileString[0];
            int shape = std::stoi(tileString.substr(1,1));
            
            //If players hand contains the tile
            if(currentPlayer->getHand()->contains(colour, shape)) {
                //Removes the selected node from the player hand & adds it to back of bag
                bag->add_back(new Node(*currentPlayer->getHand()->remove(colour, shape)));
                //Adds head of bag to back of hand
                currentPlayer->getHand()->add_back(new Node(*bag->getHead()));
                bag->remove_front();
            }

        } else if (action == "save") {
            saveGame();
        } else if (action == "quit") {
            //To be done
            cout << "QUIT..." << endl;
        } else {
            
        }
    }
}

void loadPlayers(FileIO* myFile){
}

void loadBoard(FileIO* myFile){
}

void loadBag(FileIO* myFile){
}

void loadCurrentPlayer(FileIO* myFile){
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
