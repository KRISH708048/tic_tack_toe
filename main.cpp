#include "TickTackToe.hpp"

#include <iostream>
#include <string>

int main()
{
    std::cout << "Welcome to Tic Tack Toe Game\n";

    int ch;
    bool isAIPlayer = false;
    std::string player1name, player2name;
    char mv1 = 'X', mv2 = 'O';
    Player *p1, *p2;

    while (true)
    {
        std::cout << "choose the mode\n";
        std::cout << "1. 2 player friend game\n";
        std::cout << "2. vs Computer game\n";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            std::cout << "\nEnter Player 1 name: ";
            std::cin.ignore(); 
            std::getline(std::cin, player1name);
            p1 = new Player(player1name, mv1);
            std::cout << "\nEnter Player 2 name: ";
            std::cin.ignore(); 
            std::getline(std::cin, player2name);
            p2 = new Player(player2name, mv2);
            break;
        case 2:
            isAIPlayer = true;
            std::cout << "\nEnter Player 1 name: ";
            std::cin >> player1name;
            p1 = new Player(player1name, mv1);
            p2 = new AIPlayer(mv2);
            break;

        default:
            std::cout << "\nInvalid Player choice\n";
        }
        if (ch == 1 || ch == 2)
            break;
    }

    TickTackToe game = TickTackToe(p1, p2, isAIPlayer);
    int chance = 1, played_by = 1, x, y;
    game.display();
    while (!game.isGameOver())
    {
        std::cout << "\n"
                  << game.getCurrentPlayer()->getName() << "'s turn ("
                  << game.getCurrentPlayer()->getMove() << "):\n";
        while (played_by)
        {
            std::cout << "\nPlayer 1 select you move: ";
            std::cin >> x >> y;
            chance = game.playMove(x, y);
            if (chance == 0)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        while (!played_by)
        {
            if (isAIPlayer && !played_by)
            {
                auto ai = dynamic_cast<AIPlayer *>(p2);
                std::pair<int, int> aiMove = ai->getBestMove(game);
                std::cout << "\nComputer plays: " << aiMove.first << " " << aiMove.second << "\n";
                chance = game.playMove(aiMove.first, aiMove.second);
            }
            else
            {
                std::cout << "\nPlayer 2 select your move: ";
                std::cin >> x >> y;
                chance = game.playMove(x, y);
            }
            if (chance == 0)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        played_by ^= 1;
    }

    std::cout << "\nGame Ends!!\n";

    return 0;
}