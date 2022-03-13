//
//

#include <cassert>
#include "Test.h"
#include "../Domain/Order.h"
#include "../Repository/FileRepository.h"
#include "../Service/Service.h"
#include "../Exceptions/RepositoryException.h"
#include "../Exceptions/OrderException.h"
#include "../Exceptions/ServiceException.h"

void Test::testDomain() {
    /// DEFAULT CONSTRUCTOR
    Order order1;

    ///GETTERS

    assert(order1.getCode() == 0 && order1.getClientName().empty() && order1.getTime() == 0 && order1.getPrice() == 0 &&
           order1.getDay() == 0);

    /// CONSTRUCTOR WITH PARAMETRES
    Order order2("Jack", 12, 15.52, 12);

    /// GETTERS
    assert(order2.getCode() == 1 && order2.getClientName() == "Jack" && order2.getTime() == 12 &&
           abs(order2.getPrice() - 15.52) <= EPSILON && order2.getDay() == 12);

    /// COPY CONSTRUCTOR
    const Order &order3 = order2;

    assert(order3 == order2);

    /// ASSIGN OPERATOR
    Order order4;
    order4 = order2;
    assert(order4 == order2);

    /// SETTERS
    order4.setClientName("Patrick");
    order4.setTime(15);
    order4.setPrice(14.5);
    order4.setDay(20);
    assert(order4.getClientName() == "Patrick");
    assert(order4.getTime() == 15);
    assert(abs(order4.getPrice() - 14.5) <= EPSILON);
    assert(order4.getDay() == 20);

    /// TO STRING
    assert(order4.toString() == "CODE: 1 / CLIENT NAME: Patrick / TIME: 15 / PRICE: 14.50 / DAY: 20");
}

void Test::testRepository() {

    Repository repository;
    Order order("Jack", 12, 14, 20);
    Order order1("John", 13, 150, 20);
    /// ADD
    repository.add(order);
    repository.add(order1);

    /// GET SIZE
    assert(repository.getSize() == 2);

    /// GET ALL
    vector<Order> all;
    all.push_back(order);
    all.push_back(order1);
    assert(all == repository.getAll());

    /// REMOVE
    repository.remove(2);
    assert(repository.getSize() == 1);

    /// GET FROM
    assert(repository.getFrom(0) == order1);

    /// UPDATE
    repository.update(3, 120);
    order = repository.getFrom(0);
    assert(!(repository.getFrom(0) == order1));
    assert(repository.getFrom(0).getTime() == 120);


    /// EXCEPTIONS

    try {
        repository.remove(15);
        assert(false);
    }
    catch (RepositoryException &) {
        assert(true);
    }

    try {
        repository.update(15, -100);
        assert(false);
    }
    catch (RepositoryException &) {
        assert(true);
    }

}


void Test::testService() {
    auto *repository = new Repository;
    Service service(repository);

    /// ADD
    service.addOrder("Jane", 60, 50, 12);

    /// GET NUMBER
    assert(service.getNumberOfOrders() == 1);

    /// GET ALL
    service.addOrder("Jim", 50, 200, 13);
    vector<Order> all;
    Order order("Jane", 60, 50, 12);
    Order order1("Jim", 50, 200, 13);
    all.push_back(order);
    all.push_back(order1);
    assert(service.getAllOrders() == all);

    /// GET ORDER
    assert(service.getOrder(0) == order);
    assert(service.getOrder(1) == order1);

    /// REMOVE
    service.removeOrder(4);
    assert(service.getNumberOfOrders() == 1);
    assert(service.getOrder(0) == order1);

    /// UPDATE
    service.updateOrder(5, 85);
    assert(!(service.getOrder(0) == order1));
    assert(service.getOrder(0).getTime() == 85);

    /// DISPLAY - DAY
    service.addOrder("Jim", 100, 50, 13);
    assert(service.displayTheOrdersOfAGivenDay(13).size() == 2);
    assert(service.displayTheOrdersOfAGivenDay(13)[0].getDay() == 13);
    assert(service.displayTheOrdersOfAGivenDay(13)[1].getDay() == 13);


    /// DISPLAY - NAME
    assert(service.displayTheOrdersOfAGivenClient("Jim").size() == 2);
    assert(service.displayTheOrdersOfAGivenClient("Jim")[0].getClientName() == "Jim");
    assert(service.displayTheOrdersOfAGivenClient("Jim")[1].getClientName() == "Jim");

    /// COMPUTE - profit, number

    vector<Order> successfulOrders = service.computeTheNumberOfSuccessfulOrdersAndTheProfitForADay(13);
    unsigned int numberOFSuccessfulOrders = successfulOrders.size();
    assert(numberOFSuccessfulOrders == 2);
    double profit = 0;
    for (const Order &order2:successfulOrders)
        profit += order2.getPrice();
    assert(profit == 250);
    assert(successfulOrders[0].getPrice() == 200);
    assert(successfulOrders[1].getPrice() == 50);

    /// EXCEPTIONS

    try {
        service.addOrder("", -100, -100, 40);
        assert(false);
    }
    catch (OrderException &) {
        assert(true);
    }

    try {
        service.removeOrder(50);
        assert(false);
    }
    catch (RepositoryException &) {
        assert(true);
    }

    try {
        service.updateOrder(80, -100);
        assert(false);
    }
    catch (RepositoryException &) {
        assert(true);
    }

    try {
        service.displayTheOrdersOfAGivenDay(40);
        assert(false);

    }
    catch (ServiceException &) {
        assert(true);
    }

    try {
        service.displayTheOrdersOfAGivenClient("Jennifer");
        assert(false);

    }
    catch (ServiceException &) {
        assert(true);
    }
    try {
        service.computeTheNumberOfSuccessfulOrdersAndTheProfitForADay(3);
        assert(false);
    }
    catch (ServiceException &) {
        assert(true);
    }

}

void Test::testFileRepository() {
    FileRepository cleaner(R"(C:\Users\Cosmin\CLionProjects\laboratory09_10\testOrders.txt)");
    cleaner.doClear();
    auto *repository = new FileRepository(R"(C:\Users\Cosmin\CLionProjects\laboratory09_10\testOrders.txt)");

    /// CLEAR

    /// GET FILE NAME

    assert(repository->getFileName() == R"(C:\Users\Cosmin\CLionProjects\laboratory09_10\testOrders.txt)");

    ///ADD
    Order order("Patrick", 10, 130, 20);
    Order order1("Jack", 17, 230, 19);
    Order order2("Anna", 17, 40, 10);
    Order order3("Kim", 50, 50, 20);
    repository->add(order);
    repository->add(order1);
    repository->add(order2);
    repository->add(order3);

    /// GET SIZE

    assert(repository->getSize() == 4);

    /// GET FROM

    assert(repository->getFrom(0) == order);
    assert(repository->getFrom(1) == order1);
    assert(repository->getFrom(2) == order2);
    assert(repository->getFrom(3) == order3);

    /// GET ALL

    vector<Order> all;
    all.push_back(order);
    all.push_back(order1);
    all.push_back(order2);
    all.push_back(order3);
    assert(all == repository->getAll());

    /// REMOVE

    repository->remove(15);
    assert(repository->getSize() == 3);

    try {
        repository->remove(20);
        assert(false);
    }
    catch (RepositoryException &) {
        assert(true);
    }

    /// UPDATE
    try {
        repository->update(15, 100);
        assert(false);
    }
    catch (RepositoryException &) {
        assert(true);
    }
    assert(repository->getSize() == 3);

    try {
        Order order4("", -100, -100, 40);
        repository->add(order4);
        assert(false);
    }
    catch (OrderException &) {
        assert(true);
    }
    assert(repository->getSize() == 3);

}

void Test::runAllTests() {
    testDomain();
    testRepository();
    testService();
    testFileRepository();
    cout << "All tests have passed successfully" << endl << endl;
}