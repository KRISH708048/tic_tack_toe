#include "AIPlayer.hpp"

AIPlayer::AIPlayer(const char &move): Player("Computer",move){}
   
std::pair<int, int> AIPlayer::getBestMove(const Board &board) const{
    const auto& gameBoard = board.getBoard();
    // min-max algo logic
    
}