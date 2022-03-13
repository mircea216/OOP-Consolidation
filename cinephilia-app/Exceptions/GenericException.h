//
//

#ifndef FINALPROJECT_GENERICEXCEPTION_H
#define FINALPROJECT_GENERICEXCEPTION_H

#include <string>

using namespace std;

class GenericException {
private:
    string message;
public:
    explicit GenericException(const string &message);

    string what() const;

    ~GenericException() = default;
};


#endif //FINALPROJECT_GENERICEXCEPTION_H
