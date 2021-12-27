#include "Coffee.h"

#include <utility>

Coffee::Coffee() {
    this->price = 0;
    this->name = "-";
}

Coffee::Coffee(double price, string n) {
    this->price = price;
    this->name = std::move(n);
    this->coffeeInfo = make_pair(name, price);
}

Coffee::Coffee(pair<string, double> cInfo) {
    this->name = cInfo.first;
    this->price = cInfo.second;
    this->coffeeInfo = make_pair(name, price);
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

void Coffee::setCoffeeInfo(pair<string, double> cInfo) {
    this->name = cInfo.first;
    this->price = cInfo.second;
    this->coffeeInfo = make_pair(name, price);
}

pair<string, double> Coffee::getCoffeeInfo() {
    return this->coffeeInfo;
}


istream &operator>>(istream &is, Coffee&an) {
    is >> an.name >> an.price;
    return is;
}


Coffee::~Coffee() = default;