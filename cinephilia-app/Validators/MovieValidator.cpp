//
//

#include "MovieValidator.h"
#include "../Exceptions/GenericException.h"

void MovieValidator::validate(Object *object) noexcept(false) {
    if (((Movie *) object)->getTitle().empty())
        errors += "Introduce a non-null title!\n";
    bool wrongCharacter = false;
    for (char ch:((Movie *) object)->getDirector())
        if (isdigit(ch)) {
            wrongCharacter = true;
            break;
        }

    if (((Movie *) object)->getDirector().empty() || wrongCharacter)
        errors += "Introduce a valid name for the director of the fimographic piece!\n";


    if (((Movie *) object)->getGenre() != "Drama" && ((Movie *) object)->getGenre() != "Psychological Thriller" &&
        ((Movie *) object)->getGenre() != "History" && ((Movie *) object)->getGenre() != "Film Noir" &&
        ((Movie *) object)->getGenre() != "Romance" && ((Movie *) object)->getGenre() != "War")
        errors += "The genre should belong to the next series [Drama, Psychological Thriller, "
                  "History, Film Noir, Romance, War]!\n";

    if (((Movie *) object)->getRating() < 0 || ((Movie *) object)->getRating() > 10)
        errors += "The rating should be in the range [0-10]!\n";
    wrongCharacter = false;
    for (char ch:((Movie *) object)->getDescription())
        if (isdigit(ch)) {
            wrongCharacter = true;
            break;
        }

    if (wrongCharacter || ((Movie *) object)->getDescription().empty())
        errors += "Introduce a valid description!\n";
    wrongCharacter = false;
    for (char ch:((Movie *) object)->getLeadingActor())
        if (!isalpha(ch) && !isspace(ch)) {
            wrongCharacter = true;
            break;
        }

    if (wrongCharacter || ((Movie *) object)->getLeadingActor().empty())
        errors += "Introduce a valid name for the leading actor!\n";
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw GenericException(copyErrors);
    }

}