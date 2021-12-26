#pragma once
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Cake
{
private:

    double price;
    string name;
    pair<string, double> cakeInfo;

public:

    Cake();

    Cake(double price, string name);
    explicit Cake(pair<string, double> cakeInfo);

    void setPrice(double p);

    double getPrice() const;

    void setName(string n);

    string getName();

    pair<string, double > getCakeInfo();

    void setCakeInfo(pair<string, double > cInfo);

    friend istream &operator>>(istream &os, Cake &an);

    ~Cake();
};