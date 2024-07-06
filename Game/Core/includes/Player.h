#pragma once

#include "Entity.h"

#include <iostream>

class Player : public Entity
{
public:
    Player() = default;
    ~Player() = default;

    enum class Features
    {
        HEALTH, EDUCATION, HAPPINEES, MONEY, SPEED
    };

    void incrementFeature(const Features& feature);

    [[nodiscard]] std::size_t getHealthLvl() const;
    [[nodiscard]] std::size_t getEducationLvl() const;
    [[nodiscard]] std::size_t getHappinessLvl() const;
    [[nodiscard]] std::size_t getMoneyLvl() const;
    [[nodiscard]] float getSpeed () const;

    void setHealthLvl(std::size_t healthLvl);
    void setEducationLvl(std::size_t educationLvl);
    void setHappinessLvl(std::size_t happinessLvl);
    void setMoneyLvl(std::size_t moneyLvl);
private:
    std::size_t _healthLvl = 0, _educationLvl = 0,
     _happinessLvl = 0, _moneyLvl = 0;
};
