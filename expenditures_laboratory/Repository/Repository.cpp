//
//

#include "Repository.h"

Repository::Repository() {
    /// default constructor

    dimension = 0;
}

Repository::~Repository() {
    /// desstructor
    dimension = 0;
}

Repository::Repository(const Repository &repository) {
    /// copy constructor
    /// input - const Repository &repository

    this->dimension = repository.dimension;
    for (unsigned int i = 0; i < repository.dimension; i++)
        this->storage[i] = repository.storage[i];
}

Repository &Repository::operator=(const Repository &repository) {
    /// overloads assign operator
    /// input - const Repository &repository

    if (this != &repository) {
        this->dimension = repository.dimension;
        for (int i = 0; i < repository.getSize(); i++) {
            this->storage[i] = repository.storage[i];
        }
    }
    return *this;
}

void Repository::addExpenditure(Expenditure &expenditure) {
    /// adds an expenditure in the storage
    /// input - Expenditure &expenditure - an expenditure to be added in the storage

    storage[dimension++] = expenditure;
}

void Repository::insertExpenditure(Expenditure &expenditure, int position) {
    /// inserts an expenditure in the storage
    /// input - Expenditure &expenditure - an expenditure to be inserted in the storage
    /// input - int position

    if (position >= 0 && position <= dimension) {
        for (int i = dimension - 1; i >= position; i--)
            storage[i + 1] = storage[i];
        storage[position] = expenditure;
        dimension++;
    }
}


void Repository::updateExpenditure(Expenditure &oldExpenditure, Expenditure &newExpenditure) {
    /// updates an expenditure in the storage
    /// input - Expenditure &oldExpenditure - the expenditure to be updatwd
    /// input - Expenditure &newExpenditure - the updated expenditure
    for (int i = 0; i < dimension; i++) {
        if (storage[i] == oldExpenditure)
            storage[i] = newExpenditure;
    }
}

void Repository::deleteExpenditure(Expenditure &expenditure) {
    /// deletes an expenditure of the storage
    /// input - Expenditure &expenditure

    int i, j;
    for (i = 0; i < dimension; i++) {
        if (storage[i] == expenditure) {
            for (j = i; j < dimension - 1; j++)
                storage[j] = storage[j + 1];
            dimension--;
            i--;
        }
    }
}

int Repository::getSize() const {
    /// gets the dimension of the storage
    /// output - dimension

    return dimension;
}

Expenditure *Repository::getAll() {
    /// gets the expenditures in the storage
    /// output - storage

    return storage;
}

Expenditure Repository::getExpenditure(int position) {
    /// gets the entity at a given position
    /// input - int position

    return storage[position];
}

void Repository::release() {
    /// releases the memory

    dimension = 0;
    if (storage) {
        delete[] storage;
        storage = nullptr;
    }
}