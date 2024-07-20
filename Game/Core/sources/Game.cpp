#include "Game.h"
#include <cmath>

Game::Game(const sf::Vector2f windowSize, const std::string& tittle)
    : _windowSize(windowSize), _tittle(tittle), 
    _window(std::make_shared<sf::RenderWindow>()),
    _player(std::make_shared<Player>())
{
    createWindow();
    setup();
}

void Game::start()
{
    while(_window->isOpen()) 
    {
        eventProcessing();
        display();
    }
}

void Game::setup()
{
    _map.setup(_window);
    setupControllers();
    setupPlayers();
}

void Game::eventProcessing()
{
    sf::Event event;
    while(_window->pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            _window->close();
        if (event.type == sf::Event::Resized)
            _map.handleWindowResize();
    }
}

void Game::display() 
{
    _window->clear(_backgroundColor);
    update();
    drawObjects();
    _window->display();
}

void Game::update()
{
    _deltaTime = _clock.restart().asSeconds();
    _playerController.mouseInputHandle();
    _map.mouseInputHandle();
    _playerController.movementControl(_deltaTime);
}

void Game::createWindow()
{
    _window->create(sf::VideoMode(_windowSize.x, _windowSize.y), _tittle);
}

void Game::setupPlayers()
{
    _player->setupSprite("../Game/resources/textures/PlayerTexture.png");
    _player->setPosition({600.f, 360.f});
    _player->setScale({0.3f, 0.3f});
    _player->setSpeed(1000.f);
}

void Game::setupControllers()
{
    _playerController.attachWindow(_window);
    _playerController.attachPlayer(_player);
    _playerController.setTargetData(_map.getStaticObjects());
}

void Game::drawObjects()
{
    _map.draw(*_window);
    _player->draw(*_window);
}
