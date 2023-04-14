//
// Created by Ciprian on 13.04.2023.
//
#include <iostream>
#include <vector>
using namespace std;
#ifndef OOP_LAB2_SLOT_H
#define OOP_LAB2_SLOT_H
class Slot{
private:
    bool gamble;
    int bet;
    vector <int> line;
public:
    Slot();
    Slot(bool gamble_, vector <int> line_, int bet_);
    Slot(const Slot &rhs);

    bool operator != (const Slot &rhs);
    bool operator == (const Slot &rhs);

    void setGamble(bool gamble_);
    void setLine(vector <int> line_);
    void setBet(int bet_);

    Slot &operator = (const Slot &rhs);

    [[nodiscard]] bool getGamble()const;
    [[nodiscard]] int getLine()const;
    [[nodiscard]] int getBet()const;

    friend std::ostream &operator<<(std::ostream &out, const Slot &rhs);
};
#endif //OOP_LAB2_SLOT_H
