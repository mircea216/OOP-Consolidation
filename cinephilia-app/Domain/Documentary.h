//
//

#ifndef FINALPROJECT_DOCUMENTARY_H
#define FINALPROJECT_DOCUMENTARY_H


#include "Movie.h"

class Documentary : public Movie {
private:
    string streamingService;
public:
    Documentary();

    Documentary(const string &title, const string &director, const string &genre, double rating,
                const string &description,
                const string &leadingActor, const string &streamingService);

    ~Documentary() override = default;

    string toString() override;

    string getStreamingService() const;

    void setStreamingService(const string &newStreamingService);


};


#endif //FINALPROJECT_DOCUMENTARY_H
