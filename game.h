//
// Created by Ciprian on 13.04.2023.
//
#include <iostream>
#include <string>
#include "slot.h"
#ifndef OOP_LAB2_GAME_H
#define OOP_LAB2_GAME_H
using namespace std;
class Game : public Slot{
private:
    string name;
    int chance, win;
public:
    Game();
    Game(const string name_, int chance_, int win_);
    Game(const Game &rhs);

    bool operator != (const Game &rhs);
    bool operator == (const Game &rhs);

    void setName(const string name_);
    void setChance(int chance_);
    void setWin(int win_);

    Game &operator = (const Game &rhs);

    [[nodiscard]] string getName() const;
    [[nodiscard]] int getChance() const;
    [[nodiscard]] int getWin() const;

    friend istream &operator>>(istream &in, Game &rhs);
    friend ostream &operator<<(ostream &out, const Game &rhs);
};
#endif //OOP_LAB2_GAME_H
