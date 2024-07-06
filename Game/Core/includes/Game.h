 
#pragma once

#include "Player.h"
#include "StaticMash.h"
#include "../../Patterns/includes/clickObserver.h"

#include <SFML/Graphics.hpp>
#include <string>

class Game 
{
public:
    Game(const sf::Vector2f windowSize, const std::string& tittle);
    ~Game() = default;

    void start();

private:
    void setup();
    void eventProcessing();
    void display();
    void update();
    void createWindow();

    void setupPlayers();
private:
    sf::RenderWindow _window;
    sf::Vector2f _windowSize{};
    const std::string _tittle{};
    inline static const sf::Color _backgroundColor = sf::Color::Blue;

    Player _player; // TODO: temp variable
    StaticMash _staticMash;
    ClickObserver _clickObserver;
};