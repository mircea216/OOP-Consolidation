//
//

#ifndef LABORATORY09_10_REPOSITORY_H
#define LABORATORY09_10_REPOSITORY_H


#endif //LABORATORY09_10_REPOSITORY_H

#include "../Domain/Order.h"
#include "../Validators/OrderValidator.h"
#include <vector>

using namespace std;

class Repository {
protected:
    vector<Order> storage;
    OrderValidator orderValidator;
public:
    Repository() = default;

    explicit Repository(OrderValidator &orderValidator);

    virtual ~Repository() = default;

    virtual void add(Order &order) noexcept(false);

    virtual void remove(unsigned int givenCode) noexcept(false);

    virtual void update(unsigned int givenCode, int newTime) noexcept(false);

    virtual unsigned int getSize() const;

    virtual Order getFrom(unsigned int position);

    virtual vector<Order> getAll();

};