#include "ChaoticLemniscate.h"

double ChaoticLemniscate::getX(double offsetX)
{
    return ((_windowSize.x - LemniscateMargines::getHorizontalMarginese()) / 2.f) * (std::sin(offsetX) + 0.1 * std::sin(3 * offsetX))
        + (_windowSize.x / 2.f);
}

double ChaoticLemniscate::getY(double offsetY)
{
    return ((_windowSize.y - LemniscateMargines::getVeticalMargineses()) / 2.f) * (std::sin(2 * offsetY) + 0.1 * std::cos(5 * offsetY))
        + (_windowSize.y / 2.f);
}

sf::Vector2f ChaoticLemniscate::getPosition(double offset)
{
    sf::Vector2f temp;
    temp.x = getX(offset);
    temp.y = getY(offset);
    return temp;
}

void ChaoticLemniscate::generateCurve()
{
    _curve.clear();

    for (double offset = 0; offset < 2 * M_PI; offset += 0.7)
    {
        sf::Vector2f pos = getPosition(offset);
        _curve.push_back(pos);
    }
}

std::vector<sf::Vector2f> ChaoticLemniscate::getCurve()
{
    return _curve;
}

void ChaoticLemniscate::setWindowSize(const sf::Vector2f &windowSize)
{
    _windowSize = windowSize;
}

void LemniscateMargines::setMargineses(float vertical, float horizontal)
{
    _verticalMarginesses = vertical;
    _horizontalMarginesses = horizontal;
}

float LemniscateMargines::getVeticalMargineses()
{
    return _horizontalMarginesses;
}

float LemniscateMargines::getHorizontalMarginese()
{
    return _verticalMarginesses;
}
