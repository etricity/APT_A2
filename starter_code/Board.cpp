#include "Board.h"

Board::Board(int xSize, int ySize){
    this->xSize = xSize;
    this->ySize = ySize;
    initBoard();
}

Board::~Board(){

}

void Board::initBoard(){

    // The initial row containers:
    std::vector <std::string> rowOne;
    std::vector <std::string> rowTwo;

// The creation of the initial rows:
    for(int i = 0;i<xSize;i++){
        std::string row1;
        if(i==0){
            rowOne.emplace_back(" ");
        }
        if(i<10) {
            row1 = " " + std::to_string(i) + " ";
        }else{
            row1 = " " + std::to_string(i);
        }
        rowOne.emplace_back(row1);

        std::string row2;
        if(i==0){
            row2 = "  --";
        }else{
            row2 = "---";
        }
        rowTwo.emplace_back(row2);
    }

// The creation of the board.
    board.emplace_back(rowOne);
    board.emplace_back(rowTwo);
    for(int i=0;i<ySize;i++){
        std::vector <std::string> row;
        std::string alphabet[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        for(int j = 0;j<xSize;j++){
            if(j==0){
                row.emplace_back(alphabet[i]);
            }
            std::string p1 = " | ";
            std::string p2 = "   ";
            if(i%2==0){
                if(j%2==0) {
                    row.emplace_back(p1);
                }else{
                    row.emplace_back(p2);
                }
            }else{
                if(j%2==0) {
                    row.emplace_back(p2);
                }else{
                    row.emplace_back(p1);
                }
            }
        }
        board.emplace_back(row);
    }
    board.emplace_back(rowTwo);

// Print the board
    print();
}

void Board::print(){
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board [i].size();j++) {
            std::cout<<board[i][j];
        }

        std::cout<<std::endl;
    }
}

void Board::addTile(int xCoord, int yCoord
//        , Tile tile
        ){
    //tile.getCode() or similar to get tile code as a string
    //use a dummy string for now
    std::string tileCode = "R2";
    std::string newTile = " " + tileCode;
    board[yCoord+2][xCoord+1]= newTile;

    std::cout<<std::endl;
    print();
}
