#include "Date.h"
#include <exception>
#include <iostream>

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 1990;
}

struct WrongDateException : public std::exception {
    const char *what() const throw() {
        return "Wrong Date format!";
    }
};

Date::Date(int day, int month, int year) {

    try {
        if (day > 31 || day < 0 || month < 0 || month > 12 || year < 1900 || year > 2050) {
            throw WrongDateException();
        } else {
            this->day = day;
            this->month = month;
            this->year = year;
        }
    }
    catch (WrongDateException& w){
        std::cout<<w.what()<<std::endl<<std::endl;
    }
}

void Date::setDay(int d) {
    this->day = d;
}

int Date::getDay() const {
    return this->day;
}

void Date::setMonth(int m) {
    this->month = m;

}

int Date::getMonth() const {
    return this->month;
}

void Date::setYear(int y) {
    this->year = y;

}

int Date::getYear() const {
    return this->year;
}


Date::~Date() = default;