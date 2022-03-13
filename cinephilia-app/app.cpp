#include "Tests/Test.h"
#include "Repository/Repository.h"
#include "Repository/FileRepository.h"
#include "Service/Service.h"
#include "UserInterface/UserInterface.h"
#include<crtdbg.h>

int main(int argc, char **argv) {
    Test::runAllTests();
    auto *repository = new FileRepository(R"(D:\\OneDrive\\Desktop\\finalProject\\masterpieces.csv)");
    Service service(repository);
    UserInterface userInterface(service);
    userInterface.runConsole();
    return userInterface.runQT(argc, argv);
}
