#include "Board.h"

//constructor
//will not function as expected if given xSize > 99 or ySize > 26
//no validation provided to prevent this
Board::Board(int xSize, int ySize){
    this->xSize = xSize;
    this->ySize = ySize;
    
    //fill alphabet vector
    for(char c = 'A'; c <= 'Z'; ++c){
        string s(1, c);
        alphabet.emplace_back(s);
    }
    
    initBoard();
}

//initialise the board
void Board::initBoard(){
    
    //initial row containers
    
    //numerical x coordinate labels
    vector <string> rowOne;
    //top and bottom board borders
    vector <string> borderRow;
    
    //fill initial rows
    for(int i = 0;i<xSize;i++){
        string row1;
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
        
        string border;
        if(i==0){
            border = "  --";
        }else{
            border = "---";
        }
        borderRow.emplace_back(border);
    }
    
    //the creation of the board
    
    //x axis labels
    board.emplace_back(rowOne);
    //top border
    board.emplace_back(borderRow);
    for(int i=0;i<ySize;i++){
        vector <string> row;
        for(int j = 0;j<xSize;j++){
            //add y axis label
            if(j==0){
                row.emplace_back(alphabet[i]);
            }
            //two alternating pattern pieces
            string p1 = " | ";
            string p2 = "   ";
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
    //bottom border
    board.emplace_back(borderRow);
}

//toString entire board
string Board::toString(){
    std::ostringstream oss;
    
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board [i].size();j++) {
            oss << board[i][j];
        }
        oss<<std::endl;
    }
    
    string boardString = oss.str();
    return boardString;
}

//add a tile (provides no validation, invalid coords (eg (1,1)/(1,A)) must not be passed)
void Board::addTile(int xCoord, int yCoord, string tileString){
    
    //add whitespace to make up the correct three character column width
    std::string newTile = " " + tileString;
    
    //compensate for board edges
    board[yCoord+2][xCoord+1]= newTile;
    
    
}

//to be called when a board is loaded in
//accepts a string that represents an entire row in an existing board
//passed row strings must be of the same length as the ones in the current board
void Board:: readRow(string row){
    
    //find row's y coordinate by reading the first character
    int yCoordInt;
    string yCoordString(1, row.at(0));
    yCoordInt = yCoordToInt(yCoordString);
    
    
    //set vector positions
    
    //substrings of length 3 are created from the string
    //each substring represents one position in the vector
    int bound = 1;
    for(int i = 0; i<xSize;i++){
        string temp = row.substr(bound,3);
        board[yCoordInt+2][i+1]= temp;
        bound+=3;
    }
}

//check if a board position is empty ("   "), and can have a tile placed
bool Board::isBoardPositionValid(char yCoord, int xCoord){
    string yCoordString(1, yCoord);
    int yCoordInt = yCoordToInt(yCoordString);
    if(board[yCoordInt+2][xCoord+1]=="   "){
        return true;
    }else{
        return false;
    }
}

//accept Y Coordinate string and return integer of the same value (ie, A-->0, B-->1,...,Z-->25)
int Board::yCoordToInt(string yCoordString){
    for(int i = 0;i<alphabet.size();i++){
        if(alphabet[i]==yCoordString){
            return i;
        }
    }
    //if incorrect value is passed, return -1
    return -1;
}
