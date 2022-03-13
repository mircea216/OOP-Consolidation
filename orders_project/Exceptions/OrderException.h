//
//

#ifndef LABORATORY09_10_ORDEREXCEPTION_H
#define LABORATORY09_10_ORDEREXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class OrderException : public exception {
private:
    string message;
public:
    OrderException() = default;

    explicit OrderException(const string &message);

    const char *what();

    ~OrderException() override = default;

};


#endif //LABORATORY09_10_ORDEREXCEPTION_H
