#include "Report.h"
#include<iomanip>
#include <utility>

const char separator    = ' ';
const int nameWidth     = 10;
const int numWidth      = 6;
Report::Report() = default;

Report::Report(const Order &order) {
    this->the_list.push_back(order);
}

int Report::size() {
    return this->the_list.size();
}

void Report::addOrder(const Order &order) {
    this->the_list.push_back(order);
}

list<Order> Report::getOrders() {
    return this->the_list;
}

Order &Report::operator[](int i) {
   // if (i < this->the_list.size() && i >= 0) {
        auto it = this->the_list.begin();
        for (int j = 0; j < i; i++) {
            ++it;
        }
        return *it;
}

Report::~Report() {
    this->the_list.clear();
}

template<typename T> void printElement(T t, const int& width)
{
    cout << left << setw(width) << setfill(separator) << t;
}

ostream &operator<<(ostream &os, Report &an) {
    for(int i=0;i<an.size();i++){
        Person p = an[i].getWaiter().getPersonalInfo();
        os << "Order "<<i+1<<":"<<endl<<"Waiter info: "<<p<< " "
                <<an[i].getWaiter().getCategory()<< endl<<"Order date: "<<an[i].getDate().getDay()<<"/"
                <<an[i].getDate().getMonth()<<"/"<<an[i].getDate().getYear()<<endl;
        printElement("Dish", nameWidth);
        printElement("Coffee", numWidth);
        printElement("$", numWidth);
        printElement("Cake", numWidth);
        printElement("$", numWidth);
        printElement("Total $", numWidth);
        cout <<  endl;
        for(int j=0;j<an[i].size();j++){
            Coffee coffee = an[i][j].getCoffee();
            Cake cake = an[i][j].getCake();
            printElement(j+1, nameWidth);
            printElement(coffee.getName(), numWidth);
            printElement(coffee.getPrice(), numWidth);
            printElement(cake.getName(), numWidth);
            printElement(cake.getPrice(), numWidth);
            printElement(coffee.getPrice()+cake.getPrice(), numWidth);
            cout <<  endl;
        }
        cout<<endl;
    }
    return os;
}
