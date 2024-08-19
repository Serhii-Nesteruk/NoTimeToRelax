#include "PlayerController.h"

#include <cmath>
#include <iostream>

void PlayerController::attachPlayer(std::shared_ptr<Player>& player)
{
    _players.push_back(player);
}

void PlayerController::attachWindow(std::shared_ptr<sf::RenderWindow>& window)
{
    if (isWindowAttached())
        throw std::runtime_error("Failed window attaching");
    
    _window = window;
}

void PlayerController::movementControl(float deltaTime)
{
    ensureWindowIsAttached();
    for (auto player: _players)
        if (isMoving())
            movePlayer(player, deltaTime);
}

bool PlayerController::checkingGoalAchievement(std::shared_ptr<Player>& player, const TargetData& target)
{
    sf::FloatRect playerBounds = player->getSprite().getGlobalBounds();
    sf::FloatRect targetBounds = target.getGlobalBounds();

    return playerBounds.intersects(targetBounds);
}

sf::Vector2f PlayerController::calculateMovement(const TargetData& target, Player* player, float deltaTime)
{
     sf::Vector2f direction = target.getPosition() - player->getPosition();
            
    return direction * player->getSpeed() * deltaTime;
}

bool PlayerController::isMoving() const
{
    return _isMoving;
}

void PlayerController::targetPressingHandle(const TargetData& target)
{
    if (isPosibleToChangeTarget())
    {
       _isPosibleToChangeTarget = false; 
       _lastPressedTargetId = target.getId();
       _isMoving = true;
    }
}

void PlayerController::movePlayer(std::shared_ptr<Player>& player, float deltaTime)
{
    TargetData target = findTargetById(_lastPressedTargetId);
    sf::Vector2f direction = calculateDirection(player, target);
    sf::Vector2f movement = calculateMovement(direction, player, deltaTime);

    if (checkingGoalAchievement(player, target))
    {
        player->setPosition(target.getPosition());
        _isMoving = false; 
        _isPosibleToChangeTarget = true;
    }
    else
        player->move(movement);
}

sf::Vector2f PlayerController::calculateDirection(std::shared_ptr<Player>& player, const TargetData &target)
{
    sf::Vector2f direction = target.getPosition() - player->getPosition();
    float length = calculateLength(direction);
    if (length != 0) 
        direction /= length;
    return direction;
}

sf::Vector2f PlayerController::calculateMovement(const sf::Vector2f &direction, std::shared_ptr<Player>& player, float deltaTime)
{
    return direction * player->getSpeed() * deltaTime;
}

float PlayerController::calculateLength(const sf::Vector2f& direction)
{
    return std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
}

bool PlayerController::isPosibleToChangeTarget() const
{
    return _isPosibleToChangeTarget;
}

void PlayerController::mouseInputHandle()
{
    if (!isWindowAttached())
        throw std::runtime_error("Failed to check mouse input, window isn't attached");

    if (Keyboard::checkIfLeftMousePressed())
    {
        sf::Vector2i mouse = Keyboard::getMousePosition(*_window);
        for (auto& target: _targets)
            if (targetPressingCheck(target, static_cast<sf::Vector2f>(mouse))) 
                targetPressingHandle(target);
    } 
}

void PlayerController::setTargetData(const std::vector<StaticMash> &targets)
{
    ensureWindowIsAttached();
    for (auto& target: targets)
    {
        TargetData temp;
        temp.setPosition(target.getPosition())
            .setId(target.getId())
            .setGlobalBound(target.getSprite().getGlobalBounds());

        _targets.push_back(temp);   
    }
}

bool PlayerController::isWindowAttached() const
{
    return  _window != nullptr;
}

void PlayerController::ensureWindowIsAttached()
{
     if (!isWindowAttached())
        throw std::runtime_error("Window isn't attached");
}

bool PlayerController::targetPressingCheck(const TargetData &target, const sf::Vector2f &mouse) const
{
    return target.getGlobalBounds().contains(mouse);
}

TargetData PlayerController::findTargetById(int id) const
{
    for (auto& target: _targets)
        if (target.getId() == id)
            return target;
    return TargetData();
}

TargetData &TargetData::setPosition(const sf::Vector2f &position)
{
    _position = position;
    return *this;  
}

TargetData& TargetData::setId(int id)
{
    _id = id;
    return *this;  
}

TargetData& TargetData::setGlobalBound(const sf::FloatRect &bounds)
{
    _globalBounds = bounds; 
    return *this;  
}

sf::Vector2f TargetData::getPosition() const
{
    return _position;
}

int TargetData::getId() const
{
    return _id;
}

sf::FloatRect TargetData::getGlobalBounds() const
{
    return _globalBounds;
}
