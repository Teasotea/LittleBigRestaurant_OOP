#pragma once
#include "Date.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Person 
{
private:

	string name;
	string surname;
	Date date;

public:

	Person();

	Person(string name, string surname, const Date& date);

	void setName(string n);

	string getName();

	void setSurname(string s);

	string getSurname();

	void setDate(Date date);

	Date getDate();

    friend ostream &operator<<(ostream &os, Person &an);

    friend istream &operator>>(istream &os, Person &an);
	~Person();
};


