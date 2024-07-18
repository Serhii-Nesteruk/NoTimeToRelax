#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

class ChaoticLemniscate 
{
public:
    ChaoticLemniscate() = default;
    ~ChaoticLemniscate() = default;

    [[nodiscard]] static double getX(double offsetX);
    [[nodiscard]] static double getY(double offsetY);
    [[nodiscard]] static sf::Vector2f getPosition(double offset);
    static void generateCurve();

    [[nodiscard]] static std::vector<sf::Vector2f> getCurve();
    static void setWindowSize(const sf::Vector2f& windowSize);

private:
    inline static std::vector<sf::Vector2f> _curve{};
    inline static sf::Vector2f _windowSize{};
};