//
//

#include <cstring>
#include <ctime>
#include "Service.h"

Service::Service(Repository &repository) {
    /// constructor with parameters
    /// input - Repository &repository

    this->repository = repository;
}

Service::Service(const Service &service) {
    /// copy constructor
    /// input - const Service &service

    this->repository = service.repository;
}

Service &Service::operator=(const Service &service) {
    /// overloads the assign operator
    /// input - const Service &service

    if (this != &service) {
        this->repository = service.repository;
    }
    return *this;
}

void Service::addExpenditure(unsigned int sum, const char *type) {
    /// adds an expenditure in the storage
    /// input - unsigned int sum
    /// input - const char *type

    time_t t = time(nullptr);
    tm *now = localtime(&t);
    unsigned int day = now->tm_mday;
    Expenditure expenditure(day, sum, type);
    repository.addExpenditure(expenditure);
}

void Service::insertExpenditure(unsigned int day, unsigned int sum, const char *type, int position) {
    /// inserts an expenditure in the storage at a given position
    /// input - unsigned int day
    /// input - unsigned int sum
    /// input - const char *type
    /// input - int position

    Expenditure expenditure(day, sum, type);
    repository.insertExpenditure(expenditure, position);
}

void Service::updateExpenditure(unsigned int oldDay, unsigned int oldSum, const char *oldType, unsigned int newDay,
                                unsigned int newSum, const char *newType) {
    /// updates an expenditure in the storage at a given position
    /// input - int position
    /// input - unsigned int newDay
    /// input - unsigned int newSum
    /// input - const char *newType
    Expenditure oldExpenditure(oldDay, oldSum, oldType);
    Expenditure newExpenditure(newDay, newSum, newType);
    repository.updateExpenditure(oldExpenditure, newExpenditure);
}

void Service::deleteExpenditure(unsigned int day, unsigned int sum, const char *type) {
    /// deletes an expenditure from a given position of the storage
    /// input - int position
    Expenditure expenditure(day, sum, type);
    repository.deleteExpenditure(expenditure);
}


Repository Service::getAll() {
    /// output - storage
    return this->repository;
}

unsigned int Service::getSize() const {
    /// gets the dimension of the storage
    /// output - dimension

    return repository.getSize();
}

Expenditure Service::getExpenditure(int position) {
    /// gets the entity at a given position
    /// input - int position

    return repository.getExpenditure(position);
}

void Service::release() {
    /// releases the memory

    repository.release();
}


void Service::deleteTheExpendituresOfAGivenDay(unsigned int day) {
    /// deletes the expenditure of a given day
    /// input - unsigned int day

    for (int i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (expenditure.getDay() == day) {
            repository.deleteExpenditure(expenditure);
            i--;
        }
    }
}


void Service::deleteTheExpendituresOfAGivenRangeOfDays(unsigned int startDay, unsigned int endDay) {
    /// deletes the expenditures of a given range of days
    /// input - unsigned int startDay
    /// input - unsigned int endDay

    for (int i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (expenditure.getDay() >= startDay && expenditure.getDay() <= endDay) {
            repository.deleteExpenditure(expenditure);
            i--;
        }
    }
}

void Service::deleteTheExpendituresOfAGivenType(const char *type) {
    /// deletes the expenditures of a given type
    /// input - const char *type

    for (int i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (strcmp(expenditure.getType(), type) == 0) {
            repository.deleteExpenditure(expenditure);
            i--;
        }
    }
}

Expenditure *Service::displayExpendituresOfAGivenType(const char *type, unsigned int &dimension) {
    /// displays the expenditures of a given type
    /// input - const char *type
    /// input - unsigned int &dimension
    /// output - Expenditure* expenditures
    dimension = 0;
    Expenditure *expenditures;
    expenditures = new Expenditure[50];
    for (int i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (strcmp(expenditure.getType(), type) == 0)
            expenditures[dimension++] = expenditure;
    }
    return expenditures;
}

Expenditure *
Service::displayExpendituresOfAGivenTypeWithTheCostGreaterOrEqualThanAGivenOne(const char *type, unsigned int sum,
                                                                               unsigned int &dimension) {
    /// displays the expenditures of a given type and with a cost greater or equal than a given one
    /// input - const char *type
    /// input - unsigned int sum
    /// input - unsigned int &dimension
    /// output - Expenditure* expenditures

    dimension = 0;
    Expenditure *expenditures;
    expenditures = new Expenditure[50];
    for (int i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (strcmp(expenditure.getType(), type) == 0 && expenditure.getSum() >= sum)
            expenditures[dimension++] = expenditure;
    }
    return expenditures;
}


void Service::filterTheExpendituresOfAGivenType(const char *type) {
    /// filters the food expenditures
    /// input - const char *type
    for (int i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (strcmp(expenditure.getType(), type) != 0) {
            repository.deleteExpenditure(expenditure);
            i--;
        }
    }
}

void Service::filterExpendituresOfATypeLesserThanAGivenSum(const char *type, unsigned int sum) {
    /// filters the expenditures of a type lesser than a given sum
    /// input - const char *type
    /// input - unsigned int sum
    /// output - Expenditure *filteredExpenditures

    for (int i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (strcmp(expenditure.getType(), type) != 0 || expenditure.getSum() >= sum) {
            repository.deleteExpenditure(expenditure);
            i--;
        }
    }
}

void Service::filterExpendituresOfATypeGreaterOrEqualThanAGivenSum(const char *type, unsigned int sum) {
    /// filters the expenditures of a type greater or equal than a given sum
    /// input - const char *type
    /// input - unsigned int sum
    /// output - Expenditure *filteredExpenditures

    for (int i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (strcmp(expenditure.getType(), type) != 0 || expenditure.getSum() < sum) {
            repository.deleteExpenditure(expenditure);
            i--;
        }
    }
}

Expenditure *Service::sortExpendituresInAscendingOrderBySum(unsigned int &dimension) {
    /// sorts expenditures in ascending oder by sum
    /// input - unsigned int &dimension
    /// output - Expenditure *sortedExpenditures

    int i, j;
    dimension = 0;
    Expenditure *sortedExpenditures = new Expenditure[50], copy;
    for (i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        sortedExpenditures[dimension++] = expenditure;
    }
    if (dimension) {
        for (i = 0; i < dimension - 1; i++) {
            for (j = i + 1; j < dimension; j++)
                if (sortedExpenditures[i].getSum() > sortedExpenditures[j].getSum()) {
                    copy = sortedExpenditures[i];
                    sortedExpenditures[i] = sortedExpenditures[j];
                    sortedExpenditures[j] = copy;
                }
        }
    }
    return sortedExpenditures;
}

Expenditure *Service::sortExpendituresOfAGivenTypeInDescendingOrderBySum(const char *type, unsigned int &dimension) {
    /// sorts the expenditures of a given type in ascending order by sum
    /// input - const char *type
    /// input - unsigned int &dimension
    /// output - Expenditure *sortedExpenditures

    int i, j;
    dimension = 0;
    Expenditure *sortedExpenditures = new Expenditure[50], copy;
    for (i = 0; i < repository.getSize(); i++) {
        Expenditure expenditure = repository.getExpenditure(i);
        if (strcmp(expenditure.getType(), type) == 0)
            sortedExpenditures[dimension++] = expenditure;
    }
    if (dimension) {
        for (i = 0; i < dimension - 1; i++) {
            for (j = i + 1; j < dimension; j++)
                if (sortedExpenditures[i].getSum() < sortedExpenditures[j].getSum()) {
                    copy = sortedExpenditures[i];
                    sortedExpenditures[i] = sortedExpenditures[j];
                    sortedExpenditures[j] = copy;
                }
        }
    }
    return sortedExpenditures;
}

Expenditure Service::displayTheMostCostlyExpenditure() {
    /// display the most costly expenditure
    /// output - Expenditure maximumExpenditure
    Expenditure *expenditures = repository.getAll(), maximumExpenditure;
    unsigned int maximumSum = 0;
    for (int i = 0; i < repository.getSize(); i++) {
        if (expenditures[i].getSum() > maximumSum) {
            maximumSum = expenditures[i].getSum();
            maximumExpenditure = expenditures[i];
        }
    }
    return maximumExpenditure;
}

unsigned int Service::displayTheTotalCostOfTheExpendituresOfAGivenType(const char *type) {
    /// display the total cost of the expenditures of a given type
    /// input - const char *type
    /// output - unsigned int total

    unsigned int total = 0;
    for (int i = 0; i < repository.getSize(); i++)
        if (strcmp(repository.getExpenditure(i).getType(), type) == 0)
            total += repository.getExpenditure(i).getSum();
    return total;
}

void Service::assingRepositoryForStack(const Repository &repository1) {
    this->repository = repository1;
}