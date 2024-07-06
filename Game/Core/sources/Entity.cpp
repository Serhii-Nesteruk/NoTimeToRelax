#include "Entity.h"

void Entity::move(const sf::Vector2f &offset)
{
    _sprite.move(offset);
}