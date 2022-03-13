
#ifndef FINALPROJECT_THEATREPLAYVALIDATOR_H
#define FINALPROJECT_THEATREPLAYVALIDATOR_H


#include "MovieValidator.h"
#include "../Domain/TheatrePlay.h"

class TheatrePlayValidator : public MovieValidator {
public:
    TheatrePlayValidator() = default;

    void validate(Object *object) noexcept(false) override;

    ~TheatrePlayValidator() override = default;


};


#endif //FINALPROJECT_THEATREPLAYVALIDATOR_H
