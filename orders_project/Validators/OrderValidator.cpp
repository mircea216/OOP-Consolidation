//
//

#include "OrderValidator.h"
#include "../Exceptions/OrderException.h"

void OrderValidator::validate(Order &order) noexcept(false) {
    for (unsigned int i = 0; i < order.getClientName().size(); i++) {
        if (!isalpha(order.getClientName()[i]) && order.getClientName()[i] != ' ') {
            errors += "The name of the client should contain valid characters!\n";
            break;
        }
    }
    if (order.getTime() < 0) {
        errors += "The time should be greater than 0!\n";
    }
    if (order.getPrice() < 0) {
        errors += "The price should be greater than 0!\n";
    }
    if (order.getDay() <= 0 || order.getDay() > 31) {
        errors += "The day should be in the range [1-31]!\n";
    }
    if (!errors.empty()) {
        string copyErrors = errors;
        errors.clear();
        throw OrderException(copyErrors);
    }
}

