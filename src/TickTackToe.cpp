#include "TickTackToe.hpp"

#include<iostream>

void TickTackToe::switchPlayer()
{
    if (currentPlayer->getMove() == player1->getMove())
    {
        currentPlayer = player2;
    }
    else
    {
        currentPlayer = player1;
    }
}

bool TickTackToe::isWin(char symbol) const
{
    const auto &boardState = getBoard();

    // Check rows
    for (int i = 0; i < size; i++)
    {
        bool win = true;
        for (int j = 0; j < size; j++)
        {
            if (boardState[i][j] != symbol)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;
    }

    // Check columns
    for (int j = 0; j < size; j++)
    {
        bool win = true;
        for (int i = 0; i < size; i++)
        {
            if (boardState[i][j] != symbol)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;
    }

    // Check left->right diagonal
    bool diag1 = true;
    for (int i = 0; i < size; i++)
    {
        if (boardState[i][i] != symbol)
        {
            diag1 = false;
            break;
        }
    }
    if (diag1)
        return true;

    // Check right->left diagonal
    bool diag2 = true;
    for (int i = 0; i < size; i++)
    {
        if (boardState[i][size - 1 - i] != symbol)
        {
            diag2 = false;
            break;
        }
    }
    return diag2;
}

TickTackToe::TickTackToe(Player* p1, Player* p2, bool AIPlayer): player1(p1), player2(p2), currentPlayer(p1), isComputer(AIPlayer), totalMoves(0)
{
    std::cout << "Player 1: " << player1->getName() << " (" << player1->getMove() << ")\n";
    std::cout << "Player 2: " << player2->getName() << " (" << player2->getMove() << ")\n";
}

TickTackToe::~TickTackToe(){
    delete player1;
    delete player2;
}

int TickTackToe::playMove(int row, int col)
{
    if (placeMove(row, col, currentPlayer->getMove()))
    {
        totalMoves++;
        display();
        if (isWin(currentPlayer->getMove()))
        {
            std::cout << currentPlayer->getName() << " wins!\n";
            return 2;
        }
        if (totalMoves == size * size)
        {
            std::cout << "It's a draw!\n";
            return 3;
        }
        switchPlayer();
        return 1;
    }
    return 0;
}

bool TickTackToe::isGameOver() const {
    return totalMoves == 9 || isWin(player1->getMove()) || isWin(player2->getMove());
}


Player* TickTackToe::getCurrentPlayer() const
{
    return currentPlayer;
}