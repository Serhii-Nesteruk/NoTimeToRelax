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
        display();
    }
}

void Game::setup()
{
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
    _player.draw(_window);
}

void Game::createWindow()
{
    _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _tittle);
}

void Game::setupPlayers()
{
    _player.setupSprite("../Game/resources/textures/playerTexture.png");
    _player.setPosition({0.f, 0.f});
    _player.setScale({0.5f, 0.5f});
}
