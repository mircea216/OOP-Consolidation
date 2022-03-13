//
//

#include "OrderException.h"

OrderException::OrderException(const string &message) {
    this->message = message;
}

const char *OrderException::what() {
    return message.c_str();
}