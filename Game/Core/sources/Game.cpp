#include "../includes/Game.h"
#include <cmath>

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
        if (_isMoving)
        {
            sf::Vector2f targetPosition = _staticMash.getPosition();
            sf::Vector2f startPlayerPosition = _player.getPosition();
            sf::Vector2f direction = targetPosition - startPlayerPosition;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

            if (length != 0)
                direction /= length;    

            std::cout << _deltaTime << "sdsdgs" << std::endl;
            sf::Vector2f movement = direction * _player.getSpeed() * _deltaTime;
            if (length <= _player.getSpeed() * _deltaTime)
            {
                _player.setPosition(targetPosition);
                _isMoving = false; 
            }
            else
            {
                _player.move(movement);
            }
        }
    display();
    }
}

void Game::setup()
{
    setupPlayers();

    _staticMash.addObserver(&_clickObserver);
    _staticMash.setupSprite("../Game/resources/textures/HomeTexture.png");
    _staticMash.setPosition({_window.getSize().x / 2, 150});
    _staticMash.setScale({0.2f, 0.2f});
}

void Game::eventProcessing()
{
    sf::Event event;
    while(_window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
        {
            sf::Vector2f mouse = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
            sf::FloatRect staticMashBounds = _staticMash.getSprite().getGlobalBounds();
            if (staticMashBounds.contains(mouse)) 
            {
                _staticMash.notifyObservers();
                _targetPosition = _staticMash.getPosition();
                _isMoving = true;
            }
        }
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
    _staticMash.draw(_window);
}

void Game::createWindow()
{
    _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _tittle);
}

void Game::setupPlayers()
{
    _player.setupSprite("../Game/resources/textures/playerTexture.png");

    _player.setPosition({0.f, 0.f});
    _player.setScale({0.3f, 0.3f});
    _player.setSpeed(1000.f);
}
