#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <string>

class WorldObject 
{
public:
    WorldObject() = default;
    WorldObject(const WorldObject& other);
    ~WorldObject() = default;

    void draw(sf::RenderWindow& window);

    [[nodiscard]] sf::Sprite getSprite() const;
    [[nodiscard]] sf::Texture getTexture() const;
    [[nodiscard]] sf::Vector2f getPosition() const;
    [[nodiscard]] sf::Color getColor() const;
    [[nodiscard]] sf::Vector2f getScale() const;
    
    WorldObject& setTexture(const sf::Texture& texture);
    WorldObject& setTexture(const std::filesystem::path& texturePath);
    WorldObject& setupSprite(const std::filesystem::path& texturePath);
    WorldObject& setupSprite(const sf::Texture& texture);
    WorldObject& setPosition(const sf::Vector2f& position);
    WorldObject& setColor(const sf::Color& color);
    WorldObject& setScale(const sf::Vector2f& scale);
    WorldObject& setRotation(float angle);
    WorldObject& setOrigin(float x, float y);
protected:
    sf::Sprite _sprite{};
    sf::Texture _texture{};
    sf::Vector2f _position{};
    sf::Color _color{};
    sf::Vector2f _scale{};
    std::filesystem::path _pathToTexture{};
};
