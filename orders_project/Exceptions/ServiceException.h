//
//

#ifndef LABORATORY09_10_SERVICEEXCEPTION_H
#define LABORATORY09_10_SERVICEEXCEPTION_H

#include <stdexcept>

using namespace std;

class ServiceException : public runtime_error {
private:
    const char *message;
public:
    explicit ServiceException(const char *message);

    const char *what();

    ~ServiceException() override = default;

};


#endif //LABORATORY09_10_SERVICEEXCEPTION_H
