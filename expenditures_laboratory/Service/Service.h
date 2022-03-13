//
//

#ifndef LAB_07_SERVICE_H
#define LAB_07_SERVICE_H


#include "../Repository/Repository.h"

class Service {
private:
    Repository repository;
public:
    Service() = default;

    Service(const Service &service);

    Service &operator=(const Service &service);

    explicit Service(Repository &repository);

    void assingRepositoryForStack(const Repository &repository1);

    ~Service() = default;

    void addExpenditure(unsigned int sum, const char *type);

    void insertExpenditure(unsigned int day, unsigned int sum, const char *type, int position);

    void deleteExpenditure(unsigned int day, unsigned int sum, const char *type);

    void updateExpenditure(unsigned int oldDay, unsigned int oldSum, const char *oldType, unsigned int newDay,
                           unsigned int newSum, const char *newType);

    unsigned int getSize() const;

    Repository getAll();

    Expenditure getExpenditure(int position);

    void release();

    void deleteTheExpendituresOfAGivenDay(unsigned int day);

    void deleteTheExpendituresOfAGivenRangeOfDays(unsigned int startDay, unsigned int endDay);

    void deleteTheExpendituresOfAGivenType(const char *type);

    Expenditure *displayExpendituresOfAGivenType(const char *type, unsigned int &dimension);

    Expenditure *
    displayExpendituresOfAGivenTypeWithTheCostGreaterOrEqualThanAGivenOne(const char *type, unsigned int sum,
                                                                          unsigned int &dimension);

    void filterTheExpendituresOfAGivenType(const char *type);

    void filterExpendituresOfATypeLesserThanAGivenSum(const char *type, unsigned int sum);

    void filterExpendituresOfATypeGreaterOrEqualThanAGivenSum(const char *type, unsigned int sum);

    Expenditure *sortExpendituresInAscendingOrderBySum(unsigned int &dimension);

    Expenditure *sortExpendituresOfAGivenTypeInDescendingOrderBySum(const char *type, unsigned int &dimension);

    Expenditure displayTheMostCostlyExpenditure();

    unsigned int displayTheTotalCostOfTheExpendituresOfAGivenType(const char *type);
};


#endif //LAB_07_SERVICE_H
