//
//

#include "Movie.h"

unsigned int Movie::counter = 0;

Movie::Movie() : ID(0), rating(0.0) {
}

Movie::Movie(const string &title, const string &director, const string &genre, double rating, const string &description,
             const string &leadingActor) {
    counter++;
    ID = counter;
    this->title = title;
    this->director = director;
    this->genre = genre;
    this->rating = rating;
    this->description = description;
    this->leadingActor = leadingActor;
}

string Movie::toString() {
    return "ID: " + to_string(ID) + " / TITLE: " + title + " / DIRECTOR: " + director + " / GENRE: " + genre +
           " / RATING: " + to_string(rating).substr(0, to_string(rating).find('.') + 2)
           + " \nDESCRIPTION: " + description + "\nLEADING ACTOR: " + leadingActor;
}

unsigned int Movie::getID() const {
    return ID;
}

string Movie::getTitle() const {
    return title;
}

string Movie::getDirector() const {
    return director;
}

string Movie::getGenre() const {
    return genre;
}

double Movie::getRating() const {
    return rating;
}

string Movie::getDescription() const {
    return description;
}

string Movie::getLeadingActor() const {
    return leadingActor;
}

void Movie::setTitle(const string &newTitle) {
    title = newTitle;
}

void Movie::setGenre(const string &newGenre) {
    genre = newGenre;
}

void Movie::setDirector(const string &newDirector) {
    director = newDirector;
}

void Movie::setRating(double newRating) {
    rating = newRating;
}

void Movie::setDescription(const string &newDescription) {
    description = newDescription;
}

void Movie::setLeadingActor(const string &newLeadingActor) {
    leadingActor = newLeadingActor;
}

