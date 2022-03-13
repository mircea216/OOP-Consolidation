//
//

#ifndef FINALPROJECT_MOVIEVALIDATOR_H
#define FINALPROJECT_MOVIEVALIDATOR_H


#include "../Domain/Object.h"
#include "../Domain/Movie.h"

class MovieValidator {
protected:
    string errors;
public:
    MovieValidator() = default;

    virtual void validate(Object *movie) noexcept(false);

    virtual ~MovieValidator() = default;
};


#endif //FINALPROJECT_MOVIEVALIDATOR_H
