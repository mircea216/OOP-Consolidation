//
//

#include <QApplication>
#include "UserInterface.h"
#include "../Exceptions/GenericException.h"
#include "../GraphicUserInterface/GraphicUserInterface.h"
#include <limits>

using namespace std;

UserInterface::UserInterface(Service &service) {
    this->service = service;
}


void UserInterface::printMenu() {
    cout << "1.  ADD a movie/ theatre play / documentary" << endl;
    cout << "2.  REMOVE a movie/ theatre play / documentary" << endl;
    cout << "3.  UPDATE a movie/ theatre play / documentary by renewing its rating and description" << endl;
    cout << "4.  SEARCH a movie/ theatre play / documentary by its title" << endl;
    cout << "5.  SEARCH the movies/ theatre plays / documentaries with a given genre" << endl;
    cout << "6.  SEARCH the movies/ theatre plays / documentaries with a given leading actor" << endl;
    cout << "7.  CREATE a ranking of the movies, theatre plays and documentaries" << endl;
    cout << "8.  FILTER the movies/ theatre plays / documentaries with a given genre" << endl;
    cout << "9.  FILTER the movies/ theatre plays / documentaries with a rating greater than a given one" << endl;
    cout << "a.  SHOW ALL movies/ theatre plays / documentaries" << endl;
    cout << "x.  EXIT" << endl;
    cout << endl;

}

void UserInterface::add() {
    try {
        cout << "Search - Cinephilia and beyond - " << endl << "Give the type of the piece you want to add:" << endl
             << "Movie / Theatre Play / Documentary" << endl;
        string movieType, title, director, genre, description, leadingActor, streamingService, theatreName;
        double rating = 0;
        int duration = 0;
        std::getline(std::cin >> std::ws, movieType);
        if (movieType == "Movie") {
            cout << "Give the title of the movie you want to add:" << endl;
            std::getline(std::cin >> std::ws, title);
            cout << "Give the director of the movie you want to add:" << endl;
            std::getline(std::cin >> std::ws, director);
            cout << "Give the genre of the movie you want to add:" << endl;
            std::getline(std::cin >> std::ws, genre);

            while (true) {
                cout << "Give the rating of the movie you want to add:" << endl;
                cin >> rating;
                if (cin.fail()) {
                    cout << "Please enter a valid value for the rating of the movie\n" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            cout << "Give the description of the movie you want to add:" << endl;
            std::getline(std::cin >> std::ws, description);
            cout << "Give the leading actor of the movie you want to add:" << endl;
            std::getline(std::cin >> std::ws, leadingActor);
        } else if (movieType == "Theatre Play") {
            cout << "Give the title of the theatre play you want to add:" << endl;
            std::getline(std::cin >> std::ws, title);
            cout << "Give the director of the theatre play you want to add:" << endl;
            std::getline(std::cin >> std::ws, director);
            cout << "Give the genre of the theatre play you want to add:" << endl;
            std::getline(std::cin >> std::ws, genre);

            while (true) {
                cout << "Give the rating of the theatre play you want to add:" << endl;
                cin >> rating;
                if (cin.fail()) {
                    cout << "Please enter a valid value for the rating of the theatre play\n" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            cout << "Give the description of the movie you want to add:" << endl;
            std::getline(std::cin >> std::ws, description);
            cout << "Give the leading actor of the theatre play you want to add:" << endl;
            std::getline(std::cin >> std::ws, leadingActor);

            while (true) {
                cout << "Give the duration of the theatre play you want to add:" << endl;
                cin >> duration;
                if (cin.fail()) {
                    cout << "Please enter a valid value for the duration of the theatre play\n" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            cout << "Give the theatre name of the theatre play you want to add:" << endl;
            std::getline(std::cin >> std::ws, theatreName);
        } else if (movieType == "Documentary") {
            cout << "Give the title of the documentary you want to add:" << endl;
            std::getline(std::cin >> std::ws, title);
            cout << "Give the director of the documentary you want to add:" << endl;
            std::getline(std::cin >> std::ws, director);
            cout << "Give the genre of the documentary you want to add:" << endl;
            std::getline(std::cin >> std::ws, genre);

            while (true) {
                cout << "Give the rating of the documentary you want to add:" << endl;
                cin >> rating;
                if (cin.fail()) {
                    cout << "Please enter a valid value for the rating of the documentary\n" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            cout << "Give the description of the documentary you want to add:" << endl;
            std::getline(std::cin >> std::ws, description);
            cout << "Give the leading actor of the documentary you want to add:" << endl;
            std::getline(std::cin >> std::ws, leadingActor);
            cout << "Give the streaming service of the documentary you want to add:" << endl;
            std::getline(std::cin >> std::ws, streamingService);
        }

        service.add(movieType, title, director, genre, rating, description, leadingActor, duration,
                    theatreName, streamingService);
    }
    catch (GenericException &genericException) {
        cout << genericException.what() << endl;
    }
}

void UserInterface::remove() {
    try {
        unsigned int givenID;
        while (true) {
            cout << "Introduce the ID of the movie/ theatre play / documentary you want to remove:" << endl;
            cin >> givenID;
            if (cin.fail()) {
                cout << "Please enter a valid value for the ID\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        service.remove(givenID);
    }
    catch (GenericException &genericException) {
        cout << genericException.what();
    }
}

void UserInterface::update() {
    try {
        unsigned int givenID;
        while (true) {
            cout << "Introduce the ID of the movie/ theatre play / documentary you want to update:" << endl;
            cin >> givenID;
            if (cin.fail()) {
                cout << "Please enter a valid value for the ID\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        double newRating;

        while (true) {
            cout << "Introduce the new rating:" << endl;
            cin >> newRating;
            if (cin.fail()) {
                cout << "Please enter a valid value for the rating\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        string newDescription;
        cout << "Introduce the new description:" << endl;
        std::getline(std::cin >> std::ws, newDescription);
        service.update(givenID, newRating, newDescription);
    }
    catch (GenericException &genericException) {
        cout << genericException.what();
    }
}


void UserInterface::searchFilmographicPiecesWithAGivenTitle() {
    try {
        string title;
        cout << "Give the title of the filmographic piece you want to search:" << endl;
        getline(cin >> ws, title);
        for (auto *&object:service.searchFilmographicPiecesWithAGivenTitle(title))
            cout << object->toString() << endl << endl;
    }
    catch (GenericException &genericException) {
        cout << genericException.what();
    }
}

void UserInterface::searchFilmographicPiecesWithAGivenGenre() {
    try {
        string givenGenre;
        cout << "Give the genre of the filmographic piece you want to search:" << endl;
        getline(cin >> ws, givenGenre);
        for (auto *&object:service.searchFilmographicPiecesWithAGivenGenre(givenGenre))
            cout << object->toString() << endl << endl;
    }
    catch (GenericException &genericException) {
        cout << genericException.what();
    }
}

void UserInterface::searchFilmographicPiecesWithAGivenLeadingActor() {
    try {
        string leadingActor;
        cout << "Give the leading actor of the filmographic piece you want to search:" << endl;
        getline(cin >> ws, leadingActor);
        for (auto *&object:service.searchFilmographicPiecesWithAGivenLeadingActor(leadingActor))
            cout << object->toString() << endl << endl;
    }
    catch (GenericException &genericException) {
        cout << genericException.what();
    }
}

void UserInterface::createARankingOfFilmographicPieces() {
    for (auto *&object:service.createARankingOfFilmographicPieces()) {
        cout << object->toString() << endl << endl;
    }
}

void UserInterface::filterFilmographicPiecesWithAGivenGenre() {
    try {
        string givenGenre;
        cout << "Give the genre of the filmographic pieces you want to filter:" << endl;
        getline(cin >> ws, givenGenre);
        service.filterFilmographicPiecesWithAGivenGenre(givenGenre);
        for (auto *&object:service.getAll())
            cout << object->toString() << endl << endl;
    }
    catch (GenericException &genericException) {
        cout << genericException.what();
    }
}

void UserInterface::filterFilmographicPieceswithAratingGreaterThanAGivenOne() {
    try {
        double givenRating;
        while (true) {
            cout << "Give the rating of the filmographic pieces you want to filter:" << endl;
            cin >> givenRating;
            if (cin.fail()) {
                cout << "Please enter a valid value for the rating of the filmographic piece\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        service.filterFilmographicPieceswithAratingGreaterThanAGivenOne(givenRating);
        for (auto *&object:service.getAll())
            cout << object->toString() << endl << endl;
    }
    catch (GenericException &genericException) {
        cout << genericException.what();
    }
}

int UserInterface::runQT(int argc, char **argv) {
    QApplication app(argc, argv);
    GraphicUserInterface GUI(service);
    GUI.show();
    return QApplication::exec();

}

void UserInterface::showAll() {
    for (auto *&object:service.getAll())
        cout << object->toString() << endl << endl;
}

void UserInterface::runConsole() {
    string option;
    while (true) {
        printMenu();
        cout << "Select the option:" << endl;
        cin >> option;
        if (option == "1") {
            add();
            cout << endl;
        } else if (option == "2") {
            remove();
            cout << endl;
        } else if (option == "3") {
            update();
            cout << endl;
        } else if (option == "4") {
            searchFilmographicPiecesWithAGivenTitle();
            cout << endl;
        } else if (option == "5") {
            searchFilmographicPiecesWithAGivenGenre();
            cout << endl;
        } else if (option == "6") {
            searchFilmographicPiecesWithAGivenLeadingActor();
            cout << endl;
        } else if (option == "7") {
            createARankingOfFilmographicPieces();
            cout << endl;
        } else if (option == "8") {
            filterFilmographicPiecesWithAGivenGenre();
            cout << endl;
        } else if (option == "9") {
            filterFilmographicPieceswithAratingGreaterThanAGivenOne();
            cout << endl;
        } else if (option == "a") {
            showAll();
            cout << endl;
        } else if (option == "x") {
            cout << "EXIT" << endl;
            break;
        } else {
            cout << "Invalid option! Retry!" << endl << endl;
        }
    }
}