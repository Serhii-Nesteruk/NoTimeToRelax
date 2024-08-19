#include "StaticMash.h"

#include <algorithm>
#include <iostream>

StaticMash::StaticMash() : _id(++_nextId)
{
}

StaticMash::StaticMash(const StaticMash &other)
    : WorldObject(other), _observers(other._observers), _id(other._id)
{
    _nextId = ++other._nextId;
}

StaticMash& StaticMash::addObserver(IObserver *observer)
{
    _observers.push_back(observer);
    return *this;
}

void StaticMash::removeObserver(IObserver* observer) 
{
    _observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
}

void StaticMash::notifyObservers() const 
{
    std::cout << _observers.size() << std::endl;
    for (auto& observer : _observers) 
        observer->onNotify();
}

int StaticMash::getId() const
{
    return _id;
}

bool StaticMash::checkIfObjWasPressed(const sf::Vector2f &mousePos)
{
    return _sprite.getGlobalBounds().contains(mousePos);
}
