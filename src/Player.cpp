#include "Player.hpp"
#include<string>

Player::Player(const std::string& n, char s) : name(n), symbol(s) {}

Player::Player(const Player &p)
{
    this->name = p.name;
    this->symbol = p.symbol;
}

char Player::getMove() const
{
    return this->symbol;
}
std::string Player::getName() const
{
    return this->name;
}