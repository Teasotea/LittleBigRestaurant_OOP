#pragma once
#include "../Assortiment/Cake.h"
#include "../Assortiment/Coffee.h"
#include "Date.h"
#include "../Assortiment/Dish.h"
#include "Waiter.h"
#include <cstring>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Order
{
private:
    list<Dish> dish;
	double sum{};
	Waiter waiter;
	Date date;


public:

	Order();

    Order(list<Dish> dish, const Waiter &waiter, const Date &date);

	double getSum() const;

	void setWaiter(Waiter w);

	Waiter getWaiter();

	void setDate(Date d);

	Date getDate();

	void setDish(list<Dish> dish);

	list<Dish> getDish();

    Dish &operator[](int);

    int size();

	~Order();
};

