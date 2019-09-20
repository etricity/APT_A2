#include "qwirkle.h"

int main(void) {
    LinkedList* list = new LinkedList();
    list->add_back(new Node(new Tile(GREEN, CIRCLE), nullptr));
    list->remove(GREEN, CIRCLE);
    delete list;

    //TODO Menu Interface
    cout << endl<< "Welcome to Qwirkle!" << endl;
           cout << "-------------------" << endl << endl;
    
    while(userInput != "4")
    {
        userInput = "";
        printMenu();
        cout << "> ";
        cin >> userInput;
        
        if(cin.eof()) {
            userInput = "4";
        }
        
        if(userInput == "1") {
            newGame();
        } else if(userInput == "2") {
            loadGame();
        } else if(userInput == "3") {
            showInfo();
        } else if(userInput == "4") {
            cout << "Goodbye!" << endl << endl;;
        } else {
            cout << "Invalid Input" << endl;
        }
    }
    
    return EXIT_SUCCESS;
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
    cout << "Starting a New Game" << endl << endl;
    
    //Allow user to create new players
    
    cout << "Enter the number of players (Max Players: 4)" << endl;
    cin >> userInput;
    
    int numPlayers = std::stoi(userInput);
    for(int i = 0; i < numPlayers; i++) {
        cout << "Enter a name for player " << i + 1 << " (uppercase characters only)" << endl;
        cout << "<";
        cin >> userInput;
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
        players.push_back(new Player(userInput));
    }
    
    cout << endl << "Let's Play" << endl;
    
    //Create new qwirkle game
        //Create bag
    bag = generateBag();

        //Fill player hands from bag
    
        //Create board
    
    
        /*Show all details
            - names of players
            - scores of players
            - board
            - current player hand
            - user prompt
         */
    
    //Proceed to gameplay
}

void loadGame() {
     cout << "Loading game...." << endl;
    
    //Let user enter filename
    
    //Check that file exists
    
    //Check format of file is correct
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
    
    //Addingg the remaining tiles to the Bag (all times - firstTile)
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
