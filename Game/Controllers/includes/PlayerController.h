#pragma once

#include "Player.h"
#include "StaticMash.h" 
#include "Keyboard.h"

#include <vector>
#include <memory>

class TargetData {
    public:
        TargetData() = default;
        ~TargetData() = default;

        TargetData& setPosition(const sf::Vector2f& position);
        TargetData& setId(int id);
        TargetData& setGlobalBound(const sf::FloatRect& bounds);

        [[nodiscard]] sf::Vector2f getPosition() const;
        [[nodiscard]] int getId() const;
        [[nodiscard]] sf::FloatRect getGlobalBounds() const;

    private:
        sf::Vector2f _position{};
        int _id = StaticMash::invalidId;
        sf::FloatRect _globalBounds{};
        
};

class PlayerController {
public:
    PlayerController() = default;
    ~PlayerController() = default;

    void attachPlayer(std::shared_ptr<Player>& player);
    void attachWindow(std::shared_ptr<sf::RenderWindow>& window);
    void movementControl(float deltaTime);
    void mouseInputHandle();
    void setTargetData(const std::vector<StaticMash>& targets); 
    [[nodicard]] bool isWindowAttached() const;

private:
    void ensureWindowIsAttached();
    void targetPressingHandle(const TargetData& target);
    void movePlayer(std::shared_ptr<Player>& player, float deltaTime);

    [[nodiscard]] bool targetPressingCheck(const TargetData& target, const sf::Vector2f& mouse) const;
    [[nodiscard]] TargetData findTargetById(int id) const;
    [[nodiscrad]] bool checkingGoalAchievement(std::shared_ptr<Player>& player, const TargetData& target);
    [[nodiscard]] sf::Vector2f calculateMovement(const TargetData& target, Player* player, float deltaTime);
    [[nodiscard]] bool isMoving() const;
    [[nodiscard]] sf::Vector2f calculateDirection(std::shared_ptr<Player>& player, const TargetData& target);
    [[nodiscard]] sf::Vector2f calculateMovement(const sf::Vector2f& direction, std::shared_ptr<Player>& player, float deltaTime);
    [[nodiscard]] float calculateLength(const sf::Vector2f& direction);
    [[nodiscard]] bool isPosibleToChangeTarget() const;

private:
    std::vector<std::shared_ptr<Player>> _players{};
    std::vector<TargetData> _targets{};
    std::shared_ptr<sf::RenderWindow> _window;

    int _lastPressedTargetId = StaticMash::invalidId; 
    bool _isMoving = false, _isPosibleToChangeTarget = true;
};
