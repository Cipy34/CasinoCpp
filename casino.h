//
// Created by Ciprian on 13.04.2023.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef OOP_LAB2_CASINO_H
#define OOP_LAB2_CASINO_H
class Casino{
private:
    string location, name;
    int nrseats;
public:
    Casino();
    Casino(const string location_, const string name_, int nrseats_);
    Casino(const Casino &rhs);

    friend std::istream &operator>>(std::istream &in, Casino &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Casino &rhs);

    bool operator != (const Casino &rhs);
    bool operator == (const Casino &rhs);

    void setLocation(const string location_);
    void setName(const string name_);
    void setNrseats(int nrseats_);

    Casino &operator = (const Casino &rhs);

    [[nodiscard]] string getLocation()const;
    [[nodiscard]] string getName()const;
    [[nodiscard]] int getNrseats()const;
};
#endif //OOP_LAB2_CASINO_H
