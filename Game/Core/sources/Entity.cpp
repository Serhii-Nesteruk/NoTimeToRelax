#include "Entity.h"

void Entity::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

sf::Sprite Entity::getSprite() const
{
    return _sprite;
}

sf::Texture Entity::getTexture() const
{
    return _texture;
}

sf::Vector2f Entity::getPosition() const
{
    return _position;
}

void Entity::setTexture(const sf::Texture &texture)
{
    _texture = texture;
}

void Entity::setTexture(const std::filesystem::path &texturePath)
{
    if (!_texture.loadFromFile(texturePath.string()))
        throw std::runtime_error("Failed to load texture by path: " + texturePath.string());
}

void Entity::setupSprite(const std::filesystem::path &texturePath)
{
    setTexture(texturePath);
    _sprite.setTexture(_texture);
}

void Entity::setupSprite(const sf::Texture &texture)
{
    setTexture(texture);
    _sprite.setTexture(_texture);
}

void Entity::setPosition(const sf::Vector2f &position)
{
    _position = position;
    _sprite.setPosition(_position);
}

void Entity::setColor(const sf::Color &color)
{
    _color = color;
    _sprite.setColor(_color);
}

void Entity::setScale(const sf::Vector2f &scale)
{
    _scale = scale;
    _sprite.setScale(_scale.x, scale.y);
}

void Entity::setRotation(float angle)
{
    _sprite.setRotation(angle);
}

void Entity::setOrigin(float x, float y)
{
    _sprite.setOrigin(x, y);
}

