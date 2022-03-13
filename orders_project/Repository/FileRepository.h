//
//

#ifndef LABORATORY09_10_FILEREPOSITORY_H
#define LABORATORY09_10_FILEREPOSITORY_H


#include "Repository.h"
#include <fstream>
#include <istream>
#include <string>

using namespace std;

class FileRepository : public Repository {
private:
    string fileName;

    void saveTofile();

    void loadFromFile();

    static bool isEmpty(ifstream &pFile);


public:
    FileRepository() = default;

    explicit FileRepository(const string &fileName);

    ~FileRepository() override = default;

    void add(Order &order) override;

    void remove(unsigned int givenCode) override;

    void update(unsigned int givenCode, int newTime) override;

    unsigned int getSize() const override;

    Order getFrom(unsigned int position) override;

    vector<Order> getAll() override;

    string getFileName() const;

    void doClear();

};


#endif //LABORATORY09_10_FILEREPOSITORY_H
