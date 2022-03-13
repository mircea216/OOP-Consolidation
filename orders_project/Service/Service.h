//
//

#ifndef LABORATORY09_10_SERVICE_H
#define LABORATORY09_10_SERVICE_H


#include "../Repository/FileRepository.h"

class Service {
private:
    Repository *repository;
public:
    Service();

    ~Service() = default;

    explicit Service(Repository *repository);

    void addOrder(const string &clientName, int time, double price, unsigned int day) noexcept(false);

    void removeOrder(unsigned int givenCode) noexcept(false);

    void updateOrder(unsigned int givenCode, int newTime) noexcept(false);

    unsigned int getNumberOfOrders() const;

    Order getOrder(unsigned int position);

    vector<Order> getAllOrders();

    vector<Order> displayTheOrdersOfAGivenDay(unsigned int givenDay) noexcept(false);

    vector<Order> displayTheOrdersOfAGivenClient(const string &givenClientName) noexcept(false);

    vector<Order> computeTheNumberOfSuccessfulOrdersAndTheProfitForADay(int givenDay) noexcept(false);

};


#endif //LABORATORY09_10_SERVICE_H
