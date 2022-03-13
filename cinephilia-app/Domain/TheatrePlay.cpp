//
//

#include "TheatrePlay.h"

TheatrePlay::TheatrePlay() : Movie(), duration(0) {}

TheatrePlay::TheatrePlay(const string &title, const string &director, const string &genre, double rating,
                         const string &description, const string &leadingActor, int duration,
                         const string &theatreName) : Movie(title, director, genre, rating, description, leadingActor) {
    this->duration = duration;
    this->theatreName = theatreName;
}

string TheatrePlay::toString() {
    return Movie::toString() + "\nDURATION: " + to_string(duration) + " / THEATRE NAME: " + theatreName;
}

int TheatrePlay::getDuration() const {
    return duration;
}

string TheatrePlay::getTheatreName() const {
    return theatreName;
}

void TheatrePlay::setDuration(int newDuration) {
    duration = newDuration;
}

void TheatrePlay::setTheatreName(const string &newTheatreName) {
    theatreName = newTheatreName;
}

