//
//

#include "RepositoryInMemory.h"
#include "../Validators/TheatrePlayValidator.h"
#include "../Validators/DocumentaryValidator.h"
#include "../Exceptions/GenericException.h"

RepositoryInMemory::RepositoryInMemory() : movieValidator(nullptr) {}

RepositoryInMemory::RepositoryInMemory(MovieValidator *movieValidator) : movieValidator(movieValidator) {}

void RepositoryInMemory::add(Object *object) {
    if (typeid(*object) == typeid(Movie)) {
        movieValidator = new MovieValidator;
        movieValidator->validate((Movie *) object);
    } else if (typeid(*object) == typeid(TheatrePlay)) {
        movieValidator = new TheatrePlayValidator;
        movieValidator->validate((TheatrePlay *) object);

    } else if (typeid(*object) == typeid(Documentary)) {
        movieValidator = new DocumentaryValidator;
        movieValidator->validate((Documentary *) object);
    }
    storage.push_back(object);
}

void RepositoryInMemory::remove(unsigned int givenID) {
    bool found = false;
    for (unsigned int index = 0; index < storage.size(); index++) {
        if (((Movie *) storage[index])->getID() == givenID || ((TheatrePlay *) storage[index])->getID() == givenID ||
            ((Documentary *) storage[index])->getID() == givenID) {
            found = true;
            storage.erase(storage.begin() + index);
        }
    }
    if (!found)
        throw GenericException("There is no filmographic piece with the given ID!\n");
}

void RepositoryInMemory::update(unsigned int givenID, double newRating, const string &newDescription) {
    string errors;
    bool found = false;
    if (newRating < 0 || newRating > 10)
        errors += "The rating should be in the range [0-10]!\n";

    for (char ch:newDescription)
        if (!isalpha(ch) && !isspace(ch)) {
            errors += "Introduce a valid description!\n";
            break;
        }
    if (newDescription.empty())
        errors += "Introduce a non-null description!\n";
    if (!errors.empty())
        throw GenericException(errors);
    for (auto *&object:storage) {
        if (((Movie *) object)->getID() == givenID) {
            found = true;
            ((Movie *) object)->setRating(newRating);
            ((Movie *) object)->setDescription(newDescription);
        } else if (((TheatrePlay *) object)->getID() == givenID) {
            found = true;
            ((TheatrePlay *) object)->setRating(newRating);
            ((TheatrePlay *) object)->setDescription(newDescription);
        } else if (((Documentary *) object)->getID() == givenID) {
            found = true;
            ((Documentary *) object)->setRating(newRating);
            ((Documentary *) object)->setDescription(newDescription);
        }
    }
    if (!found)
        errors += "There is no filmographic piece with the given ID!\n";
    if (!errors.empty())
        throw GenericException(errors);
}

vector<Object *> RepositoryInMemory::getAll() {
    return storage;
}

unsigned int RepositoryInMemory::getSize() {
    return storage.size();
}

Object *RepositoryInMemory::getFrom(unsigned int position) {
    return storage[position];
}