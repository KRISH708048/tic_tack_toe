#include "Board.hpp"
#include <iostream>

Board::Board()
{
    board.resize(size, std::vector<char>(size));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            board[i][j] = '.';
    std::cout << "Ready to Play!\n";
}

void Board::display() const
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool Board::isValidCell(int row, int col) const
{
    return row >= 0 && row < size && col >= 0 && col < size;
}

bool Board::isCellEmpty(int row, int col) const
{
    return isValidCell(row, col) && board[row][col] == '.';
}

bool Board::isBoardFull() const
{
    int f = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == '.')
            {
                f = 1;
                break;
            }
        }
    }

    return !f;
}

bool Board::placeMove(int row, int col, char move) {
    if (!isCellEmpty(row, col)) return false;
    board[row][col] = move;
    return true;
}

const std::vector<std::vector<char>>& Board::getBoard() const {
    return board;
}