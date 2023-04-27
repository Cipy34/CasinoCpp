//
// Created by Ciprian on 28.04.2023.
//
#include <iostream>
#include <string>
#ifndef OOP_LAB2_EXCEPTION3_H
#define OOP_LAB2_EXCEPTION3_H
using namespace std;

class Exception3 : public std::exception {
private:
    string message;
public:
    Exception3();
    virtual const char* what() const throw();
};


#endif //OOP_LAB2_EXCEPTION3_H
