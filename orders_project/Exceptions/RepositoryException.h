//
//

#ifndef LABORATORY09_10_REPOSITORYEXCEPTION_H
#define LABORATORY09_10_REPOSITORYEXCEPTION_H

#include <stdexcept>

using namespace std;

class RepositoryException : public runtime_error {
private:
    const char *message{};
public:

    explicit RepositoryException(const char *message);

    const char *what();

    ~RepositoryException() override = default;


};


#endif //LABORATORY09_10_REPOSITORYEXCEPTION_H
