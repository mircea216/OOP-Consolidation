//
//

#ifndef LAB_07_EXPENDITURE_H
#define LAB_07_EXPENDITURE_H

#include <iostream>

using namespace std;

class Expenditure {
private:
    unsigned int day;
    unsigned int sum;
    char *type;
public:
    Expenditure();

    Expenditure(unsigned int day, unsigned int sum, const char *type);

    Expenditure(const Expenditure &expenditure);

    ~Expenditure();

    Expenditure &operator=(const Expenditure &expenditure);

    unsigned int getDay() const;

    unsigned int getSum() const;

    char *getType() const;

    void setDay(unsigned int newDay);

    void setSum(unsigned int newSum);

    void setType(const char *newType);

    bool operator==(const Expenditure &expenditure) const;

    friend istream &operator>>(istream &in, Expenditure &expenditure);

    friend ostream &operator<<(ostream &out, Expenditure &expenditure);

};


#endif //LAB_07_EXPENDITURE_H
