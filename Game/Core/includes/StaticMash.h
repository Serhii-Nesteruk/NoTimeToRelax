#pragma once 

#include "WorldObject.h"

class StaticMash 
{
public:
    StaticMash() = default;
    ~StaticMash() = default;

    [[nodicard]] bool isClicked() const;
private:
};