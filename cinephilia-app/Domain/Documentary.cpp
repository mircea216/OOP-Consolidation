//
//

#include "Documentary.h"

Documentary::Documentary() : Movie() {}

Documentary::Documentary(const string &title, const string &director, const string &genre, double rating,
                         const string &description, const string &leadingActor, const string &streamingService) : Movie(
        title, director, genre, rating, description, leadingActor) {
    this->streamingService = streamingService;
}

string Documentary::toString() {
    return Movie::toString() + "\nSTREAMING SERVICE: " + streamingService;
}

string Documentary::getStreamingService() const {
    return streamingService;
}

void Documentary::setStreamingService(const string &newStreamingService) {
    streamingService = newStreamingService;
}

