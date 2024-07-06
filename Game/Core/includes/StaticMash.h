#pragma once

#include "../../Patterns/includes/observer.h" // TODO: don't use relative paths, you should to configurate CMakeLists.txt
#include <vector>

class StaticMash {
public:
    StaticMash() = default;
    ~StaticMash() = default;

    [[nodiscard]] bool isClicked() const;

    void addObserver(IObserver* observer);
    void removeObserver(IObserver* observer);
    void notifyObservers() const;

private:
    std::vector<IObserver*> _observers;
};
