#include "TestScript.h"

int main(int argc, char** argv) {
    
    //argv[1] = inputFile
    list = new LinkedList();
    command = "";
    
    inputFile.open(argv[1]);
    outputFile.open("script_output.out");
    
    
    while(inputFile >> command) {
        
        if(command == "push_back") {
            inputFile >> nodeArgument;
            char colour = nodeArgument[0];
            int shape = std::stoi(nodeArgument.substr(1,1));
            
            list->add_back(new Node(new Tile(colour, shape), nullptr));
            
        } else if(command == "remove_front") {
            list->remove_front();
        } else if(command == "remove") {
            inputFile >> nodeArgument;
            char colour = nodeArgument[0];
            int shape = std::stoi(nodeArgument.substr(1,1));
            
            list->remove(colour, shape);
        } else if(command == "size") {
            outputFile << list->size() << endl;
        }
    }
    cout << list->toString();
    outputFile << list->toString();
    outputFile.close();
    
    return 0;
}
