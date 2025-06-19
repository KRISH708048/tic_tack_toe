#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
private:
    std::string name;
    char symbol;

public:
    Player(const std::string &n, char s);
    Player(const Player &p);
    virtual ~Player() = default;
    char getMove() const;
    std::string getName() const;
};

#endif