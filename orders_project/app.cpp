#include "Test/Test.h"
#include "Repository/FileRepository.h"
#include "Service/Service.h"
#include "UserInterface/UserInterface.h"

int main() {
    Test::runAllTests();
    Repository *repository = new FileRepository(R"(C:\Users\Cosmin\CLionProjects\laboratory09_10\orders.txt)");
    Service service(repository);
    UserInterface userInterface(service);
    userInterface.runConsole();
    return 0;
}
