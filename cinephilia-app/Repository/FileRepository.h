//
//

#ifndef FINALPROJECT_FILEREPOSITORY_H
#define FINALPROJECT_FILEREPOSITORY_H

#include <iostream>
#include <fstream>
#include <istream>
#include "RepositoryInMemory.h"

using namespace std;

class FileRepository : public RepositoryInMemory {
private:
    string fileName;

    void saveTofile();

    void loadFromFile();

    static bool isEmpty(ifstream &pFile);

public:
    FileRepository() = default;

    explicit FileRepository(const string &fileName);

    void add(Object *object) override;

    void remove(unsigned int givenID) override;

    void update(unsigned int givenID, double newRating, const string &newDescription) override;

    unsigned int getSize() override;

    vector<Object *> getAll() override;

    Object *getFrom(unsigned int position) override;

    string getFileName() const;

    void clearFile();

    ~FileRepository() override = default;
};


#endif //FINALPROJECT_FILEREPOSITORY_H
