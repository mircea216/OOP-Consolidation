//
//

#ifndef FINALPROJECT_GRAPHICUSERINTERFACE_H
#define FINALPROJECT_GRAPHICUSERINTERFACE_H

#include <QTableWidget>
#include <QWidget>
#include "../Service/Service.h"

class GraphicUserInterface : public QWidget {
private:
    Service &service;
public:
    explicit GraphicUserInterface(Service &service);

    QTableWidget *tableOfMovies;
    QTableWidget *tableOfTheatrePlays;
    QTableWidget *tableOfDocumentaries;

    void addToTable(Object *object);

    void addMovie();

    void addTheatrePlay();

    void addDocumentary();
};

#endif //FINALPROJECT_GRAPHICUSERINTERFACE_H
