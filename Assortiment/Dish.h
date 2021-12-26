#pragma once
#include "Cake.h"
#include "Coffee.h"

class Dish
{
private:
    Coffee coffee;
    Cake cake;

public:
    Dish();

    Dish(Coffee coffee, Cake cake);

    void setCofee(Coffee coffee);

    Coffee getCoffee();

    void setCake(Cake cake);

    Cake getCake();

    double getSum();

    ~Dish();
};

