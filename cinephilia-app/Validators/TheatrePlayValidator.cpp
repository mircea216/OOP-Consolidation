

#include "TheatrePlayValidator.h"
#include "../Exceptions/GenericException.h"

void TheatrePlayValidator::validate(Object *object) {
    try {
        MovieValidator::validate(object);
    }
    catch (GenericException &genericException) {
        errors += genericException.what();
    }
    if (((TheatrePlay *) object)->getDuration() < 2 || ((TheatrePlay *) object)->getDuration() > 4)
        errors += "The duration should be in the range [2-4]!\n";
    if (((TheatrePlay *) object)->getTheatreName().empty())
        errors += "The theatre name cannot be null!\n";
    for (char ch:((TheatrePlay *) object)->getTheatreName())
        if (!isalpha(ch) && !isspace(ch)) {
            errors += "The theatre name should contain valid characters!\n";
            break;
        }
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw GenericException(copyErrors);
    }
}