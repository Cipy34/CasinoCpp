//
// Created by Ciprian on 13.04.2023.
//
#include <iostream>
#include <vector>
#include "slot.h"
using namespace std;
Slot::Slot(){
    gamble = 0;
    bet = 0;
    for(int i = 0; i < 3; i++)
        line.push_back(0);
}

Slot::Slot(const bool gamble_, const vector <int> line_, const int bet_){
    gamble = gamble_;
    bet = bet_;
    for(int i = 0; i < 3; i++)
        line[i] = line_[i];
}

Slot::Slot(const Slot &rhs){
    gamble = rhs.gamble;
    bet = rhs.bet;
    for(int i = 0; i < 3; i++)
        line[i] = rhs.line[i];
}

bool Slot::operator != (const Slot &rhs){
    return gamble != rhs.gamble || line[0] != rhs.line[0] || line[1] != rhs.line[1] || line[2] != rhs.line[2] || bet != rhs.bet;
}
bool Slot::operator == (const Slot &rhs){
    return gamble == rhs.gamble || line[0] == rhs.line[0] || line[1] == rhs.line[1] || line[2] == rhs.line[2] || bet == rhs.bet;
}

void Slot::setGamble(const bool gamble_){
    gamble = gamble_;
}

void Slot::setLine(const vector <int> line_){
    for(int i = 0; i < 3; i++)
        line[i] = line_[i];
}

void Slot:: setBet(const int bet_){
    bet = bet_;
}
Slot &Slot::operator = (const Slot &rhs){
    setGamble(rhs.gamble);
    setLine(rhs.line);
    setBet(rhs.bet);
    return *this;
}

bool Slot::getGamble() const{
    return gamble;
}
int Slot::getLine() const{
    return line[0]*100+line[1]*10+line[2];
}
int Slot::getBet() const{
    return bet;
}

ostream &operator << (std::ostream & os, const Slot &rhs)
{
    os<<rhs.gamble;
    for(int i = 0; i < 3; i++)
        os<<rhs.line[i]<<" ";
    return os;
}
