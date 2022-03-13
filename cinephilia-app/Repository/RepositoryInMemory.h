//
//

#ifndef FINALPROJECT_REPOSITORYINMEMORY_H
#define FINALPROJECT_REPOSITORYINMEMORY_H


#include "Repository.h"
#include "../Domain/Movie.h"
#include "../Domain/Documentary.h"
#include "../Domain/TheatrePlay.h"
#include "../Validators/MovieValidator.h"

class RepositoryInMemory : public Repository {
protected:
    MovieValidator *movieValidator;
    vector<Object *> storage;
public:
    RepositoryInMemory();

    explicit RepositoryInMemory(MovieValidator *movieValidator);

    void add(Object *object) noexcept(false) override;

    void remove(unsigned int givenID) noexcept(false) override;

    void update(unsigned int givenID, double newRating, const string &newDescription) noexcept(false) override;

    unsigned int getSize() override;

    vector<Object *> getAll() override;

    Object *getFrom(unsigned int position) override;

    ~RepositoryInMemory() override = default;

};


#endif //FINALPROJECT_REPOSITORYINMEMORY_H
