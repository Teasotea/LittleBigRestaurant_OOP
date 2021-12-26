#pragma once
#include "Waiter.h"
#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class WaiterList
{
private:
    vector<Waiter> waiters;

public:

	WaiterList();

	explicit WaiterList(vector<Waiter> waiters);

    vector<Waiter> getWaiterList();

    void addWaiter(Waiter w);

    Waiter getWaiterByNum(int n);
    int getSize();
    Waiter &operator[](int);

	~WaiterList();
};