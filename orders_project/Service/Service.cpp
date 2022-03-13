//
//

#include "Service.h"
#include "../Exceptions/ServiceException.h"

Service::Service() {
    repository = nullptr;
}

Service::Service(Repository *repository) {
    this->repository = repository;
}

void Service::addOrder(const string &clientName, int time, double price, unsigned int day) {
    Order order(clientName, time, price, day);
    repository->add(order);
}

void Service::removeOrder(unsigned int givenCode) {
    repository->remove(givenCode);
}

void Service::updateOrder(unsigned int givenCode, int newTime) {
    repository->update(givenCode, newTime);
}

vector<Order> Service::getAllOrders() {
    return repository->getAll();
}

unsigned int Service::getNumberOfOrders() const {
    return repository->getSize();
}

Order Service::getOrder(unsigned int position) {
    return repository->getFrom(position);
}

vector<Order> Service::displayTheOrdersOfAGivenDay(unsigned int givenDay) {
    if (givenDay < 0 || givenDay > 31)
        throw ServiceException("The day should be in the range [1-31]!\n");
    vector<Order> orders;
    for (auto &order:getAllOrders()) {
        if (order.getDay() == givenDay)
            orders.push_back(order);
    }
    if (orders.empty())
        throw ServiceException("There is no order for this day. Retry!\n");
    return orders;
}

vector<Order> Service::displayTheOrdersOfAGivenClient(const string &givenClientName) {
    for (char i : givenClientName) {
        if (!isalpha(i) && i != ' ') {
            throw ServiceException("The name of the client should contain valid characters!\n");
        }
    }
    vector<Order> orders;
    for (auto &order:getAllOrders())
        if (order.getClientName() == givenClientName)
            orders.push_back(order);
    if (orders.empty())
        throw ServiceException("There is no order for this client. Retry!\n");
    return orders;
}

vector<Order> Service::computeTheNumberOfSuccessfulOrdersAndTheProfitForADay(int givenDay) {
    if (givenDay < 0 || givenDay > 31)
        throw ServiceException("The day should be in the range [1-31]!\n");
    vector<Order> orders;
    int time = 0;
    for (auto &order:getAllOrders())
        if (order.getDay() == givenDay) {
            if (time < 720) {
                time += order.getTime();
                orders.push_back(order);
            }
        }
    if (time > 720)
        orders.pop_back();
    if (orders.empty())
        throw ServiceException("There is no order for this day. Retry!\n");
    return orders;
}