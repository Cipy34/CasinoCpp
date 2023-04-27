//
// Created by Ciprian on 27.04.2023.
//
#include <iostream>
#include <string>
#ifndef OOP_LAB2_EXCEPTION1_H
#define OOP_LAB2_EXCEPTION1_H

class Exception1 : public std::exception {
private:
    string message;
public:
    Exception1();
    virtual const char* what() const throw();
};


#endif //OOP_LAB2_EXCEPTION1_H
