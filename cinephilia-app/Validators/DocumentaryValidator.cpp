//
//

#include "DocumentaryValidator.h"
#include "../Exceptions/GenericException.h"

void DocumentaryValidator::validate(Object *object) noexcept(false) {
    try {
        MovieValidator::validate(object);
    }
    catch (GenericException &genericException) {
        errors += genericException.what();
    }
    if (((Documentary *) object)->getStreamingService() != "HBO" &&
        ((Documentary *) object)->getStreamingService() != "Netflix" &&
        ((Documentary *) object)->getStreamingService() != "National Geographic" &&
        ((Documentary *) object)->getStreamingService() != "Discovery" &&
        ((Documentary *) object)->getStreamingService() != "ABC")
        errors += "The streaming service should belong to next series [Netflix, HBO, ABC, National Geographic, Discovery]!";
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw GenericException(copyErrors);
    }
}