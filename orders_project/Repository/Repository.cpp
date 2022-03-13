//
//

#include "Repository.h"
#include "../Exceptions/RepositoryException.h"
#include "../Exceptions/OrderException.h"

Repository::Repository(OrderValidator &orderValidator) : orderValidator(orderValidator) {}

void Repository::add(Order &order) noexcept(false) {
    orderValidator.validate(order);
    storage.push_back(order);
}

unsigned int Repository::getSize() const {
    return storage.size();
}

void Repository::remove(unsigned int givenCode) noexcept(false) {
    bool found = false;
    for (unsigned int index = 0; index < storage.size(); index++) {
        if (storage[index].getCode() == givenCode) {
            found = true;
            storage.erase(storage.begin() + index);
        }
    }
    if (!found)
        throw RepositoryException("The order you want to delete doesn't exist!");
}

void Repository::update(unsigned int givenCode, int newTime) noexcept(false) {
    bool found = false;
    if (newTime < 0)
        throw RepositoryException("The time should be greater than 0!");
    for (auto &order : storage) {
        if (order.getCode() == givenCode) {
            found = true;
            order.setTime(newTime);
        }
    }
    if (!found)
        throw RepositoryException("The order you want to update doesn't exist!");
}

vector<Order> Repository::getAll() {
    return storage;
}

Order Repository::getFrom(unsigned int position) {
    return storage[position];
}