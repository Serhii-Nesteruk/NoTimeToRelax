#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

class WorldObject 
{
public:
    WorldObject() = default;
    ~WorldObject() = default;

    void draw(sf::RenderWindow& window);

    [[nodiscard]] sf::Sprite getSprite() const;
    [[nodiscard]] sf::Texture getTexture() const;
    [[nodiscard]] sf::Vector2f getPosition() const;
    [[nodiscard]] sf::Color getColor() const;
    [[nodiscard]] sf::Vector2f getScale() const;
    
    void setTexture(const sf::Texture& texture);
    void setTexture(const std::filesystem::path& texturePath);
    void setupSprite(const std::filesystem::path& texturePath);
    void setupSprite(const sf::Texture& texture);
    void setPosition(const sf::Vector2f& position);
    void setColor(const sf::Color& color);
    void setScale(const sf::Vector2f& scale);
    void setRotation(float angle);
    void setOrigin(float x, float y);
private:
    sf::Sprite _sprite{};
    sf::Texture _texture{};
    sf::Vector2f _position{};
    sf::Color _color{};
    sf::Vector2f _scale{};
};
