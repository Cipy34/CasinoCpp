//
// Created by Ciprian on 27.04.2023.
//

#include "exception2.h"

Exception2::Exception2(){
    message = "You can't enter the casino with no money!";
}
const char* Exception2::what() const throw(){
    return message.c_str();
}