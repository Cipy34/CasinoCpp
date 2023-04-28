//
// Created by Ciprian on 13.04.2023.
//
#include <iostream>
#include <string>
#include "casino.h"
using namespace std;

Casino::Casino(){
    location = "";
    name = "";
    nrseats = 0;
}

Casino::Casino(const string& location_, const string& name_, const int nrseats_){
    location = location_;
    name = name_;
    nrseats = nrseats_;
}

Casino::Casino(const Casino &rhs){
    location = rhs.location;
    name = rhs.name;
    nrseats = rhs.nrseats;
}

bool Casino::operator == (const Casino &rhs){
    return location == rhs.location || name == rhs.name || nrseats == rhs.nrseats;
}
bool Casino::operator != (const Casino &rhs){
    return location != rhs.location || name != rhs.name || nrseats != rhs.nrseats;
}

void Casino::setLocation(const string& location_){
    location = location_;
}
void Casino::setName(const string& name_){
    name = name_;
}
void Casino::setNrseats(const int nrseats_){
    nrseats = nrseats_;
}

Casino &Casino::operator = (const Casino &rhs){
    setLocation(rhs.location);
    setName(rhs.name);
    setNrseats(rhs.nrseats);
    return *this;
}

string Casino::getLocation() const{
    return location;
}

string Casino::getName() const{
    return name;
}

int Casino::getNrseats()const{
    return nrseats;
}
istream &operator>>(std::istream &is, Casino &rhs)
{
    string name_, location_;
    int nrseats_;

    cout<<"Name:";
    is>>name_;

    cout<<"Location:";
    is>>location_;

    std::cout<<"Nrseats:";
    is>>nrseats_;

    rhs.setName(name_);
    rhs.setLocation(location_);
    rhs.setNrseats(nrseats_);

    return is;
}
ostream &operator << (std::ostream & os, const Casino & rhs){
    os<<"Name : "<<rhs.name<<", Location : "<<rhs.location<<", Available seats : "<<rhs.nrseats<<"\n";
    return os;
}