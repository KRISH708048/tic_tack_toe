#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP
#include "Player.hpp"
#include "Board.hpp"
#include <utility>

class AIPlayer : public Player
{
public:
    AIPlayer(const char &move);
    std::pair<int, int> getBestMove(const Board &board) const;
};

#endif