//
//

#include "FileRepository.h"

FileRepository::FileRepository(const string &fileName) {
    this->fileName = fileName;
    loadFromFile();
}

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
            string clientName = line.substr(0, position);
            line = line.erase(0, position + 1);

            position = line.find(delimiter);
            int time = stoi(line.substr(0, position));
            line = line.erase(0, position + 1);

            position = line.find(delimiter);
            double price = stod(line.substr(0, position));
            line = line.erase(0, position + 1);

            position = line.find(delimiter);
            unsigned int day = stoi(line.substr(0, position));
            line = line.erase(0, position + 1);

            Order order(clientName, time, price, day);
            storage.push_back(order);
        }
    }
    f.close();
}


void FileRepository::saveTofile() {
    ofstream f(fileName);
    if (f.is_open()) {
        for (const Order &order:getAll()) {
            f << order.getClientName() << "," << order.getTime() << "," << order.getPrice() << "," << order.getDay()
              << "," << endl;
        }
    }
    f.close();

}

void FileRepository::add(Order &order) {
    Repository::add(order);
    saveTofile();
}

void FileRepository::remove(unsigned int givenCode) {
    Repository::remove(givenCode);
    saveTofile();
}

void FileRepository::update(unsigned int givenCode, int newTime) {
    Repository::update(givenCode, newTime);
    saveTofile();

}

vector<Order> FileRepository::getAll() {
    return Repository::getAll();
}

unsigned int FileRepository::getSize() const {
    return Repository::getSize();
}

Order FileRepository::getFrom(unsigned int position) {
    return Repository::getFrom(position);
}

void FileRepository::doClear() {
    ofstream f(fileName);
    f.close();
}

string FileRepository::getFileName() const {
    return fileName;
}