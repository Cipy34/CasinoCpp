//
// Created by Ciprian on 13.04.2023.
//
#include <iostream>
#include <string>
#include "drink.h"
using namespace std;

Drink::Drink(){
    name = "";
    alcohol = 0;
    thirsty =0;
    price = 0;
}

Drink::Drink(const string &name_, const int alcohol_, const int thirsty_, const int price_){
    name = name_;
    alcohol = alcohol_;
    thirsty = thirsty_;
    price = price_;
}

Drink::Drink(const Drink &rhs){
    name = rhs.name;
    alcohol = rhs.alcohol;
    thirsty = rhs.thirsty;
    price = rhs.price;
}

bool Drink::operator!=(const Drink &rhs){
    return name != rhs.name || alcohol != rhs.alcohol || thirsty != rhs.thirsty || price != rhs.price;
}

bool Drink::operator==(const Drink &rhs){
    return name == rhs.name || alcohol == rhs.alcohol || thirsty == rhs.thirsty || price == rhs.price;
}

void Drink::setName(const string &name_){
    name = name_;
}
void Drink::setAlcohol(const int alcohol_){
    alcohol = alcohol_;
}
void Drink::setThirsty(const int thirsty_){
    thirsty = thirsty_;
}
void Drink::setPrice(const int price_){
    price = price_;
}

Drink &Drink::operator=(const Drink &rhs){
    if(this != &rhs)
    {
        setName(rhs.name);
        setAlcohol(rhs.alcohol);
        setThirsty(rhs.thirsty);
        setPrice(rhs.price);
    }
    return *this;
}

string Drink::getName() const{
    return name;
}
int Drink::getAlcohol() const{
    return alcohol;
}
int Drink::getThirsty() const{
    return thirsty;
}
int Drink::getPrice() const{
    return price;
}

istream &operator>>(std::istream &is, Drink &rhs)
{
    string name_;
    int thirsty_, price_, alcohol_;

    cout<<"Name:";
    is>>name_;

    cout<<"Price $:";
    is>>price_;

    cout<<"Thirsty lvl :";
    is>>thirsty_;

    cout<<"Alcohol lvl : ";
    is>>alcohol_;

    rhs.setName(name_);
    rhs.setPrice(price_);
    rhs.setThirsty(thirsty_);
    rhs.setAlcohol(alcohol_);

    return is;
}
ostream &operator << (std::ostream & os, const Drink & rhs){
    os<<"Name : "<<rhs.name<<", Price : $"<<rhs.price<<", Thirsty lvl : "<<rhs.getThirsty()<<"Alcohol lvl : "<<rhs.alcohol<<"\n";
    return os;
}