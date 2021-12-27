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
    pair<string, double> coffeeInfo;

public:

    Coffee();

    Coffee(double price, string name);

    explicit Coffee(pair<string, double> cakeInfo);

    void setPrice(double price);

    double getPrice() const;

    void setName(string name);

    string getName();

    pair<string, double > getCoffeeInfo();

    void setCoffeeInfo(pair<string, double > cInfo);

    friend istream &operator>>(istream &os, Coffee &an);

    ~Coffee();
};

