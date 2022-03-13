//
//

#ifndef FINALPROJECT_OBJECT_H
#define FINALPROJECT_OBJECT_H
#define CONSTANT 0.0000001

#include <string>
#include <iostream>

using namespace std;

class Object {
public:
    virtual string toString() = 0;

    virtual ~Object() = default;

};


#endif //FINALPROJECT_OBJECT_H
