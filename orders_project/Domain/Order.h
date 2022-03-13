//
//

#ifndef LABORATORY09_10_ORDER_H
#define LABORATORY09_10_ORDER_H

#include <iostream>
#include <string>

#define CONSTANT 0.00001

using namespace std;

class Order {
private:
    static unsigned int counter;
    unsigned int code;
    string clientName;
    int time;
    double price;
    unsigned int day;

public:
    Order();

    Order(const string &clientName, int time, double price, unsigned int day);

    Order(const Order &order);

    Order &operator=(const Order &order);

    ~Order() = default;

    unsigned int getCode() const;

    string getClientName() const;

    int getTime() const;

    double getPrice() const;

    unsigned int getDay() const;

    bool operator==(const Order &order) const;

    void setClientName(const string &newName);

    void setTime(int newTime);

    void setPrice(double newPrice);

    void setDay(unsigned int newDay);

    string toString() const;

    friend ostream &operator<<(ostream &out, Order &order);
};


#endif //LABORATORY09_10_ORDER_H
