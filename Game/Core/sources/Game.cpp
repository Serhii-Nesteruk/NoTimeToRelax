#include "../includes/Game.h"
#include <cmath>
#include "Game.h"

Game::Game(const sf::Vector2f windowSize, const std::string& tittle)
    : _windowSize(windowSize), _tittle(tittle)
{
    createWindow();
    setup();
}

void Game::start()
{
    while(_window.isOpen()) 
    {
        eventProcessing();
        _deltaTime = _clock.restart().asSeconds();
        playerController.mouseInputHandle();
        playerController.movementControl(_deltaTime);
        display();
    }
}

void Game::setup()
{
    _map.setup();
    setupControllers();
    setupPlayers();
}

void Game::eventProcessing()
{
    sf::Event event;
    while(_window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}

void Game::display() 
{
    _window.clear(_backgroundColor);
    update();
    _window.display();
}

void Game::update()
{
    _map.draw(_window);
    _player.draw(_window);
}

void Game::createWindow()
{
    _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _tittle);
}

void Game::setupPlayers()
{
    _player.setupSprite("../Game/resources/textures/PlayerTexture.png");
    _player.setPosition({600.f, 360.f});
    _player.setScale({0.3f, 0.3f});
    _player.setSpeed(1000.f);
}

void Game::setupControllers()
{
    playerController.attachWindow(&_window);
    playerController.attachPlayer(&_player);
    playerController.setTargetData(_map.getStaticObjects());
}