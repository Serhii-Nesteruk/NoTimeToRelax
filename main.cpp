#include "Game/Core/includes/Game.h"
/* #include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Move Sprite to Target");

    sf::Texture spriteTexture;
    if (!spriteTexture.loadFromFile("../Game/resources/textures/playerTexture.png")) {
        return -1;
    }

    sf::Texture targetTexture;
    if (!targetTexture.loadFromFile("../Game/resources/textures/HomeTexture.png")) {
        return -1;
    }

    sf::Sprite sprite(spriteTexture);
    sf::Sprite target(targetTexture);

    sprite.setPosition(100, 100);
    target.setPosition(400, 300);

    bool move = false;
    sf::Vector2f targetPosition;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (target.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    move = true;
                    targetPosition = target.getPosition();
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();

        if (move) {
            sf::Vector2f spritePosition = sprite.getPosition();
            sf::Vector2f direction = targetPosition - spritePosition;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

            if (length != 0) {
                direction /= length;
            }

            float speed = 200.0f; // Speed in pixels per second
            sf::Vector2f movement = direction * speed * deltaTime;

            if (std::abs(spritePosition.x - targetPosition.x) < std::abs(movement.x) &&
                std::abs(spritePosition.y - targetPosition.y) < std::abs(movement.y)) {
                sprite.setPosition(targetPosition);
                move = false;
            } else {
                sprite.move(movement);
            }
        }

        window.clear();
        window.draw(sprite);
        window.draw(target);
        window.display();
    }

    return 0;
}
*/



#include <iostream>

int main() 
{
    try
    {
        Game game(sf::Vector2f(1280.f, 720.f), "Not Time To Relax");
        game.start();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "=================" << std::endl;
        std::cerr << e.what() << '\n'   ;
        std::cerr << "=================" << std::endl;
    }

    return 0;
}
