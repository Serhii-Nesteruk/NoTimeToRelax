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


    [[nodicard]] float getSpeed () const
    {
        return _speed;
    }
protected:
    float _speed = 0.f;
};
