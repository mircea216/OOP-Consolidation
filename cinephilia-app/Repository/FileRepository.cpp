//
//

#include "FileRepository.h"

bool FileRepository::isEmpty(ifstream &pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}


void FileRepository::loadFromFile() {
    ifstream f(fileName);
    string line;
    string delimiter = ",";
    int position;
    if (isEmpty(f))
        return;
    if (f.is_open()) {
        while (getline(f, line)) {
            position = line.find(delimiter);
            string type = line.substr(0, position);
            line = line.erase(0, position + 1);
            if (type == "Movie") {
                position = line.find(delimiter);
                string title = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                string director = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                string genre = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                double rating = stod(line.substr(0, position));
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                string description = line.substr(0, position);
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                string leadingActor = line.substr(0, position);
                line = line.erase(0, position + 1);

                Object *object = new Movie(title, director, genre, rating, description, leadingActor);
                storage.push_back(object);
            } else if (type == "Theatre Play") {
                position = line.find(delimiter);
                string title = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                string director = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                string genre = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                double rating = stod(line.substr(0, position));
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                string description = line.substr(0, position);
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                string leadingActor = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                int duration = stoi(line.substr(0, position));
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                string theatreName = line.substr(0, position);
                line = line.erase(0, position + 1);

                Object *object = new TheatrePlay(title, director, genre, rating, description, leadingActor, duration,
                                                 theatreName);
                storage.push_back(object);

            } else if (type == "Documentary") {
                position = line.find(delimiter);
                string title = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                string director = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                string genre = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                double rating = stod(line.substr(0, position));
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                string description = line.substr(0, position);
                line = line.erase(0, position + 1);


                position = line.find(delimiter);
                string leadingActor = line.substr(0, position);
                line = line.erase(0, position + 1);

                position = line.find(delimiter);
                string streamingService = line.substr(0, position);
                line = line.erase(0, position + 1);

                Object *object = new Documentary(title, director, genre, rating, description, leadingActor,
                                                 streamingService);
                storage.push_back(object);

            }
        }
    }
    f.close();
}


void FileRepository::saveTofile() {
    ofstream f(fileName);
    if (f.is_open()) {
        for (auto *&object:storage) {
            if (typeid(*object) == typeid(Movie)) {
                f << "Movie," << ((Movie *) object)->getTitle() << "," << ((Movie *) object)->getDirector() << ","
                  << ((Movie *) object)->getGenre() << "," << ((Movie *) object)->getRating() << ","
                  << ((Movie *) object)->getDescription() << "," << ((Movie *) object)->getLeadingActor() << ","
                  << endl;
            } else if (typeid(*object) == typeid(TheatrePlay)) {
                f << "Theatre Play," << ((Movie *) object)->getTitle() << "," << ((TheatrePlay *) object)->getDirector()
                  << "," << ((TheatrePlay *) object)->getGenre() << "," << ((TheatrePlay *) object)->getRating() << ","
                  << ((TheatrePlay *) object)->getDescription() << "," << ((TheatrePlay *) object)->getLeadingActor()
                  << ","
                  << ((TheatrePlay *) object)->getDuration() << "," << ((TheatrePlay *) object)->getTheatreName() << ","
                  << endl;
            } else if (typeid(*object) == typeid(Documentary)) {
                f << "Documentary," << ((Documentary *) object)->getTitle() << ","
                  << ((Documentary *) object)->getDirector() << "," << ((Documentary *) object)->getGenre() << ","
                  << ((Documentary *) object)->getRating() << ","
                  << ((Documentary *) object)->getDescription() << "," << ((Documentary *) object)->getLeadingActor()
                  << "," << ((Documentary *) object)->getStreamingService() << "," << endl;
            }
        }
    }
    f.close();
}

FileRepository::FileRepository(const string &fileName) {
    this->fileName = fileName;
    loadFromFile();
}

void FileRepository::add(Object *object) {
    RepositoryInMemory::add(object);
    saveTofile();
}

void FileRepository::remove(unsigned int givenID) {
    RepositoryInMemory::remove(givenID);
    saveTofile();

}

void FileRepository::update(unsigned int givenID, double newRating, const string &newDescription) {
    RepositoryInMemory::update(givenID, newRating, newDescription);
    saveTofile();

}

unsigned int FileRepository::getSize() {
    return RepositoryInMemory::getSize();
}

vector<Object *> FileRepository::getAll() {
    return RepositoryInMemory::getAll();
}

Object *FileRepository::getFrom(unsigned int position) {
    return RepositoryInMemory::getFrom(position);
}


string FileRepository::getFileName() const {
    return fileName;
}

void FileRepository::clearFile() {
    ofstream f(fileName);
    f.close();
}