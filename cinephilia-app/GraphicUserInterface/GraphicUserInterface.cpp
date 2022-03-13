//
//

#include "GraphicUserInterface.h"
#include "../Domain/Movie.h"
#include "../Domain/TheatrePlay.h"
#include "../Domain/Documentary.h"
#include "../Exceptions/GenericException.h"
#include <QDebug>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTableWidget>
#include <QTextEdit>
#include <QShortcut>
#include <QKeyEvent>
#include <QMessageBox>

GraphicUserInterface::GraphicUserInterface(Service &service) : service(service) {
    auto MoviesLabel = new QLabel();
    MoviesLabel->setText("Movies");
    MoviesLabel->setStyleSheet("color: blue;"
                               "background-color: yellow;"
                               "selection-color: yellow;"
                               "selection-background-color: blue;");
    MoviesLabel->setStyleSheet("QLineEdit { background-color: green }");
    MoviesLabel->setStyleSheet(
            "QLabel { background-color: green ,colour : yellow;}");

    auto playerLabel = new QLabel();
    playerLabel->setText("Theatre Plays");

    auto documentaryLabel = new QLabel("Documentary");

    this->setWindowTitle("Cinephilia and beyond");

    auto layout = new QVBoxLayout();
    this->setLayout(layout);


    QImage image;
    image.load(R"(D:\OneDrive\Desktop\finalProject\cinephilia.jpg)");
    auto label = new QLabel();
    label->setPixmap(QPixmap::fromImage(image));
    layout->addWidget(label);
    label->setAlignment(Qt::AlignCenter);

    this->tableOfMovies = new QTableWidget();
    this->tableOfTheatrePlays = new QTableWidget();
    this->tableOfDocumentaries = new QTableWidget();
    auto AddMovieButton = new QPushButton("Add Movie");
    auto AddTheatrePlayButton = new QPushButton("Add Theatre Play");
    auto addDocumentaryButton = new QPushButton("Add Documentary");
    layout->addWidget(MoviesLabel);
    layout->addWidget(tableOfMovies);
    layout->addWidget(AddMovieButton);
    layout->addWidget(playerLabel);
    layout->addWidget(tableOfTheatrePlays);
    layout->addWidget(AddTheatrePlayButton);
    layout->addWidget(documentaryLabel);
    layout->addWidget(tableOfDocumentaries);
    layout->addWidget(addDocumentaryButton);

    tableOfMovies->setColumnCount(8);
    tableOfTheatrePlays->setColumnCount(10);
    tableOfDocumentaries->setColumnCount(9);

    tableOfMovies->setHorizontalHeaderLabels(
            {"ID", "TITLE", "DIRECTOR", "GENRE", "RATING", "DESCRIPTION", "LEADING ACTOR", "Remove"});
    tableOfTheatrePlays->setHorizontalHeaderLabels(
            {"ID", "TITLE", "DIRECTOR", "GENRE", "RATING", "DESCRIPTION", "LEADING ACTOR", "DURATION", "THEATRE NANE",
             "Remove"});
    tableOfDocumentaries->setHorizontalHeaderLabels(
            {"ID", "TITLE", "DIRECTOR", "GENRE", "RATING", "DESCRIPTION", "LEADING ACTOR", "STREAMING SERVICE",
             "Remove"});

    tableOfMovies->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableOfTheatrePlays->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableOfDocumentaries->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    QObject::connect(AddMovieButton, &QPushButton::clicked, this,
                     &GraphicUserInterface::addMovie);

    QObject::connect(AddTheatrePlayButton, &QPushButton::clicked, this,
                     &GraphicUserInterface::addTheatrePlay);

    QObject::connect(addDocumentaryButton, &QPushButton::clicked, this,
                     &GraphicUserInterface::addDocumentary);

    for (Object *object : service.getAll()) {
        this->addToTable(object);
    }
}


void GraphicUserInterface::addMovie() {
    auto widget = new QWidget();
    auto VLayout = new QVBoxLayout();
    auto formLayout = new QFormLayout();
    auto addButton = new QPushButton("Add MOVIE");

    VLayout->addLayout(formLayout);
    VLayout->addWidget(addButton);
    widget->setLayout(VLayout);

    auto titleInput = new QLineEdit();
    formLayout->addRow("TITLE", titleInput);

    auto directorInput = new QLineEdit();
    formLayout->addRow("DIRECTOR", directorInput);

    auto genreInput = new QLineEdit();
    formLayout->addRow("GENRE", genreInput);

    auto descriptionInput = new QLineEdit();
    formLayout->addRow("DESCRIPTION", descriptionInput);

    auto ratingInput = new QSpinBox();
    ratingInput->setMinimum(0);
    formLayout->addRow("RATING", ratingInput);

    auto leadingActorInput = new QLineEdit();
    formLayout->addRow("LEADING ACTOR", leadingActorInput);


    QObject::connect(addButton, &QPushButton::clicked, [=]() {
        auto title = titleInput->text();
        auto director = directorInput->text();
        auto genre = genreInput->text();
        auto rating = ratingInput->value();
        auto description = descriptionInput->text();
        auto leadingActor = leadingActorInput->text();
        try {
            this->service.add("Movie", title.toStdString(), director.toStdString(), genre.toStdString(), rating,
                              description.toStdString(), leadingActor.toStdString(), 0, "", "");

            this->addToTable(this->service.getAll()[this->service.getAll().size() - 1]);
            this->adjustSize();
            widget->close();
        } catch (GenericException &exception) {
            auto messageBox = new QMessageBox();
            messageBox->setText(QString::fromStdString(exception.what()));
            messageBox->show();
        }
    });

    widget->show();
}


void GraphicUserInterface::addTheatrePlay() {
    auto widget = new QWidget();
    auto VLayout = new QVBoxLayout();
    auto formLayout = new QFormLayout();
    auto addButton = new QPushButton("Add THEATRE PLAY");

    VLayout->addLayout(formLayout);
    VLayout->addWidget(addButton);
    widget->setLayout(VLayout);

    auto titleInput = new QLineEdit();
    formLayout->addRow("TITLE", titleInput);

    auto directorInput = new QLineEdit();
    formLayout->addRow("DIRECTOR", directorInput);

    auto genreInput = new QLineEdit();
    formLayout->addRow("GENRE", genreInput);

    auto descriptionInput = new QLineEdit();
    formLayout->addRow("DESCRIPTION", descriptionInput);

    auto ratingInput = new QSpinBox();
    ratingInput->setMinimum(0);
    ratingInput->setMaximum(10);
    formLayout->addRow("RATING", ratingInput);

    auto leadingActorInput = new QLineEdit();
    formLayout->addRow("LEADING ACTOR", leadingActorInput);

    auto durationInput = new QSpinBox();
    durationInput->setMinimum(2);
    durationInput->setMaximum(4);
    formLayout->addRow("DURATION", durationInput);

    auto theatreNameInput = new QLineEdit();
    formLayout->addRow("THEATRE NAME", theatreNameInput);


    QObject::connect(addButton, &QPushButton::clicked, [=]() {
        auto title = titleInput->text();
        auto director = directorInput->text();
        auto genre = genreInput->text();
        auto rating = ratingInput->value();
        auto description = descriptionInput->text();
        auto leadingActor = leadingActorInput->text();
        auto duration = durationInput->value();
        auto theatreName = theatreNameInput->text();
        try {
            this->service.add("Theatre Play", title.toStdString(), director.toStdString(), genre.toStdString(), rating,
                              description.toStdString(), leadingActor.toStdString(), duration,
                              theatreName.toStdString(),
                              "");
            this->addToTable(this->service.getAll()[this->service.getAll().size() - 1]);
            this->adjustSize();
            widget->close();
        } catch (GenericException &exception) {
            auto messageBox = new QMessageBox();
            messageBox->setText(QString::fromStdString(exception.what()));
            messageBox->show();
        }
    });

    widget->show();
}

void GraphicUserInterface::addDocumentary() {
    auto widget = new QWidget();
    auto VLayout = new QVBoxLayout();
    auto formLayout = new QFormLayout();
    auto addButton = new QPushButton("Add DOCUMENTARY");

    VLayout->addLayout(formLayout);
    VLayout->addWidget(addButton);
    widget->setLayout(VLayout);

    auto titleInput = new QLineEdit();
    formLayout->addRow("TITLE", titleInput);

    auto directorInput = new QLineEdit();
    formLayout->addRow("DIRECTOR", directorInput);

    auto genreInput = new QLineEdit();
    formLayout->addRow("GENRE", genreInput);

    auto descriptionInput = new QLineEdit();
    formLayout->addRow("DESCRIPTION", descriptionInput);

    auto ratingInput = new QSpinBox();
    ratingInput->setMinimum(0);
    formLayout->addRow("RATING", ratingInput);

    auto leadingActorInput = new QLineEdit();
    formLayout->addRow("LEADING ACTOR", leadingActorInput);

    auto streamingServiceInput = new QLineEdit();
    formLayout->addRow("STREAMING SERVICE", streamingServiceInput);


    QObject::connect(addButton, &QPushButton::clicked, [=]() {
        auto title = titleInput->text();
        auto director = directorInput->text();
        auto genre = genreInput->text();
        auto rating = ratingInput->value();
        auto description = descriptionInput->text();
        auto leadingActor = leadingActorInput->text();
        auto streamingService = streamingServiceInput->text();
        try {
            this->service.add("Documentary", title.toStdString(), director.toStdString(), genre.toStdString(), rating,
                              description.toStdString(), leadingActor.toStdString(), 0, "",
                              streamingService.toStdString());

            this->addToTable(this->service.getAll()[this->service.getAll().size() - 1]);
            this->adjustSize();
            widget->close();
        } catch (GenericException &exception) {
            auto messageBox = new QMessageBox();
            messageBox->setText(QString::fromStdString(exception.what()));
            messageBox->show();
        }
    });

    widget->show();
}


void GraphicUserInterface::addToTable(Object *object) {

    auto ID = new QLabel();
    ID->setStyleSheet("background-color: beige; color: black;");
    ID->setText(QString::fromStdString(std::to_string(((Movie *) object)->getID())));

    auto title = new QLabel();
    title->setText(QString::fromStdString(((Movie *) object)->getTitle()));
    title->setStyleSheet("background-color: beige; color: black;");

    auto director = new QLabel();
    director->setText(QString::fromStdString(((Movie *) object)->getDirector()));
    director->setStyleSheet("background-color: beige; color: black");

    auto genre = new QLabel();
    genre->setText(QString::fromStdString(((Movie *) object)->getGenre()));
    genre->setStyleSheet("background-color: beige; color: black");

    auto rating = new QLabel();
    rating->setText(QString::number(((Movie *) object)->getRating(), 'g', 3));
    rating->setStyleSheet("background-color: beige; color: black");

    auto description = new QLabel();
    description->setText(QString::fromStdString(((Movie *) object)->getDescription()));
    description->setStyleSheet("background-color: beige; color: black");

    auto leadingActor = new QLabel();
    leadingActor->setText(QString::fromStdString(((Movie *) object)->getLeadingActor()));
    leadingActor->setStyleSheet("background-color: beige; color: black");

    auto RemoveButton = new QPushButton("Remove");
    RemoveButton->setStyleSheet("background-color: green; color: white");
    QTableWidget *table = nullptr;

    if (auto f = dynamic_cast<TheatrePlay *>(object)) {
        table = tableOfTheatrePlays;
        tableOfTheatrePlays->setRowCount(tableOfTheatrePlays->rowCount() + 1);


        auto labelDuration = new QLabel();
        labelDuration->setStyleSheet("background-color: olive; color: white");
        labelDuration->setText(QString::fromStdString(std::to_string(((TheatrePlay *) object)->getDuration())));
        tableOfTheatrePlays->setCellWidget(tableOfTheatrePlays->rowCount() - 1, 7,
                                           labelDuration);

        auto theatreName = new QLabel();
        theatreName->setStyleSheet("background-color: olive; color: white;");
        theatreName->setText(QString::fromStdString(((TheatrePlay *) object)->getTheatreName()));

        tableOfTheatrePlays->setCellWidget(tableOfTheatrePlays->rowCount() - 1, 8,
                                           theatreName);
        tableOfTheatrePlays->setCellWidget(tableOfTheatrePlays->rowCount() - 1, 9,
                                           RemoveButton);
    } else if (auto documentary = dynamic_cast<Documentary *>(object)) {
        auto streamingServiceLabel = new QLabel(QString::fromStdString(documentary->getStreamingService()));
        streamingServiceLabel->setStyleSheet("background-color: maroon; color: white");
        table = tableOfDocumentaries;
        tableOfDocumentaries->setRowCount(table->rowCount() + 1);
        tableOfDocumentaries->setCellWidget(tableOfDocumentaries->rowCount() - 1, 7, streamingServiceLabel);
        tableOfDocumentaries->setCellWidget(tableOfDocumentaries->rowCount() - 1, 8, RemoveButton);
    } else if (dynamic_cast<Movie *>(object)) {
        table = tableOfMovies;
        tableOfMovies->setRowCount(table->rowCount() + 1);
        tableOfMovies->setCellWidget(tableOfMovies->rowCount() - 1, 7, RemoveButton);

    }
    auto currentRow = table->rowCount() - 1;

    table->setCellWidget(currentRow, 0, ID);
    table->setCellWidget(currentRow, 1, title);
    table->setCellWidget(currentRow, 2, director);
    table->setCellWidget(currentRow, 3, genre);
    table->setCellWidget(currentRow, 4, rating);
    table->setCellWidget(currentRow, 5, description);
    table->setCellWidget(currentRow, 6, leadingActor);

    QObject::connect(RemoveButton, &QPushButton::clicked,
                     [=]() {
                         this->service.remove(((Movie *) object)->getID());
                         table->removeRow(currentRow);
                         this->adjustSize();
                     });
}



