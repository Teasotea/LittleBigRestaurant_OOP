#include "Coffee.h"

#include <utility>

Coffee::Coffee() {
    this->price = 0;
    this->name = "-";
}

Coffee::Coffee(double price, string n) {
    this->price = price;
    this->name = std::move(n);
}

void Coffee::setPrice(double p) {
    this->price = p;
}

double Coffee::getPrice() const {
    return this->price;
}

void Coffee::setName(string n) {
    this->name = std::move(n);
}

string Coffee::getName() {
    return this->name;
}


istream &operator>>(istream &is, Coffee&an) {
    is >> an.name >> an.price;
    return is;
}


Coffee::~Coffee() = default;