#pragma once

#include "WorldObject.h"
#include "observer.h" 
#include <vector>

class StaticMash : public WorldObject 
{
public:
    StaticMash();
    StaticMash(const StaticMash& other);
    ~StaticMash() = default;

    StaticMash& addObserver(IObserver* observer);
    void removeObserver(IObserver* observer);
    void notifyObservers() const;

    inline static const int invalidId = -1;

    [[nodiscard]] int getId() const;
private:
    std::vector<IObserver*> _observers;
    int _id = invalidId;
    inline static int _nextId = invalidId;
};
