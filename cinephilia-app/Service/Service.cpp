//
//

#include "Service.h"
#include <algorithm>
#include "../Domain/Movie.h"
#include "../Domain/TheatrePlay.h"
#include "../Domain/Documentary.h"
#include "../Exceptions/GenericException.h"

Service::Service() : repository(nullptr) {}

Service::Service(Repository *repository) : repository(repository) {}

void Service::add(const string &movieType, const string &title, const string &director, const string &genre,
                  double rating, const string &description, const string &leadingActor, int duration,
                  const string &theatreName, const string &streamingService) {

    if (movieType == "Movie") {
        Object *object = new Movie(title, director, genre, rating, description, leadingActor);
        repository->add(object);
    } else if (movieType == "Theatre Play") {
        Object *object = new TheatrePlay(title, director, genre, rating, description, leadingActor, duration,
                                         theatreName);
        repository->add(object);
    } else if (movieType == "Documentary") {
        Object *object = new Documentary(title, director, genre, rating, description, leadingActor, streamingService);
        repository->add(object);
    } else
        throw GenericException("The type of movie belongs to the series: Movie, Theatre Play, Documentary! ");
}

void Service::remove(unsigned int givenID) {
    repository->remove(givenID);
}

void Service::update(unsigned int givenID, double newRating, const string &newDescription) {
    repository->update(givenID, newRating, newDescription);
}

unsigned int Service::getSize() const {
    return repository->getSize();
}

vector<Object *> Service::getAll() {
    return repository->getAll();
}


bool Service::sortKey(Object *piece1, Object *piece2) {
    return ((Movie *) piece1)->getRating() > ((Movie *) piece2)->getRating();
}

vector<Object *> Service::searchFilmographicPiecesWithAGivenTitle(const string &givenTitle) {
    string errors;
    if (givenTitle.empty())
        errors += "Introduce a non-null title!\n";
    vector<Object *> foundPieces;
    for (auto *&object:repository->getAll()) {
        if (((Movie *) object)->getTitle() == givenTitle)
            foundPieces.push_back(object);
    }
    if (foundPieces.empty())
        errors += "There is no movie with the given title!\n";
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw GenericException(copyErrors);
    }
    return foundPieces;
}

vector<Object *> Service::searchFilmographicPiecesWithAGivenGenre(const string &givenGenre) {
    string errors;
    if (givenGenre != "Drama" && givenGenre != "Psychological Thriller" && givenGenre != "History" &&
        givenGenre != "Film Noir" && givenGenre != "Romance" && givenGenre != "War")
        errors += "The genre should belong to the next series [Drama, Psychological Thriller, "
                  "History, Film Noir, Romance, War]!\n";
    vector<Object *> foundPieces;
    for (auto *&object:repository->getAll()) {
        if (((Movie *) object)->getGenre() == givenGenre)
            foundPieces.push_back(object);
    }
    if (foundPieces.empty())
        errors += "There is no movie with the given genre!\n";
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw GenericException(copyErrors);
    }
    return foundPieces;
}

vector<Object *> Service::searchFilmographicPiecesWithAGivenLeadingActor(const string &givenLeadingActor) {
    string errors;
    bool wrongCharacter = false;
    for (char ch:givenLeadingActor)
        if (!isalpha(ch) && !isspace(ch)) {
            wrongCharacter = true;
            break;
        }
    if (wrongCharacter || givenLeadingActor.empty())
        errors += "Introduce a valid name for the leading actor!\n";
    vector<Object *> foundPieces;
    for (auto *&object:repository->getAll()) {
        if (((Movie *) object)->getLeadingActor() == givenLeadingActor)
            foundPieces.push_back(object);
    }
    if (foundPieces.empty())
        errors += "There is no movie with the given leading actor!\n";
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw GenericException(copyErrors);
    }
    return foundPieces;
}

vector<Object *> Service::createARankingOfFilmographicPieces() {
    vector<Object *> all = repository->getAll();
    sort(all.begin(), all.end(), sortKey);
    return all;
}

void Service::filterFilmographicPiecesWithAGivenGenre(const string &givenGenre) {
    string errors;
    if (givenGenre != "Drama" && givenGenre != "Psychological Thriller" && givenGenre != "History" &&
        givenGenre != "Film Noir" && givenGenre != "Romance" && givenGenre != "War")
        errors += "The genre should belong to the next series [Drama, Psychological Thriller, "
                  "History, Film Noir, Romance, War]!\n";
    if (!errors.empty()) {
        if (!errors.empty()) {
            throw GenericException(errors);
        }
    }
    bool remover = false;
    for (auto *&object:repository->getAll()) {
        if (((Movie *) object)->getGenre() != givenGenre) {
            remover = true;
            repository->remove(((Movie *) object)->getID());
        }
    }
    if (!remover)
        errors += "There is no movie with the given genre!\n";
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw GenericException(copyErrors);
    }
}

void Service::filterFilmographicPieceswithAratingGreaterThanAGivenOne(double givenRating) {
    string errors;
    if (givenRating < 0 || givenRating > 10)
        errors += "The rating should be in the range [0-10]!\n";
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw GenericException(copyErrors);
    }
    for (auto *&object:repository->getAll()) {
        if (((Movie *) object)->getRating() <= givenRating) {
            repository->remove(((Movie *) object)->getID());
        }
    }
}

Object *Service::getFrom(unsigned int position) {
    return repository->getFrom(position);
}

Service::~Service() = default;


