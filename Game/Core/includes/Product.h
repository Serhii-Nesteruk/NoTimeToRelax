#pragma once

#include "WorldObject.h"

#include <SFML/Graphics.hpp>
#include <string>

class Product : public WorldObject
{
public:
    Product() = default;
    ~Product() = default;

        

private:
    float _price = 0.f;

};