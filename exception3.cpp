//
// Created by Ciprian on 28.04.2023.
//

#include "exception3.h"
Exception3::Exception3(){
    message = "You can't enter this character!";
}
const char* Exception3::what() const throw(){
    return message.c_str();
}