#pragma once

#include "WorldObject.h"

class Entity : public WorldObject
{
public:
    Entity() = default;
    ~Entity() = default;

    
    void setSpeed(float speed)
    {   
        _speed = speed;
    }

    [[nodiscard]] float getSpeed () const
    {
        return _speed;
    }

    void move(const sf::Vector2f& offset);
protected:
    float _speed = 700.f;
};
