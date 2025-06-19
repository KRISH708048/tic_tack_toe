#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

class Board
{
private:
    std::vector<std::vector<char>> board;

public:
    static const int size = 3;
    Board();
    void display() const;
    bool isValidCell(int row, int col) const;
    bool isCellEmpty(int row, int col) const;
    bool isBoardFull() const;
    bool placeMove(int row, int col, char move);
    const std::vector<std::vector<char>> &getBoard() const;
    int getBoardSize() const;
    void undoMove(int row, int col);
};

#endif