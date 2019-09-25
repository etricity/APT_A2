#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono> 
#include "Player.h"
#include "LinkedList.h"
#include "FileIO.h"
#include "Board.h"

#define EXIT_SUCCESS 0

using std::cout;
using std::cin;
using std::endl;
using std::string;

LinkedList* generateBag();

int main(void)
{
	Board *board = new Board(26,26);

    LinkedList* bag = generateBag();

    std::vector<Player *> players;
    players.push_back(new Player("Shrey Parekh"));
    players.push_back(new Player("Jack Swallow"));
    players.push_back(new Player("Andrew Ellis"));

    Player* current = players[2];

    FileIO myFile("test01", true);
    myFile.save(players, board, bag, current);

    return EXIT_SUCCESS;
}

LinkedList* generateBag() 
{
    
    //Valid colours & shapes for tiles
    Colour colours[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    Shape shapes[6] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};
    
    //Creating all the tiles into a vector<Tile>
    std::vector<Tile*> tilesInBag;
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
