#include "WaiterList.h"
#include <list>
#include <utility>

WaiterList::WaiterList() {
	this->waiters.emplace_back();
}

WaiterList::WaiterList(vector<Waiter> w){
	this->waiters = std::move(w);
}

vector<Waiter> WaiterList::getWaiterList(){
	return waiters;
}

void WaiterList::addWaiter(Waiter w) {
    waiters.push_back(w);
}

Waiter WaiterList::getWaiterByNum(int n) {
    return waiters[n];
}

int WaiterList::getSize() {
    return waiters.size();
}

Waiter &WaiterList::operator[](int i) {
    return  waiters[i];
}

WaiterList::~WaiterList() = default;



