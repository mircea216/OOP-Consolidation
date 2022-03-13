//
//

#include "ServiceException.h"

ServiceException::ServiceException(const char *message) : runtime_error(message), message(message) {}

const char *ServiceException::what() {
    return message;
}