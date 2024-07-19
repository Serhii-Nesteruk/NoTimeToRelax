#pragma once

#include "Player.h"
#include "PlayerController.h"
#include "Map.h"

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
    void setupControllers();    
    void drawObjects();

private:
    std::shared_ptr<sf::RenderWindow> _window;
    sf::Vector2f _windowSize{};
    const std::string _tittle{};
    inline static const sf::Color _backgroundColor = sf::Color::Blue;

    PlayerController _playerController;
    std::shared_ptr<Player> _player;

    Map _map;

    sf::Clock _clock;
    float _deltaTime = 0.f;
};