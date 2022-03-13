//
//

#include "Order.h"

unsigned int Order::counter = 0;

Order::Order() {
    code = 0;
    clientName = "";
    time = 0;
    price = 0;
    day = 0;
}

Order::Order(const string &clientName, int time, double price, unsigned int day) {
    counter++;
    this->code = counter;
    this->clientName = clientName;
    this->time = time;
    this->price = price;
    this->day = day;
}

Order::Order(const Order &order) {
    code = order.code;
    clientName = order.clientName;
    time = order.time;
    price = order.price;
    day = order.day;
}

Order &Order::operator=(const Order &order) {
    if (this != &order) {
        code = order.code;
        clientName = order.clientName;
        time = order.time;
        price = order.price;
        day = order.day;
    }
    return *this;
}

unsigned int Order::getCode() const {
    return code;
}

string Order::getClientName() const {
    return clientName;
}

int Order::getTime() const {
    return time;
}

double Order::getPrice() const {
    return price;
}

unsigned int Order::getDay() const {
    return day;
}

void Order::setClientName(const string &newName) {
    clientName = newName;
}

void Order::setTime(int newTime) {
    time = newTime;
}

void Order::setPrice(double newPrice) {
    price = newPrice;
}

void Order::setDay(unsigned int newDay) {
    day = newDay;
}

bool Order::operator==(const Order &order) const {
    return (time == order.time && clientName == order.clientName && day == order.getDay() &&
            abs(price - order.getPrice()) < CONSTANT);
}

string Order::toString() const {
    return "CODE: " + to_string(code) + " / CLIENT NAME: " + clientName + " / TIME: " +
           to_string(time) + " / PRICE: " + to_string(price).substr(0, to_string(price).find('.') + 3)
           + " / DAY: " + to_string(day);
}

ostream &operator<<(ostream &out, Order &order) {
    out << "CODE: " + to_string(order.code) + " / CLIENT NAME: " + order.clientName + " / TIME: " +
           to_string(order.time) + " / PRICE: " +
           to_string(order.price).substr(0, to_string(order.price).find('.') + 3) + " / DAY: " + to_string(order.day)
        << endl;
    return out;
}