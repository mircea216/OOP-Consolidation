//
//

#ifndef LAB_07_USERINTERFACE_H
#define LAB_07_USERINTERFACE_H


#include "../Service/Service.h"


class UserInterface {
private:
    Service service;

    void addExpenditure();

    void insertExpenditure();

    void deleteExpenditure();

    void updateExpenditure();

    void deleteTheExpendituresOfAGivenDay();

    void deleteTheExpendituresOfAGivenRangeOfDays();

    void deleteTheExpendituresOfAGivenType();

    void displayExpendituresOfAGivenType();

    void displayExpendituresOfAGivenTypeWithTheCostGreaterOrEqualThanAGivenOne();

    void displayTheMostCostlyExpenditure();

    void displayTheTotalCostOfTheExpendituresOfAGivenType();

    void filterTheExpendituresOfAGivenType();

    void filterExpendituresOfATypeLesserThanAGivenSum();

    void filterExpendituresOfATypeGreaterOrEqualThanAGivenSum();

    void sortExpendituresInAscendingOrderBySum();

    void sortExpendituresOfAGivenTypeInDescendingOrderBySum();

    void showAllExpenditures();

    static void printMenu();

public:
    UserInterface() = default;

    explicit UserInterface(Service &service);

    ~UserInterface() = default;

    void runConsole();
};


#endif //LAB_07_USERINTERFACE_H
