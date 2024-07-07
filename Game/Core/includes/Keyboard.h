#pragma once 

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Keyboard
{
public:
    Keyboard() = default;
    ~Keyboard() = default;

    [[nodiscard]] static bool checkIfLeftMousePressed();
    [[nodiscard]] static bool checkIfRightMousePressed();
    [[nodiscard]] static sf::Vector2i getMousePosition(sf::RenderWindow& window);
private:

};