//
//

#include <cassert>
#include <cstring>
#include <ctime>
#include "Test.h"
#include "../Domain/Expenditure.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"


void Test::testDomain() {
    Expenditure expenditure1(12, 50, "gaz");
    /// GETTERS
    assert(expenditure1.getDay() == 12);
    assert(expenditure1.getSum() == 50);
    assert(strcmp(expenditure1.getType(), "gaz") == 0);

    /// COPY CONSTRUCTOR
    const Expenditure &expenditure4 = expenditure1;

    /// ==OPERATOR
    assert(expenditure4 == expenditure1);

    /// ASSIGN OPERATOR
    Expenditure expenditure2;
    expenditure2 = expenditure1;
    assert(expenditure1 == expenditure2);
    Expenditure expenditure3(12, 51, "lumina");
    expenditure3 = expenditure2;
    assert(expenditure3.getSum() == 50);

    /// SETTERS
    Expenditure expenditure5;
    expenditure5.setDay(12);
    expenditure5.setSum(50);
    expenditure5.setType("gaz");
    assert(expenditure5.getDay() == 12 && expenditure5.getSum() == 50 && strcmp(expenditure5.getType(), "gaz") == 0);

}

void Test::testRepository() {
    /// ADD
    Expenditure expenditure1(12, 50, "gaz");
    Expenditure expenditure2(13, 60, "menaj");
    Expenditure expenditure3(14, 100, "mancare");
    Repository repository;
    repository.addExpenditure(expenditure1);
    repository.addExpenditure(expenditure2);
    repository.addExpenditure(expenditure3);

    /// GET SIZE
    assert(repository.getSize() == 3);

    /// GET ALL
    Expenditure *expenditures = repository.getAll();
    assert(expenditure1 == expenditures[0]);
    assert(expenditure2 == expenditures[1]);
    assert(expenditure3 == expenditures[2]);

    /// UPDATE
    repository.updateExpenditure(expenditure3, expenditure1);
    assert(expenditure1 == expenditures[2]);

    /// GET EXPENDITURE
    assert(repository.getExpenditure(2) == expenditure1);

    /// DELETE
    repository.deleteExpenditure(expenditure2);
    assert(repository.getSize() == 2);

    /// INSERT
    repository.insertExpenditure(expenditure3, 0);

    /// COPY CONSTRUCTOR
    Repository repository1 = repository;
    assert(repository1.getSize() == 3);
    assert(repository1.getExpenditure(0) == expenditure3);
    assert(repository1.getExpenditure(1) == expenditure1);
    assert(repository1.getExpenditure(2) == expenditure1);


    /// ASSIGN OPERATOR
    Repository repository2;
    repository2 = repository1;
    assert(repository2.getSize() == 3);

    /// RELEASE
    repository2.release();
    repository1.release();
    repository.release();
    assert(!repository.getAll() && !repository1.getAll() && !repository2.getAll());

}


void Test::testService() {

    Repository repository;
    Service service(repository);
    /// ADD
    service.addExpenditure(50, "gaz");
    service.addExpenditure(60, "menaj");

    /// INSERT
    service.insertExpenditure(14, 100, "mancare", 2);
    assert(service.getExpenditure(2).getDay() == 14 && service.getExpenditure(2).getSum() == 100 &&
           strcmp(service.getExpenditure(2).getType(), "mancare") == 0);

    /// GET SIZE
    assert(service.getSize() == 3);

    /// DELETE
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    unsigned int currentDay = now->tm_mday;
    service.deleteExpenditure(currentDay, 50, "gaz");
    assert(service.getSize() == 2);

    ///  UPDATE
    service.updateExpenditure(14, 100, "mancare", 10, 50, "menaj");
    assert(service.getExpenditure(1).getDay() == 10 && service.getExpenditure(1).getSum() == 50 &&
           strcmp(service.getExpenditure(1).getType(), "menaj") == 0);
    /// DELETE - given day
    service.insertExpenditure(12, 100, "gaz", 2);
    service.insertExpenditure(12, 30, "menaj", 3);
    service.deleteTheExpendituresOfAGivenDay(12);
    assert(service.getSize() == 2);
    assert(service.getExpenditure(1).getDay() == 10);

    /// DELETE - given range of days
    service.deleteTheExpendituresOfAGivenRangeOfDays(10, 30);
    assert(!service.getSize());

    /// DELETE - given type
    service.insertExpenditure(12, 50, "gaz", 0);
    service.insertExpenditure(12, 100, "lumina", 1);
    service.insertExpenditure(13, 75, "lumina", 2);
    service.insertExpenditure(20, 120, "mancare", 3);
    service.insertExpenditure(12, 80, "altele", 4);
    service.insertExpenditure(23, 60, "menaj", 5);
    service.deleteTheExpendituresOfAGivenType("lumina");
    assert(service.getSize() == 4);
    assert(strcmp(service.getExpenditure(1).getType(), "mancare") == 0);

    /// DISPLAY - given type
    unsigned int dimension = 0;
    Expenditure *expenditures = service.displayExpendituresOfAGivenType("gaz", dimension);
    assert(expenditures[0].getDay() == 12 && expenditures[0].getSum() == 50 &&
           strcmp(expenditures[0].getType(), "gaz") == 0);
    assert(dimension == 1);
    if (dimension)
        delete[] expenditures;

    /// DISPLAY - total cost
    service.insertExpenditure(21, 100, "gaz", 4);
    assert(service.displayTheTotalCostOfTheExpendituresOfAGivenType("gaz") == 150);
    service.insertExpenditure(10, 50, "gaz", 5);
    assert(service.displayTheTotalCostOfTheExpendituresOfAGivenType("gaz") == 200);

    /// DISPLAY - the most costly expenditure
    assert(service.displayTheMostCostlyExpenditure().getSum() == 120);

    /// SORT - ascending by sum
    dimension = 0;
    expenditures = service.sortExpendituresInAscendingOrderBySum(dimension);
    assert(expenditures[0].getSum() == 50);
    assert(expenditures[1].getSum() == 50);
    assert(expenditures[2].getSum() == 60);
    assert(expenditures[3].getSum() == 80);
    assert(expenditures[4].getSum() == 100);
    assert(expenditures[5].getSum() == 120);

    /// SORT - given type - descending - by sum
    dimension = 0;
    assert(service.sortExpendituresOfAGivenTypeInDescendingOrderBySum("gaz", dimension)[0].getSum() == 100);
    assert(service.sortExpendituresOfAGivenTypeInDescendingOrderBySum("gaz", dimension)[1].getSum() == 50);
    assert(service.sortExpendituresOfAGivenTypeInDescendingOrderBySum("gaz", dimension)[2].getSum() == 50);


    /// FILTER - given type

    Service service1;
    service1.insertExpenditure(14, 60, "menaj", 0);
    service1.insertExpenditure(13, 30, "menaj", 1);
    service1.insertExpenditure(18, 60, "altele", 2);
    service1.filterTheExpendituresOfAGivenType("menaj");
    assert(service1.getSize() == 2);


    /// FILTER - given type - less than a sum
    Service service2;
    service2.insertExpenditure(24, 60, "menaj",0);
    service2.insertExpenditure(23, 30, "menaj",1);
    service2.insertExpenditure(28, 60, "altele",2);
    assert(service2.getSize() == 3);
    service2.filterExpendituresOfATypeLesserThanAGivenSum("menaj", 100);
    assert(service2.getSize() == 2);

    /// FILTER - given type - less than a sum
    Service service3;
    service3.insertExpenditure(12, 60, "menaj", 0);
    service3.insertExpenditure(30, 30, "menaj", 1);
    service3.insertExpenditure(18, 60, "altele", 2);
    assert(service3.getSize() == 3);
    service3.filterExpendituresOfATypeGreaterOrEqualThanAGivenSum("menaj", 60);
    assert(service3.getSize() == 1);

    /// COPY CONSTRUCTOR
    Service service4 = service3;
    assert(service4.getSize() == 1);

    /// ASSIGN OPERATOR
    Service service5;
    service5 = service2;
    assert(service5.getSize() == 2);


    service3.release();
    service2.release();
    service1.release();
    service.release();

}

void Test::runAllTests() {
    testDomain();
    testRepository();
    testService();
    cout << "All tests have passed successfully!" << endl << endl;
}