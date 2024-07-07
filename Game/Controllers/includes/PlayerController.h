#pragma once

#include "Player.h"
#include "StaticMash.h" 
#include "Keyboard.h"

#include <vector>

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
    ~PlayerController();

    void attachPlayer(Player* player);
    void attachWindow(sf::RenderWindow* window);
    void detachWindow();
    void movementControl(float deltaTime);
    void mouseInputHandle();
    void setTargetData(const std::vector<StaticMash>& targets); 
    [[nodicard]] bool isWindowAttached() const;

private:
    void ensureWindowIsAttached();
    void targetPressingHandle(const TargetData& target);
    void movePlayer(Player* player, float deltaTime);

    [[nodiscard]] bool targetPressingCheck(const TargetData& target, const sf::Vector2f& mouse) const;
    [[nodiscard]] TargetData findTargetById(int id) const;
    [[nodiscrad]] bool checkingGoalAchievement(Player* player, const TargetData& target);
    [[nodiscard]] sf::Vector2f calculateMovement(const TargetData& target, Player* player, float deltaTime);
    [[nodiscard]] bool isMoving() const;
    [[nodiscard]] sf::Vector2f calculateDirection(Player* player, const TargetData& target);
    [[nodiscard]] sf::Vector2f calculateMovement(const sf::Vector2f& direction, Player* player, float deltaTime);
    [[nodiscard]] float calculateLength(const sf::Vector2f& direction);
    [[nodiscard]] bool isPosibleToChangeTarget() const;

private:
    std::vector<Player*> _players{};
    std::vector<TargetData> _targets{};
    sf::RenderWindow* _window = nullptr;

    int _lastPressedTargetId = StaticMash::invalidId; 
    bool _isMoving = false, _isPosibleToChangeTarget = true;
};
