#pragma once

#include "observer.h"
#include <iostream>

class ClickObserver : public IObserver {
public:
    void onNotify() override {
        std::cout << "StaticMash clicked!" << std::endl;
    }
};
