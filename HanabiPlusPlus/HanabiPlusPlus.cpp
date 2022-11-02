// HanabiPlusPlus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../hanabi_learning_environment/hanabi_lib/hanabi_game.h"
#include "../hanabi_learning_environment/hanabi_lib/hanabi_state.h"
#include "../hanabi_learning_environment/hanabi_lib/hanabi_observation.h"
using namespace hanabi_learning_env;

const int CHANCE_PLAYER_ID = -1;

int main()
{
    std::cout << "Hello World!\n";    
    
    std::unordered_map<std::string, std::string> params;
    params.insert({ "players", "3" });
    params.insert({ "random_start_player", "true" });

    HanabiGame game(params);

    HanabiState state(&game);
    while (!state.IsTerminal())
    {
        int currentPlayer = state.CurPlayer();
        if (currentPlayer == CHANCE_PLAYER_ID)
        {
            state.ApplyRandomChance();
            continue;
        }

        HanabiObservation observation(state, currentPlayer);

        auto moves = state.LegalMoves(currentPlayer);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
