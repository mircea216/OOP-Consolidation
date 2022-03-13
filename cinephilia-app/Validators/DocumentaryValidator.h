//
//

#ifndef FINALPROJECT_DOCUMENTARYVALIDATOR_H
#define FINALPROJECT_DOCUMENTARYVALIDATOR_H


#include "../Domain/Documentary.h"
#include "MovieValidator.h"

class DocumentaryValidator : public MovieValidator {
public:
    DocumentaryValidator() = default;

    void validate(Object *object) noexcept(false) override;

    ~DocumentaryValidator() override = default;

};


#endif //FINALPROJECT_DOCUMENTARYVALIDATOR_H
