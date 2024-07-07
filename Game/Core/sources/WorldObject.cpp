 #include "WorldObject.h"

#include <iostream>

WorldObject::WorldObject(const WorldObject &other)
    :_sprite(other._sprite), _texture(other._texture), _position(other._position),
    _color(other._color), _scale(other._scale), _pathToTexture(other._pathToTexture)
{
    setTexture(other._pathToTexture);
}

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

WorldObject& WorldObject::setTexture(const sf::Texture &texture)
{
    _texture = texture;
    _sprite.setTexture(_texture);
    return *this;
}

WorldObject& WorldObject::setTexture(const std::filesystem::path &texturePath)
{
    if (!_texture.loadFromFile(texturePath.string()))
        throw std::runtime_error("Failed to load texture by path: " + texturePath.string());
    _pathToTexture = texturePath;
    _sprite.setTexture(_texture);
    return *this;
}

WorldObject& WorldObject::setupSprite(const std::filesystem::path &texturePath)
{
    setTexture(texturePath);
    return *this;
}

WorldObject& WorldObject::setupSprite(const sf::Texture &texture)
{
    setTexture(texture);
    return *this;
}

WorldObject& WorldObject::setPosition(const sf::Vector2f &position)
{
    _position = position;
    _sprite.setPosition(_position);
    return *this;
}

WorldObject& WorldObject::setColor(const sf::Color &color)
{
    _color = color;
    _sprite.setColor(_color);
    return *this;
}

WorldObject& WorldObject::setScale(const sf::Vector2f &scale)
{
    _scale = scale;
    _sprite.setScale(_scale.x, scale.y);
    return *this;
}

WorldObject& WorldObject::setRotation(float angle)
{
    _sprite.setRotation(angle);
    return *this;
}

WorldObject& WorldObject::setOrigin(float x, float y)
{
    _sprite.setOrigin(x, y);
    return *this;
}

