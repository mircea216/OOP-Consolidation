//
//

#ifndef FINALPROJECT_REPOSITORY_H
#define FINALPROJECT_REPOSITORY_H

#include "../Domain/Object.h"
#include <vector>

using namespace std;

class Repository {
public:
    virtual void add(Object *object) = 0;

    virtual void remove(unsigned int givenID) = 0;

    virtual void update(unsigned int givenID, double newRating, const string &newDescription) = 0;

    virtual vector<Object *> getAll() = 0;

    virtual unsigned int getSize() = 0;

    virtual Object *getFrom(unsigned int position) = 0;

    virtual ~Repository() = default;

};


#endif //FINALPROJECT_REPOSITORY_H
