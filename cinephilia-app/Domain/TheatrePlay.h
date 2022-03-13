//
//

#ifndef FINALPROJECT_THEATREPLAY_H
#define FINALPROJECT_THEATREPLAY_H


#include "Movie.h"

class TheatrePlay : public Movie {
private:
    int duration;
    string theatreName;
public:
    TheatrePlay();

    TheatrePlay(const string &title, const string &director, const string &genre, double rating,
                const string &description,
                const string &leadingActor, int duration, const string &theatreName);

    ~TheatrePlay() override = default;

    string toString() override;

    int getDuration() const;

    string getTheatreName() const;

    void setDuration(int newDuration);

    void setTheatreName(const string &newTheatreName);


};


#endif //FINALPROJECT_THEATREPLAY_H
