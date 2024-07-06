 
#include "../includes/WorldObject.h"
#include "WorldObject.h"

void WorldObject::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

sf::Sprite WorldObject::getSprite() const
{
    return _sprite;
}

sf::Texture WorldObject::getTexture() const
{
    return _texture;
}

sf::Vector2f WorldObject::getPosition() const
{
    return _position;
}

sf::Color WorldObject::getColor() const
{
    return _color;
}

sf::Vector2f WorldObject::getScale() const
{
    return _scale;
}

void WorldObject::setTexture(const sf::Texture &texture)
{
    _texture = texture;
}

void WorldObject::setTexture(const std::filesystem::path &texturePath)
{
    if (!_texture.loadFromFile(texturePath.string()))
        throw std::runtime_error("Failed to load texture by path: " + texturePath.string());
}

void WorldObject::setupSprite(const std::filesystem::path &texturePath)
{
    setTexture(texturePath);
    _sprite.setTexture(_texture);
}

void WorldObject::setupSprite(const sf::Texture &texture)
{
    setTexture(texture);
    _sprite.setTexture(_texture);
}

void WorldObject::setPosition(const sf::Vector2f &position)
{
    _position = position;
    _sprite.setPosition(_position);
}

void WorldObject::setColor(const sf::Color &color)
{
    _color = color;
    _sprite.setColor(_color);
}

void WorldObject::setScale(const sf::Vector2f &scale)
{
    _scale = scale;
    _sprite.setScale(_scale.x, scale.y);
}

void WorldObject::setRotation(float angle)
{
    _sprite.setRotation(angle);
}

void WorldObject::setOrigin(float x, float y)
{
    _sprite.setOrigin(x, y);
}

