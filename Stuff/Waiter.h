#pragma once
#include "Date.h"
#include "Person.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Waiter : public Person
{
private:

    string category;

public:

    Waiter();

    Waiter(string name, string surname, const Date &date, string category);

    Waiter(Person p, string category);

    void setCategory(string c);

    string getCategory();

    Person getPersonalInfo();

    ~Waiter();
};