#include "Stuff/Waiter.h"
#include "Stuff/Date.h"
#include "Stuff/Person.h"
#include "Assortiment/Coffee.h"
#include "Assortiment/Cake.h"
#include "Assortiment/Dish.h"
#include "Stuff/Order.h"
#include "Stuff/WaiterList.h"
#include "Stuff/Report.h"
#include <string>
#include <list>
#include <iostream>
#include <exception>
#include <fstream>
#include <iomanip>
#include <random>
#include <map>
#include <ctime>
#include <vector>

using namespace std;
map<string, double> CoffeeList{{"Americano",  1.90},
                               {"Milkariano", 2.50},
                               {"Flet",       3},
                               {"Late",       2.8},
                               {"Capuccino",  5.21}};
map<string, double> CakeList{{"ApplePie", 2},
                             {"Honeey",   3.50},
                             {"ChocoPie", 4},
                             {"Prague",   5}};
vector<Waiter> w2{Waiter("Sam", "Samuelson", Date(19, 8, 1999), "chef"),
                  Waiter("Vito", "Encho", Date(8, 2, 1985), "cook"),
                  Waiter("Jack", "Peters", Date(11, 12, 1992), "cook"),
                  Waiter("Bonia", "Boka", Date(1, 6, 1998), "cleaner"),
                  Waiter("Lee", "Bo", Date(28, 9, 1963), "manager")};
WaiterList waiters(w2);
Date today = Date(27, 12, 2021);

list<Order> orderBase;
Report r;
vector<Report> reports;

const char *fileName = "/home/sofia/CLionProjects/LittleBigRestaurant/report.txt";
const char *fileName2 = "/home/sofia/CLionProjects/LittleBigRestaurant/report.dat";

void addOrder();

void updateAndViewReport();

void writeReportToFileNonBinary(const char *string);

void readReportFileNonBinary(const char *string);

void addWaiter();

void writeReportToFileBinary(const char *name);

void readReportFileBinary(const char *name2);

void searchAssortment();

void searchWaiter();

template<typename T1>
double AveragePrice(T1 list)//T1 - Report/Order
{
    double av = 0;
    for (int i = 0; i < list.size(); i++) {
        av += list[i].getSum();
    }
    return av / list.size();
}

template<typename T1>
double AverageSize(T1 list)//T1 - Report
{
    double av = 0;
    for (int i = 0; i < list.size(); i++) {
        av += list[i].size();
    }
    return av / list.size();
}

struct WrongNumException : public std::exception {
    const char *what() const throw() {
        return "Wrong Number!";
    }
};

void Menu() {
    int choice;
    do {
        again:
        cout << "Main Menu\n";
        cout << "Here is Restaurant Database:\n";
        cout << "1 - New order\n";
        cout << "2 - Update report\n";
        cout << "3 - View Statistics\n";
        cout << "4 - View Table Database\n";
        cout << "5 - Write Database to file\n";
        cout << "6 - Read Database from file\n";
        cout << "7 - Change date\n";
        cout << "8 - Add waiter\n";
        cout << "9 - List of waiters\n";
        cout << "10 -Search info\n";
        cout << "0 - Quit\n";
        cout << "You chose: ";
        try {
            cin >> choice;
            if (choice > 10 || choice < 0) {
                throw WrongNumException();
            }
        }
        catch (WrongNumException &e) {
            std::cout << e.what() << std::endl << std::endl;
            goto again;
        }

        cout << "- - - - - - - - - - - - - -\n";

        switch (choice) {

            case 1:
                addOrder();
                break;
            case 2:
                updateAndViewReport();
                break;
            case 3:
                cout << "Average price per order: " << endl << AveragePrice<Report>(r) << endl;
                cout << "Average price per dish: " << endl;
                for (int i = 0; i < r.size(); i++) {
                    cout << AveragePrice<Order>(r[0]) << endl;
                }
                cout << "Average amount of dishes per order: " << endl << AverageSize<Report>(r) << endl;
                break;
            case 4:
                cout << "Restaurant Database in Table:" << endl;
                cout << r << endl;
                break;
            case 5: {
                int ch;
                cout << "Press 1 to write report in text file or 2 to write in binary file: ";
                cin >> ch;
                switch (ch) {
                    case 1:
                        writeReportToFileNonBinary(fileName);
                        break;
                    case 2:
                        writeReportToFileBinary(fileName2);
                        break;
                }
                break;
            }
            case 6:
                int ch;
                cout << "Press 1 to read report from text file or 2 to read from binary file: ";
                cin >> ch;
                switch (ch) {
                    case 1:
                        readReportFileNonBinary(fileName);
                        break;
                    case 2:
                        readReportFileBinary(fileName2);
                        break;
                }

                break;
            case 7:
                cout << "Enter day month year: ";
                int d, m, y;
                cin >> d >> m >> y;
                today = Date(d, m, y);
                break;
            case 8:
                addWaiter();
                break;
            case 9:
                for (int i = 0; i < waiters.getSize(); i++) {
                    cout << waiters[i] << endl;
                }
                cout << endl;
                break;
            case 10:
                int ch1;
                cout << "1 - search assortment, 2 - search waiter: ";
                cin >> ch1;
                switch (ch1) {
                    case 1:
                        searchAssortment();
                        break;
                    case 2:
                        searchWaiter();
                        break;
                }
                break;
            case 0:
                reports.push_back(r);
                break;
            default:
                cout << "Main Menu\n";
                cout << "Here is Restaurant Database:\n";
                cout << "1 - New order\n";
                cout << "2 - Update report\n";
                cout << "3 - View Statistics\n";
                cout << "4 - View Table Database\n";
                cout << "5 - Write Database to file\n";
                cout << "6 - Read Database from file\n";
                cout << "7 - Change date\n";
                cout << "8 - Add waiter\n";
                cout << "9 - List of waiters\n";
                cout << "10 -Search info\n";
                cout << "0 - Quit\n";
                cout << "You chose: ";
                cin >> choice;
                cout << "- - - - - - - - - - - - - -\n";
        }
    } while (choice != 0);
}

void searchWaiter() {
    string w_name;
    Person w;
    cout <<"Enter name or surname of waiter: "<<endl;
    cin>>w_name;
    for(int i=0; i<waiters.getSize();i++){
        if(waiters[i].getName() == w_name || waiters[i].getSurname() == w_name){
            cout<<"Yes, this waiter is working with us. Personal info: "<<endl;
            w = waiters[i].getPersonalInfo();
            cout <<w<< ", responsibility: "<< waiters[i].getCategory()<<endl;
        }
    }
}

void searchAssortment() {
    int ch;
    menu:
    cout << "1 - search coffee, 2 - search cake, 3 - exit: ";
    cin >> ch;
    string searchable;

    if (ch == 1) {
        cout << endl << "Enter name of coffee: ";
        cin >> searchable;
        if (CoffeeList.count(searchable) > 0) {
            cout << "There is " << searchable << " coffee in restaurant. Its price is: " << CoffeeList[searchable]
                 << endl;
        } else {
            cout << "Sorry, we don't have this coffee: " << searchable << endl;
        }
    } else if (ch == 2) {
        cout << endl << "Enter name of cake: ";
        cin >> searchable;
        if (CakeList.count(searchable) > 0) {
            cout << "There is " << searchable << " cake in restaurant. Its price is: " << CakeList[searchable] << endl;
        } else {
            cout << "Sorry, we don't have this cake: " << searchable << endl;
        }
    }
    else if(ch!=3){
        cout << "Wrong number" << endl;
        goto menu;
    }
}


void addWaiter() {
    cout << "Enter name surname day month year category: ";
    Person p;
    string category;
    cin >> p;
    cin >> category;
    Waiter w(p, category);
    waiters.addWaiter(w);
}

void writeReportToFileBinary(const char *name) {
    fstream my_file;
    my_file.open(name, ios::binary | ios::app);
    if (!my_file) {
        cout << "File not created!";
    } else {
        cout << "File created successfully!";
        my_file << "Restaurant Database" << endl;
        my_file << r;

        for (int i = 0; i < r.size(); i++) {
            for (int j = 0; j < r[i].size(); j++) {
                Coffee coffee = r[i][j].getCoffee();
                Cake cake = r[i][j].getCake();
                my_file << "Dish" << j + 1 << ": " << "Coffee: " << coffee.getName() << " " << coffee.getPrice()
                        << "$ Cake: " << cake.getName() << " " << cake.getPrice() << "$ Total price: "
                        << coffee.getPrice() + cake.getPrice() << "$";
                my_file << endl;
            }
        }
        my_file.close();
    }
}

void writeReportToFileNonBinary(const char *string) {
    fstream my_file;
    my_file.open(string, ios::out);
    if (!my_file) {
        cout << "File not created!";
    } else {
        cout << "File created successfully!";
        my_file << "Restaurant Database" << endl;
        my_file << r;

        for (int i = 0; i < r.size(); i++) {
            for (int j = 0; j < r[i].size(); j++) {
                Coffee coffee = r[i][j].getCoffee();
                Cake cake = r[i][j].getCake();
                my_file << "Dish" << j + 1 << ": " << "Coffee: " << coffee.getName() << " " << coffee.getPrice()
                        << "$ Cake: " << cake.getName() << " " << cake.getPrice() << "$ Total price: "
                        << coffee.getPrice() + cake.getPrice() << "$";
                my_file << endl;
            }
        }
        my_file.close();
    }
}

void readReportFileNonBinary(const char *string) {
    fstream my_file;
    my_file.open(string, ios::in);
    if (!my_file) {
        cout << "No such file";
    } else {
        char ch;
        while (true) {
            my_file >> ch;
            if (my_file.eof())
                break;
            cout << ch;
        }

    }
    my_file.close();
}

void readReportFileBinary(const char *name2) {
    fstream my_file;
    my_file.open(name2, ios::binary);
    if (!my_file) {
        cout << "No such file";
    } else {
        char ch;
        while (true) {
            my_file >> ch;
            if (my_file.eof())
                break;
            cout << ch;
        }

    }
    my_file.close();
}


void updateAndViewReport() {
    for (const auto &order: orderBase) {
        r.addOrder(order);
    }
    orderBase.empty();
    cout << r;
}

void addOrder() {
    Coffee coffee;
    Cake cake;
    int amountOfDishes, choice;
    cout << "Enter amount of dishes: ";
    cin >> amountOfDishes;
    list<Dish> dishes;
    for (int j = 0; j < amountOfDishes; j++) {
        cout << "1) Enter 1 to view standard menu or 0 to enter new items:";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Enter coffee name and price: ";
                cin >> coffee;
                CoffeeList.insert(pair<string, double>(coffee.getName(), coffee.getPrice()));
                cout << "Enter cake name and price: ";
                cin >> cake;
                CakeList.insert(cake.getCakeInfo());
                break;
            case 1:
                cout << "Here is is the standard menu: " << endl;
                cout << endl << "Coffee Menu: name price" << endl;
                for (const auto &c: CoffeeList) {
                    cout << c.first << " " << c.second << endl;
                }
                cout << endl;
                cout << "Enter name of coffee: " << endl;
                string name;
                cin >> name;
                cake.setName(name);
                cake.setPrice(CoffeeList[name]);
                cout << endl;
                cout << "Cake Menu: name price" << endl;
                for (const auto &c: CakeList) {
                    cout << c.first << " " << c.second << endl;
                }
                cout << "Enter name of cake: " << endl;
                cin >> name;
                cake.setName(name);
                cake.setPrice(CakeList[name]);
                cout << endl;
                break;
        }
        cout << endl;
        Dish dish = Dish(coffee, cake);
        dishes.push_back(dish);
    }
    srand((unsigned)time(0));
    int n = (rand() % waiters.getSize()) + 1;
    Order order = Order(dishes, waiters[n - 1], today);
    orderBase.push_back(order);
}


int main() {
    for (int i = 0; i < 9; i++) {
        reports.push_back(r);
    }
    Menu();
    for (int i = 0; i < 10; i++) {
        cout << reports[i];
    }
}
