#include "Board.h"

Board::Board(int xSize, int ySize){
    this->xSize = xSize;
    this->ySize = ySize;
    initBoard();
}

Board::~Board(){

}

//initialise the board
void Board::initBoard(){

    //initial row containers
    //numerical x coordinates
    std::vector <std::string> rowOne;
    //top and bottom board borders
    std::vector <std::string> borderRow;

    //fill initial rows
    for(int i = 0;i<xSize;i++){
        std::string row1;
        if(i==0){
            rowOne.emplace_back(" ");
        }
        //compensate for numbers over 9 using two characters
        if(i<10) {
            row1 = " " + std::to_string(i) + " ";
        }else{
            row1 = " " + std::to_string(i);
        }
        rowOne.emplace_back(row1);

        std::string border;
        if(i==0){
            border = "  --";
        }else{
            border = "---";
        }
        borderRow.emplace_back(border);
    }

    //the creation of the board
    board.emplace_back(rowOne);
    board.emplace_back(borderRow);
    for(int i=0;i<ySize;i++){
        std::vector <std::string> row;
        //alphabet array for y axis
        std::string alphabet[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        for(int j = 0;j<xSize;j++){
            //add y axis identifier
            if(j==0){
                row.emplace_back(alphabet[i]);
            }
            //two alternating pattern pieces
            std::string p1 = " | ";
            std::string p2 = "   ";
            //if row is even, start with pattern 1
            if(i%2==0){
                //alternate between patterns each column
                if(j%2==0) {
                    row.emplace_back(p1);
                }else{
                    row.emplace_back(p2);
                }
                //if row is odd, start with pattern 2
            }else{
                //alternate between patterns each column
                if(j%2==0) {
                    row.emplace_back(p2);
                }else{
                    row.emplace_back(p1);
                }
            }
        }
        board.emplace_back(row);
    }
    board.emplace_back(borderRow);
}

string Board::toString(){

    std::ostringstream oss;
    
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board [i].size();j++) {
            oss << board[i][j];
        }
        oss<<std::endl;
    }
    oss<<std::endl;
    
    string boardString = oss.str();
    return boardString;
}

//add a tile (provides no validation, invalid coords (eg (1,1)/(1,A)) must not be passed)
//tile parameter commented out until I  see the tile code and adapt this function appropriately
//dummy string used for now
<<<<<<< HEAD
void Board::addTile(int xCoord, int yCoord, string tileString){
    //std::string tileCode =tile.getCode(); or similar to get tile code as a string
    //dummy string, all tiles added will be R2
//    std::string tileCode = "R2";
    //add whitespace to make up the correct three character column width
    std::string newTile = " " + tileString;
    
    //compensate for board edges
    board[yCoord+2][xCoord+1]= newTile;

    std::cout << toString();
        
=======
void Board::addTile(int xCoord, int yCoord
//        , Tile tile
        ){
    //std::string tileCode =tile.getCode(); or similar to get tile code as a string
    //dummy string, all tiles added will be R2
    std::string tileCode = "R2";
    //add whitespace to make up the correct three character column width
    std::string newTile = " " + tileCode;
    //compensate for board edges
    board[yCoord+2][xCoord+1]= newTile;

    print();
>>>>>>> development
}
