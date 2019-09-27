#include "LinkedList.h"
#include <fstream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;

ifstream inputFile;
ofstream outputFile;

string command;
string nodeArgument;

LinkedList* list;

void linkedListTest();
