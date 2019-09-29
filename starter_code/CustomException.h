#ifndef CUSTOM_EXCEPTION_H
#define CUSTOM_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>
using std::string;

class CustomException : public std::exception {
public:
    CustomException(string message);
    string getMessage();
    
private:
    string message;
};

#endif
