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
    cout << "Enter a name for player 1 (uppercase characters only)" << endl;
    cout << "<";
    cin >> userInput;
    player1 = new Player(userInput);
    
    cout << endl << "Enter a name for player 2 (uppercase characters only)" << endl;
    cin >> userInput;
    player2 = new Player(userInput);
    
    cout << endl << "Let's Play" << endl;
    
    //Create new qwirkle game
        //Create board
    
        //Fill player hands from bag
    
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
