//
//

#include <cassert>
#include "Test.h"
#include "../Domain/Object.h"
#include "../Domain/Movie.h"
#include "../Domain/TheatrePlay.h"
#include "../Domain/Documentary.h"
#include "../Repository/Repository.h"
#include "../Repository/RepositoryInMemory.h"
#include "../Repository/FileRepository.h"
#include "../Service/Service.h"
#include "../Exceptions/GenericException.h"


void Test::testDomain() {

    /// DEFAULT CONSTRUCTOR

    Object *object = new Movie;
    assert(((Movie *) object)->getID() == 0);
    assert(((Movie *) object)->getTitle().empty());
    assert(((Movie *) object)->getDirector().empty());
    assert(((Movie *) object)->getGenre().empty());
    assert(abs(((Movie *) object)->getRating() - 0.0) < CONSTANT);
    assert(((Movie *) object)->getDescription().empty());
    assert(((Movie *) object)->getLeadingActor().empty());


    /// CONSTRUCTOR WITH PARAMETERS

    Object *movie = new Movie("The Pianist", "Roman Polanski", "Drama", 8.5,
                              "A Polish Jewish musician struggles to survive the destruction of the Warsaw ghetto.",
                              "Adrien Brody");

    /// GETTERS 

    string string1 = movie->toString();
    assert(movie->toString() == string1);
    assert(((Movie *) movie)->getID() == 1);
    assert(((Movie *) movie)->getTitle() == "The Pianist");
    assert(((Movie *) movie)->getDirector() == "Roman Polanski");
    assert(((Movie *) movie)->getGenre() == "Drama");
    assert(abs(((Movie *) movie)->getRating() - 8.5) <= CONSTANT);
    assert(((Movie *) movie)->getDescription() ==
           "A Polish Jewish musician struggles to survive the destruction of the Warsaw ghetto.");
    assert(((Movie *) movie)->getLeadingActor() == "Adrien Brody");


    /// SETTERS

    ((Movie *) object)->setTitle("Schindler's list");
    ((Movie *) object)->setDirector("Steven Spielberg");
    ((Movie *) object)->setGenre("Drama");
    ((Movie *) object)->setRating(8.9);
    ((Movie *) object)->setDescription("Oskar Schindler gradually becomes concerned for his"
                                       " Jewish workforce after witnessing"
                                       " their persecution by the Nazis.");
    ((Movie *) object)->setLeadingActor("Liam Neeson");
    assert(((Movie *) object)->getTitle() == "Schindler's list");
    assert(((Movie *) object)->getDirector() == "Steven Spielberg");
    assert(((Movie *) object)->getGenre() == "Drama");
    assert(abs(((Movie *) object)->getRating() - 8.9) <= CONSTANT);
    assert(((Movie *) object)->getDescription() == "Oskar Schindler gradually becomes concerned for his"
                                                   " Jewish workforce after witnessing"
                                                   " their persecution by the Nazis.");
    assert(((Movie *) object)->getLeadingActor() == "Liam Neeson");

    /// THEATRE PLAY

    /// CONSTRUCTOR WITH PARAMETERS

    Object *theatrePlay = new TheatrePlay("Tristan and Isolde", "Kevin Reynolds", "Romance", 6.8,
                                          "An affair between the second in line to Britain's throne and the "
                                          "princess of the feuding Irish spells doom for the young lovers.",
                                          "Sophia Myles", 2, "Odeon");

    /// GETTERS

    assert(((TheatrePlay *) theatrePlay)->getID() == 2);
    assert(((TheatrePlay *) theatrePlay)->getTitle() == "Tristan and Isolde");
    assert(((TheatrePlay *) theatrePlay)->getDirector() == "Kevin Reynolds");
    assert(((TheatrePlay *) theatrePlay)->getGenre() == "Romance");
    assert(abs(((TheatrePlay *) theatrePlay)->getRating() - 6.8) <= CONSTANT);
    assert(((TheatrePlay *) theatrePlay)->getDescription() ==
           "An affair between the second in line to Britain's throne and the "
           "princess of the feuding Irish spells doom for the young lovers.");
    assert(((TheatrePlay *) theatrePlay)->getLeadingActor() == "Sophia Myles");
    assert(((TheatrePlay *) theatrePlay)->getDuration() == 2);
    assert(((TheatrePlay *) theatrePlay)->getTheatreName() == "Odeon");


    /// SETTERS

    ((TheatrePlay *) theatrePlay)->setDuration(3);
    ((TheatrePlay *) theatrePlay)->setTheatreName("Arabela");
    assert(((TheatrePlay *) theatrePlay)->getDuration() == 3);
    assert(((TheatrePlay *) theatrePlay)->getTheatreName() == "Arabela");

    delete theatrePlay;
    delete movie;

    /// DOCUMENTARY

    /// CONSTRUCTOR WITH PARAMETERS

    Object *documentary = new Documentary("Unorthodox", "Anna Winger", "Drama", 8.0,
                                          "Story of a Jewish woman who flees her "
                                          "arranged marriage and religious community to start a new life.",
                                          "Shira Haas", "Netflix");
    /// GETTERS

    assert(((Documentary *) documentary)->getID() == 3);
    assert(((Documentary *) documentary)->getTitle() == "Unorthodox");
    assert(((Documentary *) documentary)->getDirector() == "Anna Winger");
    assert(((Documentary *) documentary)->getGenre() == "Drama");
    assert(abs(((Documentary *) documentary)->getRating() - 8.0) <= CONSTANT);
    assert(((Documentary *) documentary)->getDescription() ==
           "Story of a Jewish woman who flees her "
           "arranged marriage and religious community to start a new life.");
    assert(((Documentary *) documentary)->getLeadingActor() == "Shira Haas");
    assert(((Documentary *) documentary)->getStreamingService() == "Netflix");

    /// SETTERS
    ((Documentary *) documentary)->setStreamingService("HBO");
    assert(((Documentary *) documentary)->getStreamingService() == "HBO");
}


void Test::testRepositoryInMemory() {
    Repository *repository = new RepositoryInMemory();
    Object *movie = new Movie("The Pianist", "Roman Polanski", "Drama", 8.5,
                              "A Polish Jewish musician struggles to survive the destruction of the Warsaw ghetto.",
                              "Adrien Brody");
    Object *theatrePlay = new TheatrePlay("Tristan and Isolde", "Kevin Reynolds", "Romance", 6.8,
                                          "An affair between the second in line to Britain's throne and the "
                                          "princess of the feuding Irish spells doom for the young lovers.",
                                          "Sophia Myles", 2, "Odeon");
    Object *documentary = new Documentary("Unorthodox", "Anna Winger", "Drama", 8.0,
                                          "Story of a Jewish woman who flees her "
                                          "arranged marriage and religious community to start a new life.",
                                          "Shira Haas", "Netflix");
    /// ADD
    repository->add(movie);
    repository->add(theatrePlay);
    repository->add(documentary);

    /// GET SIZE
    assert(repository->getSize() == 3);

    /// REMOVE
    repository->remove(6);
    try {
        repository->remove(200);
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

    assert(repository->getSize() == 2);

    /// UPDATE & GET FROM

    repository->update(5, 7.0, "Compelling and moving");
    assert(abs(((TheatrePlay *) repository->getFrom(1))->getRating() - 7.0) < CONSTANT);
    assert(((TheatrePlay *) repository->getFrom(1))->getDescription() == "Compelling and moving");

    /// EXCEPTIONS

    try {
        repository->update(200, -1, "");
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

}

void Test::testFileRepository() {

    auto *cleaner = new FileRepository(R"(D:\OneDrive\Desktop\finalProject\testMasterpieces.csv)");
    cleaner->clearFile();
    auto *fileRepository = new FileRepository(R"(D:\OneDrive\Desktop\finalProject\testMasterpieces.csv)");


    /// CLEAR

    /// GET FILE NAME

    assert(fileRepository->getFileName() == R"(D:\OneDrive\Desktop\finalProject\testMasterpieces.csv)");
    Object *movie = new Movie("Schindler's list", "Steven Spielberg", "Drama", 8.9,
                              "Oskar Schindler gradually becomes concerned for his Jewish workforce after "
                              "witnessing their persecution by the Nazis.",
                              "Liam Neeson");

    Object *theatrePlay = new TheatrePlay("Tristan and Isolde", "Kevin Reynolds", "Romance", 6.8,
                                          "An affair between the second in line to Britain's throne and the "
                                          "princess of the feuding Irish spells doom for the young lovers.",
                                          "Sophia Myles", 2, "Odeon");

    Object *documentary = new Documentary("Unorthodox", "Anna Winger", "Drama", 8.0,
                                          "Story of a Jewish woman who flees her "
                                          "arranged marriage and religious community to start a new life.",
                                          "Shira Haas", "Netflix");
    /// ADD
    fileRepository->add(movie);
    fileRepository->add(theatrePlay);
    fileRepository->add(documentary);

    assert(fileRepository->getSize() == 3);

    /// GET FROM
    assert(((Movie *) fileRepository->getFrom(0))->getTitle() == "Schindler's list");
    assert(((Movie *) fileRepository->getFrom(0))->getDirector() == "Steven Spielberg");
    assert(((Movie *) fileRepository->getFrom(0))->getGenre() == "Drama");
    assert(abs(((Movie *) fileRepository->getFrom(0))->getRating() - 8.9) < CONSTANT);
    assert(((Movie *) fileRepository->getFrom(0))->getDescription() ==
           "Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.");
    assert(((Movie *) fileRepository->getFrom(0))->getLeadingActor() == "Liam Neeson");

    /// UPDATE

    fileRepository->update(11, 6.7, "Compelling and enthralling");

    /// GET ALL

    assert(((Movie *) fileRepository->getAll()[0])->getTitle() == "Schindler's list");
    assert(((Movie *) fileRepository->getAll()[0])->getDirector() == "Steven Spielberg");
    assert(((Movie *) fileRepository->getAll()[0])->getGenre() == "Drama");
    assert(abs(((Movie *) fileRepository->getAll()[0])->getRating() - 8.9) < CONSTANT);
    assert(((Movie *) fileRepository->getAll()[0])->getDescription() ==
           "Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.");
    assert(((Movie *) fileRepository->getAll()[0])->getLeadingActor() == "Liam Neeson");

    assert(((TheatrePlay *) fileRepository->getAll()[1])->getTitle() == "Tristan and Isolde");
    assert(((TheatrePlay *) fileRepository->getAll()[1])->getDirector() == "Kevin Reynolds");
    assert(((TheatrePlay *) fileRepository->getAll()[1])->getGenre() == "Romance");
    assert(abs(((TheatrePlay *) fileRepository->getAll()[1])->getRating() - 6.7) <= CONSTANT);
    assert(((TheatrePlay *) fileRepository->getAll()[1])->getDescription() ==
           "Compelling and enthralling");
    assert(((TheatrePlay *) fileRepository->getAll()[1])->getLeadingActor() == "Sophia Myles");
    assert(((TheatrePlay *) fileRepository->getAll()[1])->getDuration() == 2);
    assert(((TheatrePlay *) fileRepository->getAll()[1])->getTheatreName() == "Odeon");

    assert(((Documentary *) fileRepository->getAll()[2])->getTitle() == "Unorthodox");
    assert(((Documentary *) fileRepository->getAll()[2])->getDirector() == "Anna Winger");
    assert(((Documentary *) fileRepository->getAll()[2])->getGenre() == "Drama");
    assert(abs(((Documentary *) fileRepository->getAll()[2])->getRating() - 8.0) <= CONSTANT);
    assert(((Documentary *) fileRepository->getAll()[2])->getDescription() ==
           "Story of a Jewish woman who flees her "
           "arranged marriage and religious community to start a new life.");
    assert(((Documentary *) fileRepository->getAll()[2])->getLeadingActor() == "Shira Haas");
    assert(((Documentary *) fileRepository->getAll()[2])->getStreamingService() == "Netflix");

    /// EXCEPTIONS

    /// REMOVE

    try {
        fileRepository->remove(200);
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

    try {
        fileRepository->update(200, -1, "");
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }


    delete documentary;
    delete theatrePlay;
    delete movie;
    delete fileRepository;
    delete cleaner;
}

void Test::testService() {
    auto *repository = new RepositoryInMemory;
    Service service(repository);

    /// ADD
    service.add("Movie", "Schindler's list", "Steven Spielberg", "Drama", 8.9,
                "Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.",
                "Liam Neeson", 0, "", "");
    service.add("Theatre Play", "Tristan and Isolde", "Kevin Reynolds", "Romance", 6.8,
                "An affair between the second in line to Britain's throne and the "
                "princess of the feuding Irish spells doom for the young lovers.",
                "Sophia Myles", 2, "Odeon", "");
    service.add("Documentary", "Unorthodox", "Anna Winger", "Drama", 8.0,
                "Story of a Jewish woman who flees her arranged marriage and religious community to start a new life.",
                "Shira Haas", 0, "", "Netflix");

    /// GET FROM

    assert(((Movie *) service.getFrom(0))->getTitle() == "Schindler's list");
    assert(((Movie *) service.getFrom(0))->getDirector() == "Steven Spielberg");
    assert(((Movie *) service.getFrom(0))->getGenre() == "Drama");
    assert(abs(((Movie *) service.getFrom(0))->getRating() - 8.9) < CONSTANT);
    assert(((Movie *) service.getFrom(0))->getDescription() ==
           "Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.");
    assert(((Movie *) service.getFrom(0))->getLeadingActor() == "Liam Neeson");

    /// GET SIZE
    assert(service.getSize() == 3);

    assert(((Movie *) service.getAll()[0])->getTitle() == "Schindler's list");
    assert(((Movie *) service.getAll()[0])->getDirector() == "Steven Spielberg");
    assert(((Movie *) service.getAll()[0])->getGenre() == "Drama");
    assert(abs(((Movie *) service.getAll()[0])->getRating() - 8.9) < CONSTANT);
    assert(((Movie *) service.getAll()[0])->getDescription() ==
           "Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.");
    assert(((Movie *) service.getAll()[0])->getLeadingActor() == "Liam Neeson");

    assert(((TheatrePlay *) service.getAll()[1])->getTitle() == "Tristan and Isolde");
    assert(((TheatrePlay *) service.getAll()[1])->getDirector() == "Kevin Reynolds");
    assert(((TheatrePlay *) service.getAll()[1])->getGenre() == "Romance");
    assert(abs(((TheatrePlay *) service.getAll()[1])->getRating() - 6.8) <= CONSTANT);
    assert(((TheatrePlay *) service.getAll()[1])->getDescription() ==
           "An affair between the second in line to Britain's throne and the "
           "princess of the feuding Irish spells doom for the young lovers.");
    assert(((TheatrePlay *) service.getAll()[1])->getLeadingActor() == "Sophia Myles");
    assert(((TheatrePlay *) service.getAll()[1])->getDuration() == 2);
    assert(((TheatrePlay *) service.getAll()[1])->getTheatreName() == "Odeon");

    assert(((Documentary *) service.getAll()[2])->getTitle() == "Unorthodox");
    assert(((Documentary *) service.getAll()[2])->getDirector() == "Anna Winger");
    assert(((Documentary *) service.getAll()[2])->getGenre() == "Drama");
    assert(abs(((Documentary *) service.getAll()[2])->getRating() - 8.0) <= CONSTANT);
    assert(((Documentary *) service.getAll()[2])->getDescription() ==
           "Story of a Jewish woman who flees her "
           "arranged marriage and religious community to start a new life.");
    assert(((Documentary *) service.getAll()[2])->getLeadingActor() == "Shira Haas");
    assert(((Documentary *) service.getAll()[2])->getStreamingService() == "Netflix");

    /// SEARCH - TITLE

    service.update(14, 6.8, "Enthralling");
    assert(((TheatrePlay *) service.getFrom(1))->getDescription() == "Enthralling");
    assert(abs(((TheatrePlay *) service.getFrom(1))->getRating() - 6.8) <= CONSTANT);
    assert(service.searchFilmographicPiecesWithAGivenTitle("Schindler's list").size() == 1);
    assert(((Movie *) service.searchFilmographicPiecesWithAGivenTitle("Schindler's list")[0])->getTitle() ==
           "Schindler's list");

    /// SEARCH - GENRE

    assert(service.searchFilmographicPiecesWithAGivenGenre("Drama").size() == 2);
    assert(((Movie *) service.searchFilmographicPiecesWithAGivenGenre("Drama")[0])->getGenre() == "Drama");
    assert(((Documentary *) service.searchFilmographicPiecesWithAGivenGenre("Drama")[1])->getGenre() == "Drama");

    /// SEARCH - LEADING ACTOR
    assert(service.searchFilmographicPiecesWithAGivenLeadingActor("Shira Haas").size() == 1);
    assert(((Documentary *) service.searchFilmographicPiecesWithAGivenLeadingActor(
            "Shira Haas")[0])->getLeadingActor() == "Shira Haas");

    /// SORT

    vector<Object *> sortedPieces = service.createARankingOfFilmographicPieces();
    assert(abs(((Movie *) sortedPieces[0])->getRating() - 8.9) < CONSTANT);
    assert(abs(((Documentary *) sortedPieces[1])->getRating() - 8.0) < CONSTANT);
    assert(abs(((TheatrePlay *) sortedPieces[2])->getRating() - 6.8) < CONSTANT);

    /// FILTER - GENRE

    service.filterFilmographicPiecesWithAGivenGenre("Drama");
    assert(service.getSize() == 2);
    assert(((Movie *) service.getFrom(0))->getGenre() == "Drama");
    assert(((Documentary *) service.getFrom(1))->getGenre() == "Drama");


    /// FILTER - > RATING

    service.filterFilmographicPieceswithAratingGreaterThanAGivenOne(8.0);
    assert(service.getSize() == 1);
    assert(abs(((Movie *) service.getFrom(0))->getRating() - 8.9) < CONSTANT);


    /// EXCEPTIONS

    /// ADD

    try {
        service.add("Movie", "Schindler's list", "1", "Dramatic", -2,
                    "Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.",
                    "Liam Neeson", 0, "", "");
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

    /// REMOVE

    try {
        service.remove(200);
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

    /// UPDATE

    try {
        service.update(200, -1, "");
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

    /// SEARCHES

    try {
        service.searchFilmographicPiecesWithAGivenTitle("The Age of Adaline");
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

    try {
        service.searchFilmographicPiecesWithAGivenGenre("Film Noir");
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

    try {
        service.searchFilmographicPiecesWithAGivenLeadingActor("Meryl Streep");
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }


    /// FILTERS

    try {
        service.filterFilmographicPiecesWithAGivenGenre("Comedy");
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }

    try {
        service.filterFilmographicPieceswithAratingGreaterThanAGivenOne(-1);
        assert(false);
    }
    catch (GenericException &) {
        assert(true);
    }
}

void Test::runAllTests() {

    testDomain();
    testRepositoryInMemory();
    testFileRepository();
    testService();
    cout << "All tests have passed successfully!\n" << endl;
}