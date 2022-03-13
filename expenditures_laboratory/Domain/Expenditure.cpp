//
//

#include <cstring>
#include "Expenditure.h"

Expenditure::Expenditure() {
    /// default constructor

    day = 0;
    sum = 0;
    type = nullptr;
}

Expenditure::Expenditure(unsigned int day, unsigned int sum, const char *type) {
    /// constructor with parametres
    /// input  day - unsigned int
    /// input  sum - unsigned int
    /// input  type - const char

    this->day = day;
    this->sum = sum;
    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);
}

Expenditure::Expenditure(const Expenditure &expenditure) {
    /// copy constructor
    /// input - const Expenditure &expenditure
    day = expenditure.day;
    sum = expenditure.sum;
    if (type) {
        delete[] type;
        type = nullptr;
    }
    type = new char[strlen(expenditure.type) + 1];
    strcpy_s(type, strlen(expenditure.type) + 1, expenditure.type);

}

Expenditure::~Expenditure() {
    /// destructor

    day = 0;
    sum = 0;
    if (type) {
        delete[] type;
        type = nullptr;
    }
}

Expenditure &Expenditure::operator=(const Expenditure &expenditure) {
    /// overloads the assign operator
    /// input - const Expenditure &expenditure
    /// output - Expenditure & - *this

    if (this != &expenditure) {
        day = expenditure.day;
        sum = expenditure.sum;
        if (type) {
            delete[] type;
            type = nullptr;
        }
        type = new char[strlen(expenditure.type) + 1];
        strcpy_s(type, strlen(expenditure.type) + 1, expenditure.type);
    }
    return *this;
}

unsigned int Expenditure::getDay() const {
    /// getter for day
    /// output - day - unsigned int

    return day;
}

unsigned int Expenditure::getSum() const {
    /// getter for sum
    /// output - sum - unsigned int

    return sum;
}

char *Expenditure::getType() const {
    /// getter for type
    /// output - type - char *

    return type;
}

void Expenditure::setDay(unsigned int newDay) {
    /// setter for day
    /// intput - day - unsigned int

    day = newDay;
}

void Expenditure::setSum(unsigned int newSum) {
    /// setter for sum
    /// input - sum - unsigned int

    sum = newSum;
}

void Expenditure::setType(const char *newType) {
    /// setter for type
    /// input - type - const char *

    if (type) {
        delete[] type;
        type = nullptr;
    }
    type = new char[strlen(newType) + 1];
    strcpy_s(type, strlen(newType) + 1, newType);
}

bool Expenditure::operator==(const Expenditure &expenditure) const {
    /// overloads the == operator
    /// input - const Expenditure &expenditure
    /// output - bool - true/false

    return (day == expenditure.day && sum == expenditure.sum && strcmp(type, expenditure.type) == 0);
}

istream &operator>>(istream &in, Expenditure &expenditure) {
    /// overloads the stream >> operator
    /// input - istream &in
    /// input - Expenditure &expenditure

    cout << "Give the day of the expenditure" << endl;
    unsigned int day;
    in >> day;
    cout << "Give the sum of the expenditure" << endl;
    unsigned int sum;
    in >> sum;
    cout << "Give the type of the expenditure" << endl;
    char *type = new char[15];
    in >> type;
    expenditure.setDay(day);
    expenditure.setSum(sum);
    expenditure.setType(type);
    delete[] type;
    return in;
}

ostream &operator<<(ostream &out, Expenditure &expenditure) {
    /// overloads the stream << operator
    /// input - ostream &out
    /// input - Expenditure &expenditure

    out << "EXPENDITURE: " << "DAY: " << expenditure.day << " SUM: " << expenditure.sum << " TYPE: " << expenditure.type
        << endl;
    return out;
}