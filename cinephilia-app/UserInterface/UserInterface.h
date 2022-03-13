//
//

#ifndef FINALPROJECT_USERINTERFACE_H
#define FINALPROJECT_USERINTERFACE_H


#include "../Service/Service.h"

class UserInterface {
private:
    Service service;

    static void printMenu();

    void add();

    void remove();

    void update();

    void searchFilmographicPiecesWithAGivenTitle();

    void searchFilmographicPiecesWithAGivenGenre();

    void searchFilmographicPiecesWithAGivenLeadingActor();

    void createARankingOfFilmographicPieces();

    void filterFilmographicPiecesWithAGivenGenre();

    void filterFilmographicPieceswithAratingGreaterThanAGivenOne();

    void showAll();


public:
    UserInterface() = default;

    explicit UserInterface(Service &service);

    ~UserInterface() = default;

    void runConsole();

    int runQT(int i, char **pString);


};


#endif //FINALPROJECT_USERINTERFACE_H
