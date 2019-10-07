#include "CustomException.h"

CustomException::CustomException(string message) {
    this->message = message;
}

string CustomException::getMessage() {
    return message;
}
