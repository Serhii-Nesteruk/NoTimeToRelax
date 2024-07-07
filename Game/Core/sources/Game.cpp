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
    setupMap();
    setupControllers();
    setupPlayers();
}

void Game::setupMap()
{
    setupBackground();
    setupStaticObjects();
}

void Game::setupBackground() // TODO: move to another class 
{
    if (!_backgroundTexture.loadFromFile("../Game/resources/textures/Background.jpg"))
        throw std::runtime_error("Failed to load background texture");

    _background.setTexture(_backgroundTexture);
}

void Game::eventProcessing()
{
    sf::Event event;
    while(_window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::Resized)
        {
            _window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            sf::Vector2u textureSize = _backgroundTexture.getSize();
            float scaleX = static_cast<float>(_window.getSize().x) / textureSize.x;
            float scaleY = static_cast<float>(_window.getSize().y) / textureSize.y;
            _background.setScale(scaleX, scaleY);
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
    _window.draw(_background);
    for (auto& obj: _staticObjects)
        obj.draw(_window);
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
    playerController.setTargetData(_staticObjects);
}

void Game::setupStaticObjects() // TODO: Create map class and move part of this function to map class
{
    int countOfStaticObjects = 4;
    float indentationX = 50.f,
        indentationY = 50.f;
  
    for (int i = 1; i <= countOfStaticObjects; ++i) 
    {
        StaticMash temp;
        temp.addObserver(&_clickObserver)
            .setTexture("../Game/resources/textures/HomeTexture.png")
            .setScale({0.2f, 0.2f});   
        
        switch (i) { // TODO: I think it's bad idea
            case 1:
                // left upper angle
                temp.setPosition({indentationX, indentationY})
                    .setTexture("../Game/resources/textures/FastFoodTexture.png")
                    .setScale({0.5f, 0.5f});   ;
                break;
            case 2:
                // right upper angle
                temp.setPosition({1050.f + indentationX, indentationY});
                break;
            case 3:
                // left bottom angle
                temp.setPosition({indentationX, 500.f  + indentationY});
                break;
            case 4:
                // right bottom
                temp.setPosition({1050.f  + indentationX, 500.f  + indentationY});
                break;
        }   
        _staticObjects.push_back(temp);
    }
}
