#include "Cake.h"

#include <utility>

Cake::Cake() {
    this->price = 0;
    this->name = "-";
}

Cake::Cake(double price, string name) {
    this->price = price;
    this->name = std::move(name);
    this->cakeInfo = make_pair(name, price);
}

Cake::Cake(pair<string, double> cInfo) {
    this->name = cInfo.first;
    this->price = cInfo.second;
    this->cakeInfo = make_pair(name, price);
}

void Cake::setPrice(double p) {
    this->price = p;
}

double Cake::getPrice() const {
    return this->price;
}

void Cake::setName(string n) {
    this->name = std::move(n);
}

string Cake::getName() {
    return this->name;
}

void Cake::setCakeInfo(pair<string, double> cInfo) {
    this->name = cInfo.first;
    this->price = cInfo.second;
    this->cakeInfo = make_pair(name, price);
}

pair<string, double> Cake::getCakeInfo() {
    return this->cakeInfo;
}

istream &operator>>(istream &is,Cake&an) {
        is >> an.name >> an.price;
        an.setCakeInfo({an.name, an.price});
    return is;
}

Cake::~Cake() = default;
