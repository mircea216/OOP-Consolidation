//
//

#ifndef FINALPROJECT_MOVIE_H
#define FINALPROJECT_MOVIE_H


#include "Object.h"

class Movie : public Object {
protected:
    static unsigned int counter;
    unsigned int ID;
    string title;
    string director;
    string genre;
    double rating;
    string description;
    string leadingActor;
public:
    Movie();

    Movie(const string &title, const string &director, const string &genre, double rating, const string &description,
          const string &leadingActor);

    ~Movie() override = default;

    string toString() override;

    unsigned int getID() const;

    string getTitle() const;

    string getDirector() const;

    string getGenre() const;

    double getRating() const;

    string getDescription() const;

    string getLeadingActor() const;

    void setTitle(const string &newTitle);

    void setDirector(const string &newDirector);

    void setGenre(const string &newGenre);

    void setRating(double newRating);

    void setDescription(const string &newDescription);

    void setLeadingActor(const string &newLeadingActor);

};


#endif //FINALPROJECT_MOVIE_H
