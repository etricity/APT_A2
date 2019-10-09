#ifndef CUSTOM_EXCEPTION_H
#define CUSTOM_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>
using std::string;

/*
 * Simple custom exception to allow custom error messages to be presented to the user
 */

class CustomException : public std::exception {
public:
    CustomException(string message);
    string getMessage();
    
private:
    string message;
};

#endif
