//
//

#include "UserInterface.h"
#include "../Exceptions/OrderException.h"
#include "../Exceptions/RepositoryException.h"
#include "../Exceptions/ServiceException.h"
#include <limits>

using namespace std;

UserInterface::UserInterface(Service &service) {
    this->service = service;
}

void UserInterface::printMenu() {
    cout << "1.  ADD an order" << endl;
    cout << "2.  UPDATE an order" << endl;
    cout << "3.  DELETE an order" << endl;
    cout << "4.  DISPLAY the orders of a given day" << endl;
    cout << "5.  DISPLAY the orders of a given client" << endl;
    cout << "6.  COMPUTE the number of successful orders and the profit for a day" << endl;
    cout << "a.  SHOW ALL orders" << endl;
    cout << "x.  EXIT" << endl;
    cout << endl;
}

void UserInterface::addOrder() {

    string clientName;
    cout << "Give the name of the client:" << endl;
    cin >> clientName;
    int time;
    while (true) {
        cout << "Give the time of the order:" << endl;
        cin >> time;
        if (cin.fail()) {
            cout << "Please enter a valid integer value for the time of the order\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    double price;

    while (true) {
        cout << "Give the price of the order:" << endl;
        cin >> price;
        if (cin.fail()) {
            cout << "Please enter a valid value for the price of the order\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    unsigned int day;

    while (true) {
        cout << "Give the day of the order:" << endl;
        cin >> day;
        if (cin.fail()) {
            cout << "Please enter a valid value for the day of the order\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    try {
        service.addOrder(clientName, time, price, day);
    }
    catch (OrderException &orderException) {
        cout << orderException.what() << endl;
    }
}

void UserInterface::updateOrder() {
    unsigned int givenCode;

    while (true) {
        cout << "Give the code of the order you want to update:" << endl;
        cin >> givenCode;
        if (cin.fail()) {
            cout << "Please enter a valid value for the code of the order\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    int newTime;
    while (true) {
        cout << "Give the updated time of the order you want to update:" << endl;
        cin >> newTime;
        if (cin.fail()) {
            cout << "Please enter a valid value for the updated time of the order\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    try {
        service.updateOrder(givenCode, newTime);
    }
    catch (RepositoryException &repositoryException) {
        cout << repositoryException.what() << endl;
    }

}

void UserInterface::removeOrder() {
    unsigned int givenCode;

    while (true) {
        cout << "Give the code of the order you want to delete:" << endl;
        cin >> givenCode;
        if (cin.fail()) {
            cout << "Please enter a valid value for the code of the order\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    try {
        service.removeOrder(givenCode);
    }
    catch (RepositoryException &repositoryException) {
        cout << repositoryException.what() << endl;
    }
}

void UserInterface::showAllOrders() {
    for (auto &order:service.getAllOrders())
        cout << order;
}

void UserInterface::displayTheOrdersOfAGivenDay() {
    unsigned int day;
    while (true) {
        cout << "Give the day of the order:" << endl;
        cin >> day;
        if (cin.fail()) {
            cout << "Please enter a valid value for the day of the order\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    try {
        for (auto &order:service.displayTheOrdersOfAGivenDay(day))
            cout << order;
    }
    catch (ServiceException &serviceException) {
        cout << serviceException.what();
    }
}

void UserInterface::displayTheOrdersOfAGivenClient() {
    string givenClientName;
    cout << "Give the name of the client whose orders you want to display:" << endl;
    cin >> givenClientName;
    try {
        for (auto &order:service.displayTheOrdersOfAGivenClient(givenClientName))
            cout << order;
    }
    catch (ServiceException &serviceException) {
        cout << serviceException.what();
    }


}

void UserInterface::computeTheNumberOfSuccessfulOrdersAndTheProfitForADay() {
    int day;
    while (true) {
        cout << "Give the day for which you want to display the successful orders, their number and the profit:"
             << endl;
        cin >> day;
        if (cin.fail()) {
            cout << "Please enter a valid value for the day of the order\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    double profit = 0.0;
    try {
        cout << "There number of successful orders is: \n"
             << service.computeTheNumberOfSuccessfulOrdersAndTheProfitForADay(day).size()
             << endl;
        for (auto &order:service.computeTheNumberOfSuccessfulOrdersAndTheProfitForADay(day)) {
            cout << order;
            profit += order.getPrice();
        }
        cout << "\nThe total profit is: " << profit << endl;
    }
    catch (ServiceException &serviceException) {
        cout << serviceException.what();
    }
}

void UserInterface::runConsole() {
    string option;
    while (true) {
        printMenu();
        cout << "Select the option:" << endl;
        cin >> option;
        if (option == "1") {
            addOrder();
            cout << endl;
        } else if (option == "2") {
            updateOrder();
            cout << endl;
        } else if (option == "3") {
            removeOrder();
            cout << endl;
        } else if (option == "4") {
            displayTheOrdersOfAGivenDay();
            cout << endl;
        } else if (option == "5") {
            displayTheOrdersOfAGivenClient();
            cout << endl;
        } else if (option == "6") {
            computeTheNumberOfSuccessfulOrdersAndTheProfitForADay();
            cout << endl;
        } else if (option == "a") {
            showAllOrders();
            cout << endl;
        } else if (option == "x") {
            cout << "EXIT" << endl;
            break;
        } else {
            cout << "Invalid option! Retry!" << endl << endl;
        }
    }
}