//
// Created by Cosmin on 04/05/2021.
//

#ifndef LABORATORY09_10_USERINTERFACE_H
#define LABORATORY09_10_USERINTERFACE_H


#include "../Service/Service.h"

class UserInterface {
private:
    Service service;

    static void printMenu();

    void addOrder();

    void removeOrder();

    void updateOrder();

    void showAllOrders();

    void displayTheOrdersOfAGivenDay();

    void displayTheOrdersOfAGivenClient();

    void computeTheNumberOfSuccessfulOrdersAndTheProfitForADay();

public:
    UserInterface() = default;

    explicit UserInterface(Service &service);

    ~UserInterface() = default;

    void runConsole();
};


#endif //LABORATORY09_10_USERINTERFACE_H
