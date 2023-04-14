//
// Created by Ciprian on 12.04.2023.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef OOP_LAB2_PLAYER_H
#define OOP_LAB2_PLAYER_H
class Player {
private:
    string name;
    int age, money, alcohol, thirsty;;
public:
    Player();
    Player(const string& name_, int age_, int money_, int alcohol_, int thirsty_);
    Player(const Player &rhs);
    Player &operator = (const Player &rhs);

    bool operator != (const Player &rhs) const;
    bool operator == (const Player &rhs) const;

    friend std::ostream &operator<<(std::ostream &out, const Player &rhs);
    friend std::istream &operator>>(std::istream &in, Player &rhs);

    void setName(const string &name_);
    void setAge(int age_);
    void setMoney(int money_);
    void setAlcohol(int alcohol_);
    void setThirsty(int thirsty_);

    [[nodiscard]] string getName() const;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] int getMoney() const;
    [[nodiscard]] int getAlcohol() const;
    [[nodiscard]] int getThirsty() const;
};
#endif //OOP_LAB2_PLAYER_H
