//
// Created by Ciprian on 13.04.2023.
//
#include <iostream>
#include <string>
#include "game.h"
using namespace std;
Game::Game(){
    name = "";
    chance = 0;
    win = 0;
}

Game::Game(const string& name_, const int chance_, const int win_){
    name = name_;
    chance = chance_;
    win = win_;
}

Game::Game(const Game &rhs) : Slot(rhs) {
    name = rhs.name;
    chance = rhs.chance;
    win = rhs.win;
}

bool Game:: operator != (const Game &rhs){
    return name != rhs.name || chance != rhs.chance || win != rhs.win;
}

bool Game:: operator == (const Game &rhs){
    return name == rhs.name || chance == rhs.chance || win == rhs.win;
}

void Game::setName(const string& name_){
    name = name_;
}

void Game::setChance(const int chance_){
    chance = chance_;
}

void Game::setWin(const int win_){
    win = win_;
}

Game &Game::operator = (const Game &rhs){
    setName(rhs.name);
    setChance(rhs.chance);
    setWin(rhs.win);
    return *this;
}

string Game::getName() const{
    return name;
}

int Game::getChance() const{
    return chance;
}

int Game::getWin() const{
    return win;
}

istream &operator>>(istream &is, Game &rhs)
{
    string name_;
    int chance_, win_;

    cout<<"Name:";
    is>>name_;

    cout<<"How many numbers[0 - 9]:";
    is>>chance_;

    cout<<"How much win:";
    is>>win_;

    rhs.setName(name_);
    rhs.setChance(chance_);
    rhs.setWin(win_);

    return is;
}
ostream &operator << (ostream & os, const Game & rhs){
    os<<"Name : "<<rhs.name<<", Numbers : "<<rhs.chance<<", Win : "<<rhs.win<<"\n";
    return os;
}