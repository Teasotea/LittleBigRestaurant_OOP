#include "Person.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

Person::Person() {
	this->name = "Unnamed";
	this->surname = "Unnamed";
	this->date = Date();
}

Person::Person(string name, string surname, const Date& date) {
	this->name = std::move(name);
	this->surname = std::move(surname);
	this->date = date;
}

void Person::setName(string n) {
	this->name = std::move(n);
}

string Person::getName() {
	return name;
}

void Person::setSurname(string s) {
	this->surname = std::move(s);
}

string Person::getSurname() {
	return surname;
}

void Person::setDate(Date d) {
	this->date = d;
}

Date Person::getDate() {
    Date d = Date(this->date.getDay(), this->date.getMonth(), this->date.getYear());
	return d;
}

ostream &operator<<(ostream &os, Person &an) {
    os << an.getName() << " " << an.getSurname()<< " " << an.date.getDay() <<"/"
    <<an.date.getMonth()<<"/"<< an.date.getYear();
    return os;
}

istream &operator>>(istream &is, Person &an) {
    int d, m, y;
    is >> an.name >> an.surname >>d >> m >> y;
    an.date.setDay(d);
    an.date.setMonth(m);
    an.date.setYear(y);
    return is;
}

Person::~Person() = default;