#include "TickTackToe.hpp"

#include <iostream>
#include <string>
#include <memory>  

int main()
{
    std::cout << "Welcome to Tic Tack Toe Game\n";

    int ch;
    bool isAIPlayer = false;
    std::string player1name, player2name;
    char mv1 = 'X', mv2 = 'O';
    std::unique_ptr<Player> p1;
    std::unique_ptr<Player> p2;

    while (true)
    {
        std::cout << "choose the mode\n";
        std::cout << "1. 2 player friend game\n";
        std::cout << "2. vs Computer game\n";
        std::cin >> ch;
        std::cin.ignore(); 

        switch (ch)
        {
        case 1:
            std::cout << "\nEnter Player 1 name: ";
            std::getline(std::cin, player1name);
            p1 = std::make_unique<Player>(player1name, mv1);

            std::cout << "\nEnter Player 2 name: ";
            std::getline(std::cin, player2name);
            p2 = std::make_unique<Player>(player2name, mv2);
            break;

        case 2:
            isAIPlayer = true;
            std::cout << "\nEnter Player 1 name: ";
            std::getline(std::cin, player1name);
            p1 = std::make_unique<Player>(player1name, mv1);
            p2 = std::make_unique<AIPlayer>(mv2);
            break;

        default:
            std::cout << "\nInvalid Player choice\n";
            continue;
        }
        break;
    }

    TickTackToe game(p1.get(), p2.get(), isAIPlayer);
    int chance = 1, played_by = 1, x, y;
    game.display();

    while (!game.isGameOver())
    {
        std::cout << "\n" << game.getCurrentPlayer()->getName() << "'s turn ("
                  << game.getCurrentPlayer()->getMove() << "): ";

        while (played_by)
        {
            std::cin >> x >> y;
            chance = game.playMove(x, y);
            if (chance == 0) continue;
            else break;
        }

        while (!played_by)
        {
            if (isAIPlayer)
            {
                auto ai = dynamic_cast<AIPlayer*>(p2.get());
                std::pair<int, int> aiMove = ai->getBestMove(game);
                std::cout << "\nComputer plays: " << aiMove.first << " " << aiMove.second << "\n";
                chance = game.playMove(aiMove.first, aiMove.second);
            }
            else
            {
                std::cin >> x >> y;
                chance = game.playMove(x, y);
            }

            if (chance == 0) continue;
            else break;
        }

        played_by ^= 1;
    }

    std::cout << "\nGame Ends!!\n";

    return 0;
}
