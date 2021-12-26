#include "Waiter.h"
#include "Date.h"
#include "Person.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

Waiter::Waiter() : Person() {
	this->category = "Unknown";
}

Waiter::Waiter(string name, string surname, const Date& date, string category) : Person(name, surname, date)  {
	this->category = std::move(category);
}
Waiter::Waiter(Person p, string category) {
    this->setName(p.getName());
    this->setSurname(p.getSurname());
    this->setDate(p.getDate());
    this->category = std::move(category);
}

string Waiter::getCategory() {
	return this->category;
}

void Waiter::setCategory(string c) {
	this->category = std::move(c);
}

Person Waiter::getPersonalInfo() {
    Person thisWaiter;
    thisWaiter.setName(this->getName());
    thisWaiter.setSurname(this->getSurname());
    thisWaiter.setDate(this->getDate());
    return thisWaiter;
}


Waiter::~Waiter() = default;
