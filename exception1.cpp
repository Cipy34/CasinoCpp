//
// Created by Ciprian on 27.04.2023.
//
#include "exception1.h"

Exception1::Exception1(){
    message = "You are too young!";
}
const char* Exception1::what() const throw(){
    return message.c_str();
}