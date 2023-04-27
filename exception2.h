//
// Created by Ciprian on 27.04.2023.
//
#include <iostream>
#include <string>
#ifndef OOP_LAB2_EXCEPTION2_H
#define OOP_LAB2_EXCEPTION2_H

class Exception2 : public std::exception {
private:
    string message;
public:
    Exception2();
    virtual const char* what() const throw();
};

#endif //OOP_LAB2_EXCEPTION2_H
