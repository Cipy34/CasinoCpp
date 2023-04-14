//
// Created by Ciprian on 12.04.2023.
//
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

Player::Player(){
    name = "";
    age = 0;
    money = 0;
    alcohol = 0;
    thirsty = 0;
}
Player::Player(const string &name_, const int age_, const int money_, const int alcohol_, const int thirsty_){
    name = name_;
    age = age_;
    money = money_;
    alcohol = alcohol_;
    thirsty = thirsty_;
}

Player::Player(const Player &rhs)
{
    name = rhs.name;
    age = rhs.age;
    money = rhs.money;
    alcohol = rhs.alcohol;
    thirsty = rhs.thirsty;
}

bool Player::operator != (const Player &rhs)
const {
    return name != rhs.name || age != rhs.age || money != rhs.money || alcohol != rhs.alcohol || thirsty != rhs.thirsty;
}

bool Player::operator == (const Player &rhs)
const {
    return name == rhs.name || age == rhs.age || money == rhs.money || alcohol == rhs.alcohol || thirsty == rhs.thirsty;
}

Player &Player::operator = (const Player &rhs)
{
        setName(rhs.name);
        setAge(rhs.age);
        setMoney(rhs.money);
        setAlcohol(rhs.alcohol);
        setThirsty(rhs.thirsty);
    return *this;
}

void Player::setName(const string &name_){
    name = name_;
}
void Player::setAge(const int age_){
    age = age_;
}
void Player::setMoney(const int money_){
    money = money_;
}
void Player::setAlcohol(const int alcohol_){
    alcohol = alcohol_;
}
void Player::setThirsty(const int thirsty_){
    thirsty = thirsty_;
}

string Player::getName()
const {
    return name;
}

int Player::getAge()
const {
    return age;
}

int Player::getMoney()
const {
    return money;
}

int Player::getAlcohol()
const {
    return alcohol;
}

int Player::getThirsty()
const {
    return thirsty;
}


ostream &operator << (std::ostream & os, const Player & rhs)
{
    os<<"Hello! My name is "<<rhs.name<<", I am "<<rhs.age<<" years old and I have "<<rhs.money<<"$"<<"\n";
    return os;
}

istream &operator>>(std::istream &is, Player &rhs)
{
    string name_;
    int age_, money_;

    cout<<"Name:";
    is>>name_;

    cout<<"Age:";
    is>>age_;

    std::cout<<"Money:";
    is>>money_;

    rhs.setName(name_);
    rhs.setAge(age_);
    rhs.setMoney(money_);

    return is;
}