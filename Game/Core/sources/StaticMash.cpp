#include "../includes/StaticMash.h"

#include <algorithm>

void StaticMash::addObserver(IObserver* observer) {
    _observers.push_back(observer);
}

void StaticMash::removeObserver(IObserver* observer) {
    _observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
}

void StaticMash::notifyObservers() const {
    for (auto observer : _observers) {
        observer->onNotify();
    }
}
