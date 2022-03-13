//
//

#include <cstring>
#include "UserInterface.h"
#include <stack>

using namespace std;

UserInterface::UserInterface(Service &service) {
    this->service = service;
}

void UserInterface::addExpenditure() {
    cout << "Give the sum of the expenditure: " << endl;
    unsigned int sum;
    cin >> sum;
    cout << "Give the type of the expenditure: " << endl;
    char *type = new char[15];
    cin >> type;
    service.addExpenditure(sum, type);
    delete[] type;
}

void UserInterface::insertExpenditure() {
    cout << "Give the position at which you want to insert the expenditure: " << endl;
    int position;
    cin >> position;
    cout << "Give the day of the expenditure you want to insert: " << endl;
    unsigned int day;
    cin >> day;
    cout << "Give the sum of the expenditure you want to insert: " << endl;
    unsigned int sum;
    cin >> sum;
    cout << "Give the type of the expenditure you want to insert: " << endl;
    char *type = new char[15];
    cin >> type;
    service.insertExpenditure(day, sum, type, position);
    delete[] type;
}

void UserInterface::deleteExpenditure() {
    cout << "Give the day of the expenditure you want to delete: " << endl;
    unsigned int day;
    cin >> day;
    cout << "Give the sum of the expenditure you want to delete: " << endl;
    unsigned int sum;
    cin >> sum;
    cout << "Give the type of the expenditure you want to delete: " << endl;
    char *type = new char[15];
    cin >> type;
    service.deleteExpenditure(day, sum, type);
    delete[] type;

}


void UserInterface::updateExpenditure() {
    cout << "Give the day of the expenditure you want to update: " << endl;
    unsigned int oldDay;
    cin >> oldDay;
    cout << "Give the sum of the expenditure you want to update: " << endl;
    unsigned int oldSum;
    cin >> oldSum;
    cout << "Give the type of the expenditure you want to update: " << endl;
    char *oldType = new char[15];
    cin >> oldType;
    cout << "Give the day of the expenditure you want to update: " << endl;
    unsigned int newDay;
    cin >> newDay;
    cout << "Give the sum of the expenditure you want to update: " << endl;
    unsigned int newSum;
    cin >> newSum;
    cout << "Give the type of the expenditure you want to update: " << endl;
    char *newType = new char[15];
    cin >> newType;
    service.updateExpenditure(oldDay, oldSum, oldType, newDay, newSum, newType);
    delete[] newType;
    delete[] oldType;
}

void UserInterface::deleteTheExpendituresOfAGivenDay() {
    cout << "Give the day of the expenditure you want to delete: " << endl;
    unsigned int day;
    cin >> day;
    service.deleteTheExpendituresOfAGivenDay(day);

}

void UserInterface::deleteTheExpendituresOfAGivenRangeOfDays() {
    unsigned int startDay;
    unsigned int endDay;
    cout << "Give the first day of the range: " << endl;
    cin >> startDay;
    cout << "Give the second day of the range:: " << endl;
    cin >> endDay;
    service.deleteTheExpendituresOfAGivenRangeOfDays(startDay, endDay);

}

void UserInterface::deleteTheExpendituresOfAGivenType() {
    cout << "Give the type of the expenditure you want to delete: " << endl;
    char *type = new char[15];
    cin >> type;
    service.deleteTheExpendituresOfAGivenType(type);
    delete[] type;
}

void UserInterface::sortExpendituresInAscendingOrderBySum() {
    int i;
    unsigned int dimension = 0;
    Expenditure *sortedExpenditures = service.sortExpendituresInAscendingOrderBySum(dimension);
    if (dimension) {
        for (i = 0; i < dimension; i++)
            cout << sortedExpenditures[i];
    } else cout << "There are no expenditures of the given type to be sorted";
}

void UserInterface::filterTheExpendituresOfAGivenType() {
    char *type = new char[15];
    cout << "Give the type of the expenditures you want to filter: " << endl;
    cin >> type;
    service.filterTheExpendituresOfAGivenType(type);
    delete[] type;
}

void UserInterface::filterExpendituresOfATypeLesserThanAGivenSum() {
    cout << "Give the comparison price: " << endl;
    unsigned int sum;
    cin >> sum;
    cout << "Give the type of the expenditures you want to filter: " << endl;
    char *type = new char[15];
    cin >> type;
    service.filterExpendituresOfATypeLesserThanAGivenSum(type, sum);
    delete[] type;
}

void UserInterface::displayTheTotalCostOfTheExpendituresOfAGivenType() {
    cout << "Give the type of the expenditures to be added to the total cost : " << endl;
    char *type = new char[15];
    cin >> type;
    cout << "The total cost is:" << endl;
    cout << service.displayTheTotalCostOfTheExpendituresOfAGivenType(type);
    delete[] type;

}

void UserInterface::displayExpendituresOfAGivenType() {
    unsigned int dimension = 0;
    cout << "Give the type of the expenditure you want to display: " << endl;
    char *type = new char[15];
    cin >> type;
    Expenditure *expenditures = service.displayExpendituresOfAGivenType(type, dimension);
    cout << "The expenditures you are looking for are: " << endl;
    if (!dimension)
        cout << "The are no expenditures with the searched properties! " << endl;
    for (unsigned int i = 0; i < dimension; i++)
        cout << expenditures[i];
    if (dimension) {
        delete[] expenditures;
    }
    delete[] type;
}

void UserInterface::displayExpendituresOfAGivenTypeWithTheCostGreaterOrEqualThanAGivenOne() {
    unsigned int dimension = 0;
    cout << "Give the type of the expenditure you want to display: " << endl;
    char *type = new char[15];
    cin >> type;
    cout << "Give the comparison cost of the expenditure you want to display: " << endl;
    unsigned int sum;
    cin >> sum;
    Expenditure *expenditures = service.displayExpendituresOfAGivenTypeWithTheCostGreaterOrEqualThanAGivenOne(type, sum,
                                                                                                              dimension);
    cout << "The expenditures you are looking for are: " << endl;
    if (!dimension)
        cout << "The are no expenditures with the searched properties! " << endl;
    for (unsigned int i = 0; i < dimension; i++)
        cout << expenditures[i];
    if (dimension) {
        delete[] expenditures;
    }
    delete[] type;
}

void UserInterface::displayTheMostCostlyExpenditure() {
    cout << "The most costly expenditure is:" << endl;
    Expenditure expenditure = service.displayTheMostCostlyExpenditure();
    cout << expenditure;
}

void UserInterface::filterExpendituresOfATypeGreaterOrEqualThanAGivenSum() {
    cout << "Give the comparison price: " << endl;
    unsigned int sum;
    cin >> sum;
    cout << "Give the type of the expenditure you want to filter: " << endl;
    char *type = new char[15];
    cin >> type;
    service.filterExpendituresOfATypeGreaterOrEqualThanAGivenSum(type, sum);
    delete[] type;
}


void UserInterface::showAllExpenditures() {
    if (service.getAll().getAll() && service.getSize()) {
        cout << "The expenditures are: " << endl;
        for (int i = 0; i < service.getSize(); i++) {
            Expenditure expenditure = service.getExpenditure(i);
            cout << expenditure;
        }
    } else cout << "The are no expenditures." << endl;
}

void UserInterface::sortExpendituresOfAGivenTypeInDescendingOrderBySum() {
    char *type = new char[15];
    cout << "Give the type of the expenditure: " << endl;
    cin >> type;
    unsigned int dimension = 0;
    int i;
    Expenditure *sortedExpenditures = service.sortExpendituresOfAGivenTypeInDescendingOrderBySum(type, dimension);
    if (dimension) {
        for (i = 0; i < dimension; i++)
            cout << sortedExpenditures[i];
    } else cout << "There are no expenditures of the given type to be sorted";
    delete[] type;
}

void UserInterface::printMenu() {
    cout << "1.   ADD an expenditure" << endl;
    cout << "2.   INSERT an expenditure at a given position" << endl;
    cout << "3.   UPDATE an expenditure" << endl;
    cout << "4.   DELETE an expenditure" << endl;
    cout << "5.   DELETE the expenditures of a given day" << endl;
    cout << "6.   DELETE the expenditures of a given range of days" << endl;
    cout << "7.   DELETE the expenditures of a given type" << endl;
    cout << "8.   DISPLAY the expenditures of a given type" << endl;
    cout << "9.   DISPLAY the expenditures of a given type with the cost greater or equal than a given one" << endl;
    cout << "10.  DISPLAY the total cost of the expenditures of a given type" << endl;
    cout << "11.  DISPLAY the day of the most costly expenditure" << endl;
    cout << "12.  DISPLAY the expenditures sorted by the sum in ascending order" << endl;
    cout << "13.  DISPLAY the expenditures of a given type sorted by the sum in descending order" << endl;
    cout << "14.  FILTER the expenditures of a given type" << endl;
    cout << "15.  FILTER the expenditures of a type lesser than a given sum" << endl;
    cout << "16.  FILTER the expenditures of a given type greater or equal than a given sum" << endl;
    cout << "a.   SHOW ALL expenditures" << endl;
    cout << "u.   UNDO" << endl;
    cout << "x.   EXIT" << endl;
    cout << endl;
}


void UserInterface::runConsole() {
    char option[2];
    unsigned int numberOfEntities, index;
    stack<Repository> undoStack;
    while (true) {
        printMenu();
        cout << "Select the option:" << endl;
        cin >> option;
        if (strcmp(option, "1") == 0) {
            undoStack.push(service.getAll());
            cout << "Give the number of expenditures you want to add:" << endl;
            cin >> numberOfEntities;
            for (index = 0; index < numberOfEntities; index++)
                addExpenditure();
            cout << endl;
        } else if (strcmp(option, "2") == 0) {
            undoStack.push(service.getAll());
            insertExpenditure();
            cout << endl;
        } else if (strcmp(option, "3") == 0) {
            undoStack.push(service.getAll());
            updateExpenditure();
            cout << endl;
        } else if (strcmp(option, "4") == 0) {
            undoStack.push(service.getAll());
            deleteExpenditure();
            cout << endl;
        } else if (strcmp(option, "5") == 0) {
            undoStack.push(service.getAll());
            deleteTheExpendituresOfAGivenDay();
            cout << endl;
        } else if (strcmp(option, "6") == 0) {
            undoStack.push(service.getAll());
            deleteTheExpendituresOfAGivenRangeOfDays();
            cout << endl;
        } else if (strcmp(option, "7") == 0) {
            undoStack.push(service.getAll());
            deleteTheExpendituresOfAGivenType();
            cout << endl;
        } else if (strcmp(option, "8") == 0) {
            displayExpendituresOfAGivenType();
            cout << endl;
        } else if (strcmp(option, "9") == 0) {
            displayExpendituresOfAGivenTypeWithTheCostGreaterOrEqualThanAGivenOne();
            cout << endl;
        } else if (strcmp(option, "10") == 0) {
            displayTheTotalCostOfTheExpendituresOfAGivenType();
            cout << endl;
        } else if (strcmp(option, "11") == 0) {
            displayTheMostCostlyExpenditure();
            cout << endl;
        } else if (strcmp(option, "12") == 0) {
            sortExpendituresInAscendingOrderBySum();
            cout << endl;
        } else if (strcmp(option, "13") == 0) {
            sortExpendituresOfAGivenTypeInDescendingOrderBySum();
            cout << endl;
        } else if (strcmp(option, "14") == 0) {
            undoStack.push(service.getAll());
            filterTheExpendituresOfAGivenType();
            cout << endl;
        } else if (strcmp(option, "15") == 0) {
            undoStack.push(service.getAll());
            filterExpendituresOfATypeLesserThanAGivenSum();
            cout << endl;
        } else if (strcmp(option, "16") == 0) {
            undoStack.push(service.getAll());
            filterExpendituresOfATypeGreaterOrEqualThanAGivenSum();
            cout << endl;
        } else if (strcmp(option, "a") == 0) {
            showAllExpenditures();
            cout << endl;
        } else if (strcmp(option, "u") == 0) {
            if (!undoStack.empty()) {
                service.assingRepositoryForStack(undoStack.top());
                undoStack.pop();
            } else cout << "The UNDO operation cannot be executed any longer!" << endl;
        } else if (strcmp(option, "x") == 0) {
            service.release();
            cout << "EXIT" << endl;
            break;
        } else {
            cout << "Invalid option! Retry!" << endl;
        }
    }
}