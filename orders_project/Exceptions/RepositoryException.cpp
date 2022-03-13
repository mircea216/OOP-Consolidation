//
//

#include "RepositoryException.h"

RepositoryException::RepositoryException(const char *message) : runtime_error(message), message(message) {

}

const char *RepositoryException::what() {
    return message;
}

