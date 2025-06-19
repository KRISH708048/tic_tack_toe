#ifndef GAME_HPP
#define GAME_HPP
#include "Board.hpp"
#include "Player.hpp"
#include "AIPlayer.hpp"

class TickTackToe : public Board
{
private:
    Player *player1;
    Player *player2;
    Player *currentPlayer;
    bool isComputer;
    int totalMoves;
    
    void switchPlayer();
    bool isWin(char symbol) const;
    
public:
    TickTackToe(Player* p1, Player* p2, bool AIPlayer);
    ~TickTackToe();
    int playMove(int row, int col);
    bool isGameOver() const;
    Player *getCurrentPlayer() const;
};

#endif