#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP
#include "Player.hpp"
#include "Board.hpp"
#include <utility>

class AIPlayer : public Player
{
public:
    AIPlayer(const char &move);
    std::pair<int, int> getBestMove(Board board) const;
private:
    int minimax(Board& board, bool isMax, char aiSymbol, char playerSymbol) const;
};

#endif