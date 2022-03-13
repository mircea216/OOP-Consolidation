#include "Tests/Test.h"
#include "Repository/Repository.h"
#include "Service/Service.h"
#include "UserInterface/UserInterface.h"

int main() {
    Test::runAllTests();
    Repository repository;
    Service service(repository);
    service.insertExpenditure(12, 500, "lumina", 0);
    service.insertExpenditure(17, 200, "altele", 1);
    service.insertExpenditure(18, 40, "gaz", 2);
    service.insertExpenditure(21, 35, "haine", 3);
    service.addExpenditure(50, "gaz");
    service.addExpenditure(120, "mancare");
    service.addExpenditure(80, "altele");
    service.addExpenditure(60, "menaj");
    service.insertExpenditure(3, 500, "menaj", 8);

    UserInterface userInterface(service);
    userInterface.runConsole();
    return 0;
}
