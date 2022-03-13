//
//

#include "GenericException.h"

GenericException::GenericException(const string &message) {
    this->message = message;
}

string GenericException::what() const {
    return message;
}