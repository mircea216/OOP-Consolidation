//
// Created by Cosmin on 14/05/2021.
//

#ifndef LABORATORY09_10_ORDERVALIDATOR_H
#define LABORATORY09_10_ORDERVALIDATOR_H

#include <string>
#include "../Domain/Order.h"

using namespace std;

class OrderValidator {
private:
    string errors;
public:
    OrderValidator() = default;

    void validate(Order &order) noexcept(false);

    ~OrderValidator() = default;


};


#endif //LABORATORY09_10_ORDERVALIDATOR_H
