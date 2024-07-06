#pragma once

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void onNotify() = 0;
};