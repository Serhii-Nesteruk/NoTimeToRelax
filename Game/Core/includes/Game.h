#pragma once

#include "Player.h"
#include "StaticMash.h"
#include "PlayerController.h"
#include "clickObserver.h"

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
    void setupStaticObjects();
    void setupMap();
    void setupBackground(); // TODO: move to another class
private:
    sf::RenderWindow _window;
    sf::Vector2f _windowSize{};
    const std::string _tittle{};
    inline static const sf::Color _backgroundColor = sf::Color::Blue;

    PlayerController playerController;

    Player _player;
    std::vector<StaticMash> _staticObjects{};
    ClickObserver _clickObserver;
    sf::Clock _clock;
    float _deltaTime = 0.f;

    // TODO: move two next variables to Map class
    sf::Sprite _background;
    sf::Texture _backgroundTexture;
};