#include "../includes/Player.h"

#include <iostream>

void Player::incrementFeature(const Features& feature)
{
    switch (feature)
    {
    case Features::HEALTH:
        ++_healthLvl;
        break;
    case Features::EDUCATION:
        ++_educationLvl;
        break;
    case Features::HAPPINEES:
        ++_happinessLvl;
        break;
    case Features::MONEY:
        ++_moneyLvl;
        break;
    case Features::SPEED:
        ++_speed;
        break;
    }
}

std::size_t Player::getHealthLvl() const
{
    return _healthLvl;
}

std::size_t Player::getEducationLvl() const
{
    return _educationLvl;
}

std::size_t Player::getHappinessLvl() const
{
    return _happinessLvl;
}

std::size_t Player::getMoneyLvl() const
{
    return _moneyLvl;
}

float Player::getSpeed() const
{
    return 0.0f;
}

void Player::setHealthLvl(std::size_t healthLvl)
{
    _healthLvl = healthLvl;
}

void Player::setEducationLvl(std::size_t educationLvl)
{
    _educationLvl = educationLvl;
}

void Player::setHappinessLvl(std::size_t happinessLvl)
{
    _happinessLvl = happinessLvl;
}

void Player::setMoneyLvl(std::size_t moneyLvl)
{
    _moneyLvl = moneyLvl;
}
