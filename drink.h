//
// Created by Ciprian on 13.04.2023.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef OOP_LAB2_DRINK_H
#define OOP_LAB2_DRINK_H
class Drink{
private:
    string name;
    int alcohol, price, thirsty;
public:
    Drink();
    Drink(const string name, int alcohol, int thirsty, int price);
    Drink(const Drink &rhs);

    bool operator != (const Drink &rhs);
    bool operator == (const Drink &rhs);

    void setName(const string name_);
    void setAlcohol(int alcohol_);
    void setThirsty(int thirsty_);
    void setPrice(int price_);

    Drink &operator = (const Drink &rhs);

    [[nodiscard]] string getName()const;
    [[nodiscard]] int getAlcohol()const;
    [[nodiscard]] int getThirsty()const;
    [[nodiscard]] int getPrice()const;

    friend istream &operator>>(istream &in, Drink &rhs);
    friend ostream &operator<<(ostream &out, const Drink &rhs);

};
#endif //OOP_LAB2_DRINK_H
