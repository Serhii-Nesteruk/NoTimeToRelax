#include "Keyboard.h"

bool Keyboard::checkIfLeftMousePressed()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Keyboard::checkIfRightMousePressed()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Right);
}

sf::Vector2i Keyboard::getMousePosition(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window);
}
