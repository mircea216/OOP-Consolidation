//
//

#ifndef FINALPROJECT_SERVICE_H
#define FINALPROJECT_SERVICE_H


#include "../Repository/Repository.h"

class Service {
private:
    Repository *repository;
public:
    Service();

    explicit Service(Repository *repository);

    ~Service();

    void add(const string &movieType, const string &title, const string &director, const string &genre, double rating,
             const string &description, const string &leadingActor, int duration, const string &theatreName,
             const string &streamingService) noexcept(false);

    void remove(unsigned int givenID) noexcept(false);

    void update(unsigned int givenID, double newRating, const string &newDescription) noexcept(false);

    vector<Object *> searchFilmographicPiecesWithAGivenTitle(const string &givenTitle) noexcept(false);

    vector<Object *> searchFilmographicPiecesWithAGivenGenre(const string &givenGenre) noexcept(false);

    vector<Object *> searchFilmographicPiecesWithAGivenLeadingActor(const string &givenLeadingActor) noexcept(false);

    void filterFilmographicPiecesWithAGivenGenre(const string &givenGenre) noexcept(false);

    void filterFilmographicPieceswithAratingGreaterThanAGivenOne(double givenRating) noexcept(false);

    vector<Object *> createARankingOfFilmographicPieces();

    unsigned int getSize() const;

    static bool sortKey(Object *piece1, Object *piece2);

    vector<Object *> getAll();

    Object *getFrom(unsigned int position);


};


#endif //FINALPROJECT_SERVICE_H
