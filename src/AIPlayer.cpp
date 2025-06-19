#include "AIPlayer.hpp"
#include <climits>

AIPlayer::AIPlayer(const char &move) : Player("Computer", move) {}

std::pair<int, int> AIPlayer::getBestMove(Board board) const {
    int bestScore = INT_MIN;
    std::pair<int, int> bestMove = {-1, -1};
    char playerSymbol = (this->getMove() == 'X') ? 'O' : 'X';
    int boardSize = board.getBoardSize();

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board.isCellEmpty(i, j)) {
                board.placeMove(i, j, this->getMove());
                int score = minimax(board, false, this->getMove(), playerSymbol);
                board.undoMove(i, j);

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }
    return bestMove;
}

int AIPlayer::minimax(Board& board, bool isMax, char aiSymbol, char playerSymbol) const {

    for (int i = 0; i < board.getBoardSize(); ++i) {
        // Check rows
        if (board.getBoard()[i][0] != '.' &&
            board.getBoard()[i][0] == board.getBoard()[i][1] &&
            board.getBoard()[i][1] == board.getBoard()[i][2]) {
            return board.getBoard()[i][0] == aiSymbol ? 10 : -10;
        }
        // Check columns
        if (board.getBoard()[0][i] != '.' &&
            board.getBoard()[0][i] == board.getBoard()[1][i] &&
            board.getBoard()[1][i] == board.getBoard()[2][i]) {
            return board.getBoard()[0][i] == aiSymbol ? 10 : -10;
        }
    }

    // Check diagonals
    if (board.getBoard()[0][0] != '.' &&
        board.getBoard()[0][0] == board.getBoard()[1][1] &&
        board.getBoard()[1][1] == board.getBoard()[2][2]) {
        return board.getBoard()[0][0] == aiSymbol ? 10 : -10;
    }

    if (board.getBoard()[0][2] != '.' &&
        board.getBoard()[0][2] == board.getBoard()[1][1] &&
        board.getBoard()[1][1] == board.getBoard()[2][0]) {
        return board.getBoard()[0][2] == aiSymbol ? 10 : -10;
    }

    // Draw
    if (board.isBoardFull()) return 0;

    int bestScore = isMax ?  INT_MIN : INT_MAX;

    for (int i = 0; i < board.getBoardSize(); ++i) {
        for (int j = 0; j < board.getBoardSize(); ++j) {
            if (board.isCellEmpty(i, j)) {
                board.placeMove(i, j, isMax ? aiSymbol : playerSymbol);
                int score = minimax(board, !isMax, aiSymbol, playerSymbol);
                board.undoMove(i, j);
                bestScore = isMax ? std::max(score, bestScore) : std::min(score, bestScore);
            }
        }
    }
    return bestScore;
}
