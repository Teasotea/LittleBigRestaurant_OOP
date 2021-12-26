#include "Order.h"
#include "Date.h"
#include "../Assortiment/Dish.h"
#include <iostream>
#include <list>
#include <utility>
#include <iterator>

Order::Order() {
    this->waiter = Waiter();
    this->date = Date();
    this->sum = 0;
    this->dish.emplace_back();
}

Order::Order(list<Dish> dish, const Waiter &waiter, const Date &date) {
    this->waiter = waiter;
    this->date = date;
    this->dish = std::move(dish);
    double s = 0;
    for (int i = 0; i < this->dish.size(); i++) {
        Dish b;
        auto it = this->dish.begin();
        for (int j = 0; j < i; j++) {
            ++it;
        }
        b = *it;
        s += b.getCoffee().getPrice()+b.getCake().getPrice();
    }
    this->sum = s;
}

void Order::setWaiter(Waiter w) {
    this->waiter = w;
}

Waiter Order::getWaiter() {
    return this->waiter;
}



void Order::setDate(Date d) {
    this->date = d;
}

Date Order::getDate() {
    return this->date;
}


double Order::getSum() const {
    return this->sum;
}

void Order::setDish(list<Dish> d) {
    this->dish = std::move(d);
}


int Order::size() {
    return this->dish.size();
}


list<Dish> Order::getDish() {
    return this->dish;
}

Dish &Order::operator[](int i) {
    //if (i < this->dish.size() && i >= 0) {
        auto it = this->dish.begin();
        for (int j = 0; j < i; j++) {
            ++it;
        }
        return *it;
}

Order::~Order() {
    this->dish.clear();
}
