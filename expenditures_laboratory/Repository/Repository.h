//
//

#ifndef LAB_07_REPOSITORY_H
#define LAB_07_REPOSITORY_H


#include "../Domain/Expenditure.h"

class Repository {
private:
    int dimension;
    Expenditure *storage = new Expenditure[100];
public:
    Repository();

    Repository(const Repository &repository);

    Repository &operator=(const Repository &repository);

    ~Repository();

    void addExpenditure(Expenditure &expenditure);

    void insertExpenditure(Expenditure &expenditure, int position);

    void deleteExpenditure(Expenditure &expenditure);

    void updateExpenditure(Expenditure &oldExpenditure, Expenditure &newExpenditure);

    int getSize() const;

    Expenditure *getAll();

    Expenditure getExpenditure(int position);

    void release();

};


#endif //LAB_07_REPOSITORY_H
