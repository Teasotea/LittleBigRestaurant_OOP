#pragma once
#include "../Assortiment/Cake.h"
#include "Order.h"
#include "../Assortiment/Coffee.h"
#include "../Assortiment/Dish.h"
#include "Waiter.h"
#include <cstring>
#include <string>
#include <iostream>
#include <list>

using namespace std;
class Report
{
private:
	list<Order> the_list;

public:

	Report();

	explicit Report(const Order& order);

    void addOrder(const Order& order);

    list<Order> getOrders();

    Order &operator[](int);

    int size();

    friend ostream &operator<<(ostream &os, Report &an);

    ~Report();
};

