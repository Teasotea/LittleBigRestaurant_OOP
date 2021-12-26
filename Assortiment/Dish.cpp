#include "Dish.h"

Dish::Dish() {
    this->coffee = Coffee();
    this->cake = Cake();
}

Dish::Dish(Coffee cofee, Cake cake) {
    this->coffee = cofee;
    this->cake = cake;
}

void Dish::setCofee(Coffee cofee) {
    this->coffee = cofee;
}

Coffee Dish::getCoffee() {
    return this->coffee;
}

void Dish::setCake(Cake cake) {
    this->cake = cake;
}

Cake Dish::getCake() {
    return this->cake;
}

double Dish::getSum() {
    return this->coffee.getPrice() + this->cake.getPrice();
}

Dish::~Dish() = default;