#pragma once
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Coffee
{
private:

    double price;
    string name;

public:

    Coffee();

    Coffee(double price, string name);

    void setPrice(double price);

    double getPrice() const;

    void setName(string name);

    string getName();

    friend istream &operator>>(istream &os, Coffee &an);

    ~Coffee();
};

